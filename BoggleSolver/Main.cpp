#include <iostream>
#include "Include/BoggleSolver.h"

int main()
{
	LoadDictionary("../Resources/Dictionary.txt");
	Results results = FindWords("dzxeaiqut", 3, 3);
	FreeWords(results);
	FreeDictionary();
	std::cin.get();
	return 0;
}