#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Include/BoggleSolver.h"
#include "Include/Timer.h"

char* GenerateRandomBoard(unsigned width, unsigned height)
{
	static char letters[] = { "abcdefghijklmnopqrstuvwxyz" };
	std::srand(std::time(nullptr));
	char* result = new char[width * height];
	for (unsigned i = 0; i < width*height; i++)
	{
		result[i] = letters[std::rand() % 27];
	}
	return result;
}

int main()
{
	unsigned width = 1000, height = 1000;
	char* board = GenerateRandomBoard(width, height);
	TomasMo::Timer timer;
	LoadDictionary("../Resources/Dictionary.txt");
	Results results = FindWords(board, width, height);
	FreeWords(results);
	FreeDictionary();
	long long elapsedMs = timer.ElapsedMs();
	delete[] board;
	std::cout << "Time elapsed: " << elapsedMs << " ms. " << std::endl;
	std::cout << "Found words: " << results.Count << std::endl;
	std::cout << "Score: " << results.Score << std::endl;
	std::cin.get();
	return 0;
}