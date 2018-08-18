#pragma once

namespace TomasMo {

	char* LoadFile(const char* path); //TODO test with c style file reading
	char* Strtok(char* string, const char* delimeters, char** nextToken);
}
