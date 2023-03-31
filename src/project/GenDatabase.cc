#include "GenDatabase.h"
#include "TransactionHelper.h"
#include "Apriorialgo.h"
#include "Idea1algo.h"

using namespace TransactionHelper;


#include <string>
#include <iostream>
#include <vector>

int main() {
	GenDatabase* gen = new GenDatabase();
  gen->writeDBToFile("D1K", gen->genDB(1000), ' ');
  gen->writeDBToFile("D10K", gen->genDB(10000), ' ');
  gen->writeDBToFile("D50K", gen->genDB(50000), ' ');
  gen->writeDBToFile("D100K", gen->genDB(100000), ' ');
	
	return 0;
}