#include "../Include/Board.h"
#include "../Include/Utils.h"
#include <memory>

namespace TomasMo {

	Board::Board(const char* path)
	{
		std::unique_ptr<char> boardContent(LoadFile(path));
		if (!boardContent)
		{
			return;
		}
		int dimensionsReadCount = sscanf_s(boardContent.get(), "%d %d", &Width, &Height);
		if (!dimensionsReadCount)
		{
			return;
		}
		Content = new char[Width*Height];
		char* newLine = strchr(boardContent.get(), '\n');
		memcpy(Content, newLine + 1, Width*Height);
	}

	Board::~Board()
	{
		delete[] Content;
	}
}