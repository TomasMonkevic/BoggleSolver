#pragma once

#include "Results.h"

//Required functions:
void LoadDictionary(const char* path);
Results FindWords(const char* board, unsigned width, unsigned height);
void FreeWords(Results results);
void FreeDictionary();