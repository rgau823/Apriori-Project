#include <vector>
#include <string>
#include <random>
#include <algorithm>

#include "GenDatabase.h"
#include "TransactionHelper.h"

using namespace TransactionHelper;

std::random_device ran;
std::mt19937 gen(ran());

GenDatabase::GenDatabase(bool generateDB) {
  genItems();
  if (!generateDB) { return; }
  D1K = genDB(1000);
  D10K = genDB(10000);
  D50K = genDB(50000);
  D100K = genDB(100000);
}

std::vector<std::string> GenDatabase::genTransaction(int num) {
  std::shuffle(items.begin(), items.end(), gen);
  std::vector<std::string> transaction;
  for (int i = 0; i < num; i++) {
    transaction.push_back(items[i]);
  }
  TransactionHelper::lexiSort(transaction);
  return transaction;
}

std::vector<std::string> GenDatabase::genTransaction(int min, int max) {
  std::uniform_int_distribution<int> dist(min, max);
  return genTransaction(dist(gen));
}

std::vector<std::vector<std::string>> GenDatabase::genDB(int num) {
  std::vector<std::vector<std::string>> db;
  for (int i = 0; i < num; i++) {
    db.push_back(genTransaction(5, 15));
  }
  return db;
}

void GenDatabase::genItems(int count) {
  for (int i = 0; i < count; i++) {
    std::string name = "i";
    name += std::to_string(i);
    items.push_back(name);
  }
}

void GenDatabase::writeDBToFile(std::vector<std::vector<std::string>> db, char delim) {
  // TODO (Tyler): Implement
}

std::vector<std::vector<std::string>> GenDatabase::readDBFromFile(std::string file, char delim) {
  // TODO (Tyler): Implement
}