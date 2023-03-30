#include "GenDatabase.h"
#include "TransactionHelper.h"
#include "Apriorialgo.h"
#include "Idea1algo.h"

using namespace TransactionHelper;


#include <string>
#include <iostream>
#include <vector>

int main() {
	GenDatabase* gen = new GenDatabase(false);
	std::vector<std::vector<std::string>> db;
	db = gen->genDB(100);

	// for (auto a : db){
	// 	for (auto b : a)
	// 		std::cout << b << " ";
	// 	std::cout << std::endl;
	// }

	Idea1algo* i1  = new Idea1algo();
	i1->idea1(db, 0.02);
	
	Apriorialgo* a1  = new Apriorialgo();
	a1->apriori(db, 0.02);
	
	return 0;
}