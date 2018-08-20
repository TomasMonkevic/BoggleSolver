#pragma once

namespace TomasMo {

	//Useful when loading big boards from file
	struct Board
	{
		unsigned Width, Height;
		char* Content;

		Board(const char* path);
		~Board();
	};
}