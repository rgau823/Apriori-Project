#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

#include "GenDatabase.h"
#include "TransactionHelper.h"

using namespace TransactionHelper;

std::random_device ran;
std::mt19937 gen(ran());

GenDatabase::GenDatabase() {
  genItems();
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

void GenDatabase::writeDBToFile(std::string file, std::vector<std::vector<std::string>> db, char delim) {
  std::ofstream dbFile;
  dbFile.open(file);
  for (std::vector<std::string> transaction : db) {
    for (std::string item : transaction) {
      dbFile << item << delim;
    }
    dbFile << "\n";
  }
  dbFile.close();
}

std::vector<std::vector<std::string>> GenDatabase::readDBFromFile(std::string file, char delim) {
  std::ifstream dbFile;
  std::vector<std::vector<std::string>> db;
  std::string readLine;
  dbFile.open(file);

  while (std::getline(dbFile, readLine)) {
    std::stringstream ss(readLine);
    std::vector<std::string> transaction;
    std::string item;

    while (std::getline(ss, item, delim)) {
      transaction.push_back(item);
    }
    db.push_back(transaction);
  }
  dbFile.close();
  return db;
}