#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <iomanip>

#include "TransactionHelper.h"

std::map<std::vector<std::string>, int> TransactionHelper::freqSets;

void TransactionHelper::lexiSort(std::vector<std::string>& transaction) {
  std::sort(transaction.begin(), transaction.end(), lexiPred);
}

bool TransactionHelper::lexiPred(const std::string& itemA, const std::string& itemB) {
  return (std::stoi(itemA.substr(1)) < std::stoi(itemB.substr(1)));
}

void TransactionHelper::clearFreqSets() {
  freqSets.clear();
}

void TransactionHelper::writeFreqSets(std::string fileName) {
  std::ofstream freqFile;
  freqFile.open(fileName);

  int largestSetSize = 0;
  for (auto it = freqSets.begin(); it != freqSets.end(); ++it) {
    if (it->first.size() > largestSetSize) {
      largestSetSize = it->first.size();
    }
  }
  
  for (auto it = freqSets.begin(); it != freqSets.end(); ++it) {
    std::string outputLine = "{ ";
    for (int i = 0; i < it->first.size(); i++) {
      if (i+1 == it->first.size() || it->first.size() == 1) {
        outputLine += it->first[i] + " }";
      } else {
        outputLine += it->first[i] + ", ";
      }
      freqFile << std::setw(9 + largestSetSize*4) << std::left << outputLine << "| Count: " << it->second << "\n";
    }
  }
  freqFile.close();
}
// For counting:
// TransactionHelper::freqSets[it->first] = it->second