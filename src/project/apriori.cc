#include "GenDatabase.h"
#include "TransactionHelper.h"
#include "Apriorialgo.h"
#include "Idea1algo.h"

using namespace TransactionHelper;

#include <string>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	if (argc < 3 || argc >= 4) {
		std::cout << "Usage: " << argv[0] << " db_filename min_support\n";
		return -1;
	}
	std::string filename = argv[1];
	float min_supp = std::stof(argv[2]);

	GenDatabase* gen = new GenDatabase();
	std::vector<std::vector<std::string>> db;
	try {
		db = gen->readDBFromFile(filename, ' ');
	} catch (std::exception& e) {
		std::cout << e.what();
		return -1;
	}

	Apriorialgo* a1  = new Apriorialgo();
	a1->apriori(db, min_supp);
	std::string suppString = std::to_string(min_supp*100);
	suppString = suppString.substr(0, suppString.find('.')+3);
	suppString.erase(suppString.find_last_not_of('0') + 1, std::string::npos);
	suppString.erase(suppString.find_last_not_of('.') + 1, std::string::npos);
	std::string freqFilename = filename + "_Apriori_" + suppString + ".freq";
	writeFreqSets(freqFilename);
	
	return 0;
}