#include "../Include/Tree.h"

namespace TomasMo {

	Tree::Tree()
	{

	}

	Tree::Tree(const char* pathToDictionary)
	{

	}

	Tree::~Tree()
	{
		delete _root;
	}

	void Back();
	void Next(char letter);

	void AddWord(const char* word);
	const char* GetTraversedWord();
}
