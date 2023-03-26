#include <algorithm>
#include "Apriorialgo.h"
#include "TransactionHelper.h"


using namespace TransactionHelper;


std::vector<std::string> Apriorialgo::apriori(std::vector<std::vector<std::string>>&db, float ms) {
	supp_count = (int)(db.size() * ms);
	genOneItem();
	while (freq) {
		std::cout << "Round: " << round << std::endl;
		checkFreq(db);
		freq = false;
	}
	std::vector<std::string> stub;
	return stub;
}

void Apriorialgo::checkFreq(std::vector<std::vector<std::string>>&db) {
	for (auto it = freqSet.rbegin(); it!=freqSet.rend(); it++) {
		std::vector<std::string> sorted = it->first;
		TransactionHelper::lexiSort(sorted);
		for(unsigned int i = 0; i < db.size(); i++) {
			if (std::includes(db[i].begin(), db[i].end(), sorted.begin(), sorted.end())) {
				it->second++;
			}
		}
	}
	for (auto it = freqSet.rbegin(); it!=freqSet.rend(); it++) {
		std::cout << "Set: ";
		for (unsigned int j = 0; j < it->first.size(); j++) {
			std::cout << it->first[j] << " ";
		}
		std::cout << "Count: " << it->second << std::endl;

	}

}


void Apriorialgo::genOneItem() {
	for (int i = 0; i < 100; i++) {
		std::vector<std::string> item;
		std::string name = "i";
	    name += std::to_string(i);
	    item.push_back(name);
	    freqSet.insert(std::make_pair(item, 0));
	}
}
