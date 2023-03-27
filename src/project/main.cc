#include "GenDatabase.h"
#include "TransactionHelper.h"
#include "Apriorialgo.h"

using namespace TransactionHelper;


#include <string>
#include <iostream>
#include <vector>

int main() {
	GenDatabase* gen = new GenDatabase(false);
	std::vector<std::vector<std::string>> db;
	db = gen->genDB(100);
	Apriorialgo* apri  = new Apriorialgo();
	apri->apriori(db, 0.02);
	return 0;
}