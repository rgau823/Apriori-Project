#ifndef TRANSACTION_HELPER_H
#define TRANSACTION_HELPER_H

#include <vector>
#include <string>
#include <map>

namespace TransactionHelper {

  extern std::map<std::vector<std::string>, int> freqSets;

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
  bool itemsetSizePred(const std::pair<std::vector<std::string>, int>& setA, const std::pair<std::vector<std::string>, int>& setB);
  void clearFreqSets();
  void writeFreqSets(std::string fileName);


} // namespace TransactionHelper

#endif // TRANSACTION_HELPER_H