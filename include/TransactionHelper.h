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

} // namespace TransactionHelper

#endif // TRANSACTION_HELPER_H