#include <algorithm>
#include "Idea1algo.h"
#include "TransactionHelper.h"


using namespace TransactionHelper;


void Idea1algo::idea1(database &db, float ms) {
	supp_count = (int)(db.size() * ms);
	
	genOneItem(db.size());
    
	while (!tempSet.empty()) {
		std::cout << "Round: " << round << std::endl;
		checkFreq(db);
		
		// declareFreq();
		// declareTemp();
		
		round++;
		std::cout << std::endl;
	}
	
	std::cout << "The last TransactionID: " << transactionID << std::endl;
	declareFreq();
}

// Idea1
void Idea1algo::checkFreq(database &db) {
	for(unsigned int i = 0; i < db.size(); i++) {
		for (auto it = tempSet.begin(); it!=tempSet.end();) {
			if (std::includes(db[i].begin(), db[i].end(), it->first.begin(), it->first.end())) {
				it->second.first++;
			}
			
			if(it->second.first >= supp_count) {
				freqSet.push_back({it->first, {0, i}});
				genCandidate(it->first, i);
				it = tempSet.erase(it);
			} else if(it->second.second == i) {
				it = tempSet.erase(it);
			} else ++it;
		}
		
		for(auto a : k1Set)
			tempSet.push_back(a);
		
		// std::cout << i << " ___________________K1SET__________________" << std::endl;
		// for(auto a : k1Set){
		// for(auto b : a.first)
		// 	std::cout << b << " ";
		// std::cout << std::endl;
		// }
		
		k1Set.clear();
		
		if(tempSet.empty()){
			transactionID = i;
			return;
		}
	}
			// std::cout << "___________________TEMPSET__________________" << std::endl;
			// for(auto a : tempSet){
			// for(auto b : a.first)
			// 	std::cout << b << " ";
			// std::cout << std::endl;
			// }
}

// print Frequent Itemsets
void Idea1algo::declareFreq() {
	freq = true;
	
	std::cout << "\n\n===== Frequent Itemsets =====\n\n";

	for (auto it = freqSet.rbegin(); it!=freqSet.rend(); it++) {
		std::cout << "Set: ";
		for (unsigned int i = 0; i < it->first.size(); i++) {
			std::cout << it->first[i] << " ";
		}
		std::cout << "Size: " << it->first.size() << std::endl;
	}

	std::cout << "\n\n===== Total Number of Frequent Itemsets ===== " << freqSet.size() << "\n\n";
}

// print Candidate Itemsets
void Idea1algo::declareTemp() {
	std::cout << "\n\n===== Temp Itemsets =====\n\n";

	if (true) {
		for (auto it = tempSet.rbegin(); it!=tempSet.rend(); it++) {
			std::cout << "Set: ";
			for (unsigned int i = 0; i < it->first.size(); i++) {
				std::cout << it->first[i] << " ";
			}
			std::cout << "Count: " << it->second.first << std::endl;
		}
	} else {
		std::cout << "No more frequent itemsets found." << std::endl;
	}
	std::cout << "\n\n===== Total Number of Candidate Itemsets =====" << tempSet.size() << "\n\n";
}

// Generating Candidate Itemsets
void Idea1algo::genCandidate(itemset fi, int startpoint) {
	for (auto it = freqSet.begin(); it != freqSet.end(); it++) {
		
		// if fi is in freqSet
		if (std::includes(it->first.begin(), it->first.end(), fi.begin(), fi.end()))
			return;

		if(it->first.size() == fi.size()) {
			int antiMono = it->first.size() - 1;
			int count = 0;
			
			for (unsigned int i = 0; i < antiMono; i++) {
				if (it->first[i] == fi[i]) count++;
			}
			
			if (count == antiMono) {
				itemset kplusone;
				for (unsigned int i = 0; i < it->first.size(); i++) {
					kplusone.push_back(it->first[i]);
				}
				if(kplusone.back() == fi.back())
					continue;

				kplusone.push_back(fi.back());
				TransactionHelper::lexiSort(kplusone);
				k1Set.push_back({kplusone, {0, startpoint}});
			}
		}
	}	
}

// For the initial setup...
void Idea1algo::genOneItem(int size) {
	for (int i = 0; i < 100; i++) {
		itemset item;
		std::string name = "i";
	    name += std::to_string(i);
	    item.push_back(name);
	    tempSet.push_back({item, {0, size-1}});
	}
}
