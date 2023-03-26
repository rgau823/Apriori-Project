#ifndef APRIORIALGO_H
#define APRIORIALGO_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Comp {
	bool operator()(const std::vector<std::string>& lhs, const std::vector<std::string>& rhs) const {
		for(unsigned int i = 0; i < lhs.size(); i++) {
			int lhsnumb;
			int rhsnumb;
			lhsnumb = stoi(lhs[i].substr(1, lhs[i].length()-1));
			rhsnumb = stoi(lhs[i].substr(1, rhs[i].length()-1));
			if (lhsnumb != rhsnumb) {
				return lhsnumb > rhsnumb;
			}

		}
		return true;

	}
};


class Apriorialgo {
 public:
	
	/**
	 * @brief runs the apriori algorithm on the inputted database with the minimum support provided (default 1%)
	 * @param the database with transactions
	 * @param the minimum support
	 * @return a vector with frequen item sets
	 * */
	std::vector<std::string> apriori(std::vector<std::vector<std::string>>&db, float ms = 0.01);


	/**
	 * @brief generates the 1-item set to begin apriori
	 * */
	void genOneItem();

	/**
	 * 
	 * */
	void checkFreq(std::vector<std::vector<std::string>>& db);


 private:
 	int supp_count;
 	std::map<std::vector<std::string>, int, Comp> freqSet;
 	int  round  = 1;
 	bool freq = true;
};

#endif