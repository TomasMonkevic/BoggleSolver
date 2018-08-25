#include "../googleTestLib/gtest/gtest.h"
#include "Common.h"
#include <Tree.h>
#include <Timer.h>

using namespace TomasMo;

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
	Tree actualResult((std::string(RESOURCE_PATH) + std::string("TestDictionary.txt")).c_str());
	ASSERT_STRCASEEQ(actualResult.ToString().c_str(), "abcdefbcd");
}

TEST(TreeTests, PerformanceTest)
{
	Timer timer;
	Tree actualResult((std::string(RESOURCE_PATH) + std::string("Dictionary.txt")).c_str());
	long long elapsedMs = timer.ElapsedMs();
	std::cout << "Time elapsed: " << elapsedMs << " ms."<< std::endl;
	ASSERT_TRUE(elapsedMs < 100);
}