#include "../Include/Utils.h"
#include <fstream>
#include <string.h>

namespace TomasMo {

	char* LoadFile(const char* path)
	{
		std::ifstream fileStream(path);
		if (fileStream)
		{
			fileStream.seekg(0, fileStream.end);
			std::streamoff length = fileStream.tellg();

			fileStream.seekg(0, fileStream.beg);
			char* buffer = new char[length];
			memset(buffer, 0, length);
			fileStream.read(buffer, length);

			fileStream.close();
			return buffer;
		}
		return nullptr;
	}

	char* Strtok(char* string, const char* delimeters, char** nextToken)
	{
		#ifdef _WIN32
			return strtok_s(string, delimeters, nextToken);
		#else
			return strtok_r(string, delimeters, nextToken);
		#endif
	}
}
