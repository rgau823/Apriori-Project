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
		declareFreq();
		genCandidate();
		round++;
		std::cout << std::endl;
	}
	std::vector<std::string> stub;
	return stub;
}


void Apriorialgo::declareFreq() {
	freq = false;
	for (auto it = freqSet.rbegin(); it!=freqSet.rend(); it++) {
		if(it->second >= supp_count) {
			freq = true;
		}
	}

	if (freq) {
		for (auto it = freqSet.rbegin(); it!=freqSet.rend(); it++) {
			if(it->second >= supp_count) {
				TransactionHelper::freqSets[it->first] = it->second;
				std::cout << "Set: ";
				for (unsigned int i = 0; i < it->first.size(); i++) {
					std::cout << it->first[i] << " ";
				}
				std::cout << "Count: " << it->second << std::endl;
			}
		}
	} else {
		std::cout << "No more frequent itemsets found." << std::endl;
	}
}

void Apriorialgo::genCandidate() {
	bool newCandidate = false;
	std::map<std::vector<std::string>, int, Comp> kplusoneset;
	for (auto it = freqSet.rbegin(); it!=freqSet.rend(); it++) {
		if (it->second < supp_count) continue;
		int antiMono = it->first.size() - 1;
		for (auto it1 = freqSet.rbegin(); it1 != freqSet.rend(); it1++) {
			int count = 0;
			if (it1->second < supp_count) continue;
			if (it->first == it1->first) continue;
			for (unsigned int i = 0; i < it->first.size(); i++) {
				if (it->first[i] == it1->first[i]) count++;
			}
			if (count == antiMono) {
				std::vector<std::string> kplusone;
				for (unsigned int i = 0; i < it->first.size(); i++) {
					kplusone.push_back(it->first[i]);
				}
				kplusone.push_back(it1->first.back());
				auto it = freqSet.find(kplusone);
				if (it == freqSet.end()) {
					kplusoneset.insert(std::make_pair(kplusone, 0));
					newCandidate = true;
				}
			}
		}
	}
	freqSet = kplusoneset;
	freq = newCandidate;
}

void Apriorialgo::checkFreq(std::vector<std::vector<std::string>>&db) {
	TransactionHelper::scanCount++;
	for(unsigned int i = 0; i < db.size(); i++) {
		for (auto it = freqSet.rbegin(); it!=freqSet.rend(); it++) {
		std::vector<std::string> sorted = it->first;
			if (std::includes(db[i].begin(), db[i].end(), sorted.begin(), sorted.end())) {
				it->second++;
			}
		}
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
