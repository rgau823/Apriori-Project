#include <vector>
#include <string>
#include <algorithm>

#include "TransactionHelper.h"
#include "GenDatabase.h"
#include "gtest/gtest.h"

using TransactionHelper::lexiSort;
using TransactionHelper::lexiPred;

TEST(TestTransactionHelper, lexiSortTest) {
  GenDatabase g(false);
  std::vector<std::string> t1;
  t1 = g.genTransaction(5, 15);
  lexiSort(t1);
  EXPECT_TRUE(std::is_sorted(t1.begin(), t1.end(), lexiPred));
}