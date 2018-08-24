#pragma once

#include "Results.h"
#include "Tree.h"
#include <stack>

namespace TomasMo {

	class Board
	{
	private:
		static const int MAX_WORD_SIZE = 50;

		unsigned _width, _height;
		mutable char _currentWord[MAX_WORD_SIZE];
		char* _board;

	private:
		void Backtrack(unsigned current, bool* visited, Tree& dictionary, Results& results) const;

	public:
		Board(const char* path);
		Board(const char* board, unsigned width, unsigned height);

		~Board();

		Results FindWords(Tree& dictionary) const;
	};
}