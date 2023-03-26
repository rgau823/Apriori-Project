#include "GenDatabase.h"
#include "TransactionHelper.h"
#include "Apriorialgo.h"

using namespace TransactionHelper;


#include <string>
#include <iostream>
#include <vector>

int main() {
	GenDatabase* gen = new GenDatabase(false);
	std::string i = "i";
	int two = 2;
	i = i  + std::to_string(two);
	std::string i2 = "i2";
	if (i == i2) {
		std::cout << "good" << std::endl;
	}
	std::vector<std::vector<std::string>> db;
	db = gen->genDB(100);
	Apriorialgo* apri  = new Apriorialgo();
	apri->apriori(db);
	return 0;
}