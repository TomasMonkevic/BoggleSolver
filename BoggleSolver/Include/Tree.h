#pragma once

#include "Node.h"

namespace TomasMo {

	class Tree
	{
	private:
		Node* _current;

	private:
		//might be a good idea to make this function more robust
		inline int LetterToIndex(char letter) 
		{
			return static_cast<unsigned char>(letter) - 0x61;
		}

	public:
		Tree();
		Tree(const char* pathToDictionary);
		~Tree();

		inline bool ChildExists(char letter)
		{
			return _current->Children[LetterToIndex(letter)];
		}

		void Back();
		void BackToRoot();
		void Next(char letter);

		void AddLetter(char letter);
		void AddWord(const char* word);
		const char* GetTraversedWord();
	};
}
