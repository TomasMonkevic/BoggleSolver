#include "../Include/Board.h"
#include "../Include/Utils.h"
#include <memory>
#include <algorithm>

#include <iostream>

namespace TomasMo {

	unsigned char WordScore(const char* word)
	{
		size_t wordLenght = strlen(word);
		unsigned char score = 0;
		if (wordLenght == 3 || wordLenght == 4)
		{
			score = 1;
		}
		else if (wordLenght == 5)
		{
			score = 2;
		}
		else if (wordLenght == 6)
		{
			score = 3;
		}
		else if (wordLenght == 7)
		{
			score = 5;
		}
		else if (wordLenght >= 8)
		{
			score = 11;
		}
		return score;
	}

	void FillResults(Results& results, const std::vector<char*>& words, unsigned score)
	{
		results.Count = words.size();
		results.Words = new char*[words.size()];
		memcpy((void*)results.Words, words.data(), words.size() * sizeof(void*));
		results.Score = score;
	}

	Board::Board(const char* path, Tree& dictionary)
		: _dictionary(dictionary)
	{
		memset(_currentWord, 0, MAX_WORD_SIZE);
		std::unique_ptr<char[]> boardContent(LoadFile(path));
		if (!boardContent)
		{
			return;
		}
		int dimensionsReadCount = Sscanf(boardContent.get(), "%d %d", &_width, &_height);
		if (!dimensionsReadCount)
		{
			return;
		}
		_board = new char[_width*_height];
		char* newLine = strchr(boardContent.get(), '\n');
		memcpy(_board, newLine + 1, _width*_height);
	}

	Board::Board(const char* board, unsigned width, unsigned height, Tree& dictionary)
		: _width(width), _height(height), _board(new char[_width*_height]), _dictionary(dictionary)
	{
		memset(_currentWord, 0, MAX_WORD_SIZE);
		memcpy(_board, board, _width*height);
	}

	Results Board::FindWords() const
	{
		std::vector<char*> words;
		words.reserve(2 * _width * _height); //saves up a few reallocations
		unsigned score = 0;
		std::unique_ptr<bool[]> visited(new bool[_width*_height]);
		memset(visited.get(), 0, _width*_height);
		for (unsigned i = 0; i < _height; i++)
		{
			for (unsigned j = 0; j < _width; j++)
			{
				char letter = _board[i * _width + j];
				Backtrack(i * _width + j, visited.get(), words, score);
				_dictionary.BackToRoot();
				memset(_currentWord, 0, MAX_WORD_SIZE);
				memset(visited.get(), 0, _width*_height);
			}
			//std::cout << std::endl;
		}
		//all found words should be reset, because the dictionary may be used in another find words function (takes about 26 ms)
		_dictionary.ResetFoundWords();
		Results result;
		FillResults(result, words, score);
		return result;
	}

	void Board::Backtrack(unsigned current, bool* visited, std::vector<char*>& words, unsigned& score) const
	{
		//std::cout << _board[current] << " ";
		visited[current] = true;
		_dictionary.Next(_board[current]);
		_currentWord[strlen(_currentWord)] = _board[current];
		if (_board[current] == 'q') //TODO not really nice to have hard coded values
		{
			_currentWord[strlen(_currentWord)] = 'u';
			_dictionary.Next('u');
		}
		if (_dictionary.IsWord() && !_dictionary.IsFound())
		{
			_dictionary.SetWordFoundTrue();
			score += WordScore(_currentWord);
			words.emplace_back(Strdup(_currentWord));
		}
		int currentX = static_cast<int>(current % _height);
		int currentY = static_cast<int>(current / _height);
		for (unsigned i = std::max(0, currentY - 1); i <= std::min(static_cast<int>(_height - 1), currentY + 1); i++)
		{
			for (unsigned j = std::max(0, currentX - 1); j <= std::min(static_cast<int>(_width - 1), currentX + 1); j++)
			{
				if (!visited[i * _width + j] && _dictionary.ChildExists(_board[i * _width + j]))
				{
					Backtrack(i * _width + j, visited, words, score);
					visited[i * _width + j] = false;
					_currentWord[strlen(_currentWord) - 1] = '\0';
					if (_dictionary.IsParent('q'))
					{
						_currentWord[strlen(_currentWord) - 1] = '\0';
						_dictionary.Back();
					}
					_dictionary.Back();
					//std::cout << ". ";
				}
			}
		}
	}

	Board::~Board()
	{
		delete[] _board;
	}
}