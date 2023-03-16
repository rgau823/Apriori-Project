#include <vector>
#include <string>
#include <iostream>

#include "GenDatabase.h"
#include "gtest/gtest.h"

TEST(TestGenDatabase, genTransactionTest) {
  GenDatabase g(false);
  std::vector<std::string> t1 = {};

  t1 = g.genTransaction(6);
  EXPECT_EQ(t1.size(), 6);

  t1= g.genTransaction(5, 15);
  EXPECT_TRUE(t1.size() >= 5 && t1.size() <= 15);
}

TEST(TestGenDatabase, genDBTest) {
  GenDatabase g(false);
  std::vector<std::vector<std::string>> db = {};
  std::vector<std::string> t1 = {};

  db = g.genDB(1000);
  EXPECT_EQ(db.size(), 1000);
  db = g.genDB(64);
  EXPECT_EQ(db.size(), 64);
  db = g.genDB(100000);
  EXPECT_EQ(db.size(), 100000);

  t1 = db.at(3678);
  EXPECT_TRUE(t1.size() > 0);
  EXPECT_TRUE(t1.at(0).size() > 0);
  EXPECT_TRUE(t1.at(0)[0] == 'i');
}