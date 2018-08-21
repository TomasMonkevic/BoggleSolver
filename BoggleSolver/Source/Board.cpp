#include "../Include/Board.h"
#include "../Include/Utils.h"
#include <memory>
#include <algorithm>

#include <iostream>

namespace TomasMo {

	Board::Board(const char* path)
	{
		std::unique_ptr<char[]> boardContent(LoadFile(path));
		if (!boardContent)
		{
			return;
		}
		int dimensionsReadCount = sscanf_s(boardContent.get(), "%d %d", &_width, &_height);
		if (!dimensionsReadCount)
		{
			return;
		}
		_board = new char[_width*_height];
		char* newLine = strchr(boardContent.get(), '\n');
		memcpy(_board, newLine + 1, _width*_height);
	}

	Board::Board(const char* board, unsigned width, unsigned height)
		: _width(width), _height(height), _board(new char[_width*_height])
	{
		memcpy(_board, board, _width*height);
	}

	Results Board::FindWords(Tree& dictionary) const
	{
		Results results;
		results.Words = nullptr;
		results.Count = 0;
		std::unique_ptr<bool[]> visited(new bool[_width*_height]);
		memset(visited.get(), 0, _width*_height);
		for (unsigned i = 0; i < _height; i++)
		{
			for (unsigned j = 0; j < _width; j++)
			{
				char letter = _board[i * _width + j];
				std::cout << letter << " Path: ";
				//DFS
				std::stack<unsigned> neighbors;
				neighbors.push(i * _width + j);
				while (!neighbors.empty())
				{
					unsigned neighbor = neighbors.top();
					neighbors.pop();
					std::cout << _board[neighbor] << " ";
					std::size_t temp = neighbors.size();
					if (!visited[neighbor])
					{
						visited[neighbor] = true;
						AddNeighbors(neighbor, neighbors, visited.get());
					}
				}
				memset(visited.get(), 0, _width*_height);
				std::cout << std::endl;
			}
			//std::cout << std::endl;
		}
		return results;
	}

	void Board::Backtrack(unsigned current, bool* visited) const
	{
		visited[current] = true;
		int currentX = static_cast<int>(current % _height);
		int currentY = static_cast<int>(current / _height);
		for (unsigned i = std::max(0, currentY - 1); i <= std::min(static_cast<int>(_height - 1), currentY + 1); i++)
		{
			for (unsigned j = std::max(0, currentX - 1); j <= std::min(static_cast<int>(_width - 1), currentX + 1); j++)
			{
				if (!visited[i * _width + j])
				{
					//std::cout << _board[i * _width + j] << " ";
				}
			}
		}
	}

	void Board::AddNeighbors(unsigned current, std::stack<unsigned>& neighbors, const bool* visited) const
	{
		int currentX = static_cast<int>(current % _height);
		int currentY = static_cast<int>(current / _height);
		for (unsigned i = std::max(0, currentY - 1); i <= std::min(static_cast<int>(_height-1), currentY + 1); i++)
		{
			for (unsigned j = std::max(0, currentX - 1); j <= std::min(static_cast<int>(_width-1), currentX + 1); j++)
			{
				if (!visited[i * _width + j])
				{
					neighbors.push(i * _width + j);
					//std::cout << _board[i * _width + j] << " ";
				}
			}
		}
		//std::cout << std::endl;
	}

	Board::~Board()
	{
		delete[] _board;
	}
}