#include "../Include/BoggleSolver.h"
#include "../Include/Tree.h"
#include "../Include/Utils.h"
#include "../Include/Board.h"

using namespace TomasMo;

Tree* dictionary = nullptr;

void LoadDictionary(const char* path)
{
	dictionary = new Tree(path);
}

Results FindWords(const char* board, unsigned width, unsigned height)
{
	Board boardToSolve(board, width, height, *dictionary);
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