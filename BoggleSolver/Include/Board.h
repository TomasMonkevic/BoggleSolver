#pragma once

#include "Results.h"
#include "Tree.h"
#include <vector>

namespace TomasMo {

	class Board
	{
	private:
		static const int MAX_WORD_SIZE = 50;

		unsigned _width, _height;
		mutable char _currentWord[MAX_WORD_SIZE];
		char* _board;
		Tree& _dictionary;

	private:
		void Backtrack(unsigned current, bool* visited, std::vector<char*>& words, unsigned& score) const;

	public:
		Board(const char* path, Tree& dictionary);
		Board(const char* board, unsigned width, unsigned height, Tree& dictionary);

		~Board();

		Results FindWords() const;
	};
}