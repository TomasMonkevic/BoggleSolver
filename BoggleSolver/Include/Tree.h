#pragma once

#include "Node.h"
#include <string>

namespace TomasMo {

	class Tree
	{
	private:
		Node* _current;
		Node* const _root;

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

		inline bool IsFound() const { return _current->IsFound; }
		inline void SetWordFoundTrue() { _current->IsFound = true; }

		inline bool IsParent(char letter) 
		{
			if (_current && _current->Parent)
			{
				return _current->Parent->Letter == letter;  
			}
			return false;
		}

		void Back();
		void BackToRoot();
		void Next(char letter);

		void AddLetter(char letter);
		void AddWord(const char* word);
		void ResetFoundWords();

		//Only for testing
		std::string ToString() const;

		//not used but might be useful
		bool operator==(const Tree& rhs) const;
	};
}
