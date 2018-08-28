#pragma once

namespace TomasMo {

	char* LoadFile(const char* path);
	char* Strtok(char* string, const char* delimeters, char** nextToken);
	char* Strdup(const char *src);
	int Sscanf(const char* buffer, const char* format, ...);
}
