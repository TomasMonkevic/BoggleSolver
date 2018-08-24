#include "../Include/BoggleSolver.h"
#include "../Include/Tree.h"
#include "../Include/Utils.h"
#include "../Include/Board.h"
#include <cstdio>

using namespace TomasMo;

Tree* dictionary = nullptr;

void LoadDictionary(const char* path)
{

	printf("Started load!\n");
	dictionary = new Tree(path);
	//printf("%s\n", dictionary.ToString().c_str());
	printf("Finish!\n");
}

Results FindWords(const char* board, unsigned width, unsigned height)
{
	Board boardToSolve(board, *dictionary);
	return boardToSolve.FindWords();
}

void FreeWords(Results results)
{
	for (unsigned i = 0; i < results.Count; i++)
	{
		free((void*)results.Words[i]);
	}
	delete[] results.Words;
}

void FreeDictionary()
{
	delete dictionary;
}