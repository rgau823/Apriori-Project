#ifndef IDEA1ALGO_H
#define IDEA1ALGO_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef std::string item;
typedef std::vector<item> itemset;
typedef std::vector<itemset> database;

class Idea1algo {
 public:
	
	/**
	 * @brief runs the apriori algorithm on the inputted database with the minimum support provided (default 1%)
	 * @param the database with transactions
	 * @param the minimum support
	 * @return a vector with frequen item sets
	 * */
	void idea1(database&db, float ms = 0.01);


	/**
	 * @brief generates the 1-item set to begin apriori
	 * */
	void genOneItem(int size);

	/**
	 * @brief checks if itemsets are frequent;
	 * */
	void checkFreq(database& db);


	/**
	 * @brief prints out the frequent item sets;
	 * */
	void declareFreq();
	void declareTemp();


	/**
	 * @brief generates the candidate sets from frequent itemsets
	 * @param startpoint startpoint
	 * */
	void genCandidate(itemset fi, int startpoint); 


 private:
 	int supp_count;
	
	// Frequent Itemsets
	std::vector<std::pair<itemset, std::pair<int, int>>> freqSet; // pair<int, int> ==> counter, start-point
	
	// Candidate Itemsets
	std::vector<std::pair<itemset, std::pair<int, int>>> tempSet; // pair<int, int> ==> counter, start-point
	
	// Generated K+1 Itemsets
	std::vector<std::pair<itemset, std::pair<int, int>>> k1Set; // pair<int, int> ==> counter, start-point
 	
	// # of scaaning DB
	unsigned int  round  = 1;
	
	// ID of the transaction last scanned
	unsigned int  transactionID = 0;
 	
	bool freq = true;
};

#endif