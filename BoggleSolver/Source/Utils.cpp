#include "../Include/Utils.h"
#include <fstream>

namespace TomasMo {

	char* LoadFile(const char* path)
	{
		std::ifstream fileStream(path);
		if (fileStream)
		{
			fileStream.seekg(0, fileStream.end);
			int length = fileStream.tellg();

			fileStream.seekg(0, fileStream.beg);
			char* buffer = new char[length];
			fileStream.read(buffer, length);

			fileStream.close();
			return buffer;
		}
		return nullptr;
	}
}
