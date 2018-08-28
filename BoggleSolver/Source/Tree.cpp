#include "../Include/Tree.h"
#include "../Include/Utils.h"
#include <memory>
#include <stack>

namespace TomasMo {

	Tree::Tree()
		: _current(new Node()), _root(_current)
	{

	}

	Tree::Tree(const char* pathToDictionary)
		: Tree()
	{
		std::unique_ptr<char[]> fileContent(LoadFile(pathToDictionary));
		if (!fileContent)
		{
			return;
		}

		char* word;
		char* nextToken;
		word = Strtok(fileContent.get(), "\n", &nextToken);
		while (word)
		{
			AddWord(word);
			word = Strtok(nullptr, "\n", &nextToken);
		}
	}

	Tree::~Tree()
	{
		BackToRoot();
		delete _current;
	}

	void Tree::Back()
	{
		if (_current->Parent)
		{
			_current = _current->Parent;
		}
	}

	void Tree::BackToRoot()
	{
		_current = _root;
	}

	void Tree::Next(char letter)
	{
		if (ChildExists(letter))
		{
			_current = _current->Children[LetterToIndex(letter)];
		}
	}

	void Tree::AddLetter(char letter)
	{
		if (!ChildExists(letter))
		{
			auto* node = new Node(_current, letter);
			_current->Children[LetterToIndex(letter)] = node;
		}
	}

	void Tree::AddWord(const char* word)
	{
		for (unsigned i = 0; i < strlen(word); i++)
		{
			AddLetter(word[i]);
			Next(word[i]);
		}
		_current->IsWord = true;
		BackToRoot();
	}

	void Tree::ResetFoundWords()
	{
		std::stack<Node*> neighbors;
		neighbors.push(_current);
		while (!neighbors.empty())
		{
			Node* neighbor = neighbors.top();
			neighbor->IsFound = false;
			neighbors.pop();

			for (unsigned i = 0; i < ALPHABET_SIZE; i++)
			{
				if (neighbor->Children[i])
				{
					neighbors.push(neighbor->Children[i]);
				}
			}
		}
	}

	//does a depth first search on the tree and returns all available letters
	std::string Tree::ToString() const
	{
		std::string result;
		std::stack<Node*> neighbors;
		neighbors.push(_current);
		while(!neighbors.empty())
		{
			Node* neighbor = neighbors.top();
			if(neighbor->Parent)
			{
				result += neighbor->Letter;
			}
			neighbors.pop();

			for(int i=ALPHABET_SIZE-1; i>=0; i--)
			{
				if(neighbor->Children[i])
				{
					neighbors.push(neighbor->Children[i]);
				}
			}
		}
		return result;
	}

	bool Tree::operator==(const Tree& rhs) const
	{
		return *_current == *rhs._current;
	}
}
