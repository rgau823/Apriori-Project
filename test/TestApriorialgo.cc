#include "Apriorialgo.h"
#include "TransactionHelper.h"
#include "GenDatabase.h"
#include "gtest/gtest.h"

using namespace TransactionHelper;



class ApriorialgoTest : public testing::Test {
 public:
  GenDatabase* genDb;

  void SetUp() override {
    genDb = new GenDatabase;
  }

  void TearDown() override {
    delete genDb;
  }

};

// Testing that the apriori algorithm can generate the correct frequent itemsets based on designated minimum support
TEST(ApriorialgoTest, testApriori) {
  GenDatabase genDb;
  std::vector<std::vector<std::string>> db;
  try {
    db = genDb.readDBFromFile("D1K", ' ');
  } catch (std::exception& e) {
    std::cout << e.what();
    std::cout << "Error reading database file.";
    exit(1);
  }

  Apriorialgo* a1 = new Apriorialgo();
  a1->apriori(db, 0.01);
  
  // find it->first == "i99" and save it->second to count


  int count = 10;
  for (auto it = freqSets.rbegin(); it != freqSets.rend(); it++) {
    std::cout << it->first[0] << std::endl;
    if (it->first[0] == "i99") {
      count = (int) it->second;
    }
  }


  // cout all it->first and it->second in freqSet
  std::cout << "Freq set size: " << freqSets.size() << std::endl;
  for (auto it = freqSets.rbegin(); it != freqSets.rend(); it++) {
    std::cout << "Set: ";
    for (unsigned int i = 0; i < it->first.size(); i++) {
      std::cout << it->first[i] << " ";
    }
    std::cout << "Count: " << it->second << std::endl;
    std::cout << "spaghetti!";
  }

  EXPECT_EQ(count, 102);

  delete a1;
}