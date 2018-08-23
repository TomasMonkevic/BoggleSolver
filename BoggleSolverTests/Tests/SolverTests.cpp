#include "../googleTestLib/gtest/gtest.h"
#include "Common.h"
#include <Board.h>
#include <Tree.h>
#include <Timer.h>

using namespace TomasMo;

class SolverTests : public ::testing::Test 
{
protected:
	static Tree* s_dictionary;

protected:
	static void SetUpTestCase()
	{
		s_dictionary = new Tree(RESOURCE_FOLDER("Dictionary.txt"));
	}

	static void TearDownTestCase()
	{
		delete s_dictionary;
	}
};

Tree* SolverTests::s_dictionary = nullptr;

TEST_F(SolverTests, Board3x3)
{
	Board solver(RESOURCE_FOLDER("Board3x3.txt"));
	Timer timer;
	Results result = solver.FindWords(*s_dictionary);
	long long elapsedMs = timer.ElapsedMs();
	EXPECT_EQ(result.Count, 21);
	std::cout << "Time elapsed: " << elapsedMs << " ms." << std::endl;
	EXPECT_TRUE(elapsedMs < 10);
}

TEST_F(SolverTests, Board100x100)
{
	Board solver(RESOURCE_FOLDER("Board100x100.txt"));
	Timer timer;
	Results result = solver.FindWords(*s_dictionary);
	long long elapsedMs = timer.ElapsedMs();
	//EXPECT_EQ(result.Count, 21);
	std::cout << "Time elapsed: " << elapsedMs << " ms." << std::endl;
	EXPECT_TRUE(elapsedMs < 200);
}