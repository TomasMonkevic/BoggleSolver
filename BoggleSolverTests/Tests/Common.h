#pragma once

#ifdef _WIN32
	#define RESOURCE_PATH "../../../../Resources/"
#else
	#define RESOURCE_PATH "Resources/"
#endif

#define RESOURCE_FOLDER(RESOURCE) RESOURCE_PATH ## RESOURCE