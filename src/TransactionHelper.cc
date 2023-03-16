#include <vector>
#include <string>
#include <algorithm>

#include "TransactionHelper.h"

void TransactionHelper::lexiSort(std::vector<std::string>& transaction) {
  std::sort(transaction.begin(), transaction.end(), lexiPred);
}

bool TransactionHelper::lexiPred(const std::string& itemA, const std::string& itemB) {
  return (std::stoi(itemA.substr(1)) < std::stoi(itemB.substr(1)));
}