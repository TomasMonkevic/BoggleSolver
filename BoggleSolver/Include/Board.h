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
		void AddNeighbors(unsigned current, std::stack<unsigned>& neighbors, const bool* visited) const;
		void Backtrack(unsigned current, bool* visited) const;

	public:
		Board(const char* path);
		Board(const char* board, unsigned width, unsigned height);

		~Board();

		Results FindWords(Tree& dictionary) const;
	};
}