#pragma once

#include "Results.h"
#include "Tree.h"
#include <stack>

namespace TomasMo {

	class Board
	{
	private:
		unsigned _width, _height;
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