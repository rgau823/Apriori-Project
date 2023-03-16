#ifndef GENDATABASE_H
#define GENDATABASE_H

#include <vector>
#include <string>

class GenDatabase {
 public:
  
  // Transaction databases
  std::vector<std::vector<std::string>> D1K, D10K, D50K, D100K;

  /**
   * @brief Construct the database generator.
   * If generateDB is true, generates four databases, D1K, D10K, D50K, and D100K,
   * filling them with their respective number of transactions.
   * @param generateDB Should DBs be generated?
   */
  GenDatabase(bool generateDB = true);

  /**
   * @brief Generates a transaction of num random items.
   * 
   * @param num number of items in the transaction.
   * @return vector containing names of items.
   */
  std::vector<std::string> genTransaction(int num);

  /**
   * @brief Generates a transaction of random items ranging between min and max.
   * 
   * @param min min number of items in a transaction.
   * @param max max number of items in a transaction.
   * @return vector containing names of items.
   */
  std::vector<std::string> genTransaction(int min, int max);

  /**
   * @brief Creates a transaction database with num transactions.
   * 
   * @param num number of transactions to generate.
   * @return vector of transactions.
   */
  std::vector<std::vector<std::string>> genDB(int num);

  /**
   * @brief Writes the given DB to file using the given delimiting character.
   * 
   * @param db database to write to file.
   * @param delim delimiter to use when writing.
   */
  void writeDBToFile(std::vector<std::vector<std::string>> db, char delim = ' ');

  /**
   * @brief Reads the given file, creating a database of transactions from it.
   * 
   * @param file name of file to read.
   * @param delim delimiter to use when reading.
   * @return vector of transactions.
   */
  std::vector<std::vector<std::string>> readDBFromFile(std::string file, char delim = ' ');

 private:
  std::vector<std::string> items;
  /**
   * @brief Generate vector of items from 0 to count with the following format:
   * i0, i1, i2 ... i98, i99 .. in
   * 
   * @param count number of items to generate. Default: 100
   */
  void genItems(int count = 100);
};

#endif // GENDATABASE_H