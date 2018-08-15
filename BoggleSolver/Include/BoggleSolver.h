#pragma once

struct Results
{
	const char* const* Words;    // pointers to unique found words, each terminated by a non-alpha char
	unsigned           Count;    // number of words found
	unsigned           Score;    // total score
	void*              UserData; // ignored
};

//Required functions:
void LoadDictionary(const char* path);
Results FindWords(const char* board, unsigned width, unsigned height);
void FreeWords(Results results);
void FreeDictionary();