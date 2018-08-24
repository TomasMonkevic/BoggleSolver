#include <iostream>
#include "Include/BoggleSolver.h"

int main()
{
	LoadDictionary("../Resources/Dictionary.txt");
	Results results = FindWords("../Resources/Board300x300.txt", 3, 3);
	//std::cout << "Count: " << results.Count << std::endl;
	//std::cout << "Score: " << results.Score << std::endl;
	//for (unsigned i = 0; i < results.Count; i++)
	//{
	//	std::cout << results.Words[i] << " ";
	//}
	FreeWords(results);
	FreeDictionary();
	std::cin.get();
	return 0;
}