#include "../googleTestLib/gtest/gtest.h"
#include <Tree.h>

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
	Tree actualResult("Resources/TestDictionary.txt");
	ASSERT_STRCASEEQ(actualResult.ToString().c_str(), "abcdefbcd");
}