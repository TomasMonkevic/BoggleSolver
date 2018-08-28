#include "../Include/Utils.h"
#include <fstream>
#include <string.h>
#include <cstdarg>

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

	char* Strdup(const char *src) 
	{
		size_t lenght = strlen(src) + 1;
		char* s = (char*)malloc(lenght);
		if (s == nullptr)
		{
			return nullptr;
		}
		return (char*)memcpy(s, src, lenght);
	}

	int Sscanf(const char* buffer, const char* format, ...)
	{
		va_list vaArgs;
		va_start(vaArgs, format);
#ifdef _WIN32
		int result = vsscanf_s(buffer, format, vaArgs);
#else
		int result = vsscanf(buffer, format, vaArgs);
#endif
		va_end(vaArgs);
		return result;
	}
}
