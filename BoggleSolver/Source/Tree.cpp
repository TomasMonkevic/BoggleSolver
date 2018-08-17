#include "../Include/Tree.h"
#include "../Include/Utils.h"
#include <string.h>
#include <memory>

namespace TomasMo {

	Tree::Tree()
		: _current(new Node())
	{

	}

	Tree::Tree(const char* pathToDictionary)
		: Tree()
	{
		std::unique_ptr<char> fileContent(LoadFile(pathToDictionary));
		if (!fileContent)
		{
			return;
		}

		char* word;
		char* nextToken;
		word = strtok_s(fileContent.get(), "\n", &nextToken); //TODO make cross-platform
		while (word)
		{
			AddWord(word);
			word = strtok_s(nullptr, "\n", &nextToken);
		}
	}

	Tree::~Tree()
	{
		BackToRoot();
		delete _current;
	}

	void Tree::Back()
	{

	}

	void Tree::BackToRoot()
	{
		Node* iterator = _current;
		while (iterator->Parent)
		{
			iterator = iterator->Parent;
		}
		_current = iterator;
	}

	void Tree::Next(char letter)
	{
		_current = _current->Children[LetterToIndex(letter)];
	}

	void Tree::AddLetter(char letter)
	{
		if (!ChildExists(letter))
		{
			auto* node = new Node(_current, letter);
			_current->Children[LetterToIndex(letter)] = node;
		}
		Next(letter);
	}

	void Tree::AddWord(const char* word)
	{
		for (unsigned i = 0; i < strlen(word); i++)
		{
			AddLetter(word[i]);
		}
		BackToRoot();
	}

	const char* Tree::GetTraversedWord()
	{
		return nullptr;
	}
}
