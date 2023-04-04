#include "GenDatabase.h"
#include "TransactionHelper.h"
#include "Apriorialgo.h"
#include "Idea1algo.h"

using namespace TransactionHelper;

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

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

	Idea1algo* i1  = new Idea1algo();
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	i1->idea1(db, min_supp);
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Idea1 time: " << elapsed_seconds.count() << std::setprecision(6);
	std::cout << " seconds" << std::endl;
	std::string suppString = std::to_string(min_supp*100);
	suppString = suppString.substr(0, suppString.find('.')+3);
	suppString.erase(suppString.find_last_not_of('0') + 1, std::string::npos);
	suppString.erase(suppString.find_last_not_of('.') + 1, std::string::npos);
	std::string freqFilename = filename + "_Idea1_" + suppString + ".freq";
	writeFreqSets(freqFilename);
	
	return 0;
}