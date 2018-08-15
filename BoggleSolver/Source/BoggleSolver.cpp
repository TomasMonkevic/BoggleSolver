#include "../Include/BoggleSolver.h"
#include "../Include/Tree.h"

void LoadDictionary(const char* path)
{
	using namespace TomasMo;
	Tree dictionary(path);
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