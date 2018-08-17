#include "../Include/BoggleSolver.h"
#include "../Include/Tree.h"
#include "../Include/Utils.h"
#include <cstdio>

void LoadDictionary(const char* path)
{
	using namespace TomasMo;

	printf("Started load!");
	Tree dictionary(path);
	printf("Finish!");
}

Results FindWords(const char* board, unsigned width, unsigned height)
{
	Results results;
	results.Count = 0;
	return results;
}

void FreeWords(Results results)
{

}

void FreeDictionary()
{

}