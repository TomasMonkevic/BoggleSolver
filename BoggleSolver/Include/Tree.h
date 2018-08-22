#pragma once

#include "Node.h"
#include <string>

namespace TomasMo {

	class Tree
	{
	private:
		Node* _current;
		//TODO A good idea would be to have a root node

	private:
		//might be a good idea to make this function more robust
		inline int LetterToIndex(char letter) const
		{
			return static_cast<unsigned char>(letter) - 0x61;
		}

	public:
		Tree();
		Tree(const char* pathToDictionary);
		~Tree();

		inline bool ChildExists(char letter) const
		{
			return _current->Children[LetterToIndex(letter)];
		}
		inline bool IsWord() const
		{
			if (!_current) 
			{
				return false;
			} 
			return _current->IsWord; 
		}

		void Back();
		void BackToRoot();
		void Next(char letter);

		void AddLetter(char letter);
		void AddWord(const char* word);
		//TODO optimize this function
		std::string GetTraversedWord();

		//Only for testing
		std::string ToString() const;

		//not used but might be useful
		bool operator==(const Tree& rhs) const;
	};
}
