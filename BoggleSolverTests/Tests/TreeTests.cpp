#include "../googleTestLib/gtest/gtest.h"
#include <Tree.h>
#include <Timer.h>

using namespace TomasMo;

#ifdef _WIN32
	#define RESOURCE_PATH "../../../../Resources/"
#else
	#define RESOURCE_PATH "Resources/"
#endif

#define RESOURCE_FOLDER(RESOURCE) RESOURCE_PATH ## RESOURCE

TEST(TreeTests, AddLetter)
{
	Tree actualResult;
	actualResult.AddLetter('a');
	ASSERT_STRCASEEQ(actualResult.ToString().c_str(), "a");
}

TEST(TreeTests, AddWord)
{
	Tree actualResult;
	actualResult.AddWord("abcd");
	ASSERT_STRCASEEQ(actualResult.ToString().c_str(), "abcd");
}

TEST(TreeTests, ConstructFromFile)
{
	Tree actualResult(RESOURCE_FOLDER("TestDictionary.txt"));
	ASSERT_STRCASEEQ(actualResult.ToString().c_str(), "abcdefbcd");
}

TEST(TreeTests, PerformanceTest)
{
	Timer timer;
	Tree actualResult(RESOURCE_FOLDER("Dictionary.txt"));
	long long elapsedMs = timer.ElapsedMs();
	std::cout << "Time elapsed: " << elapsedMs << " ms."<< std::endl;
	ASSERT_TRUE(elapsedMs < 100);
}