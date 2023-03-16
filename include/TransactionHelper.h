#ifndef TRANSACTION_HELPER_H
#define TRANSACTION_HELPER_H

#include <vector>
#include <string>

namespace TransactionHelper {

  /**
   * @brief Sorts the given transaction using the following lexicographic order:
   * i0 < i1 < i2 < .. < i99 .. < in-1 < in < in+1
   * 
   * @param transaction transaction to sort
   */
  void lexiSort(std::vector<std::string>& transaction);

  /**
   * @brief Predicate function for transaction for use in std::sort and 
   * std::is_sorted.
   * Assumes all items follow the format of i#, where the first character is always
   * 'i', following by any number of digits.
   * 
   * @param itemA first item to check
   * @param itemB second item to check
   * @return true if itemA < itemB
   * @return false otherwise
   */
  bool lexiPred(const std::string& itemA, const std::string& itemB);
} // namespace TransactionHelper

#endif // TRANSACTION_HELPER_H