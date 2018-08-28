#include "../googleTestLib/gtest/gtest.h"
#include "Common.h"
#include <Board.h>
#include <Tree.h>
#include <Timer.h>
#include <BoggleSolver.h>
#include <fstream>

using namespace TomasMo;

std::ostream& operator<<(std::ostream& os, const Results& obj)
{
	os << "Count: " << obj.Count << std::endl;
	os << "Score: " << obj.Score << std::endl;
	for (unsigned i = 0; i < obj.Count; i++)
	{
		os << obj.Words[i] << " ";
	}
	return os;
}

bool operator==(const Results& lhs, const Results& rhs)
{
	if (lhs.Count != rhs.Count) return false;
	if (lhs.Score != rhs.Score) return false;
	for (unsigned i = 0; i < lhs.Count; i++)
	{
		if (strcmp(lhs.Words[i], rhs.Words[i]))
		{
			return false;
		}
	}
	return true;
}

class SolverTests : public ::testing::Test 
{
protected:
	static Tree* s_dictionary;

protected:
	static void SetUpTestCase()
	{
		s_dictionary = new Tree((std::string(RESOURCE_PATH) + std::string("Dictionary.txt")).c_str());
	}

	static void TearDownTestCase()
	{
		delete s_dictionary;
	}
};

Tree* SolverTests::s_dictionary = nullptr;

TEST_F(SolverTests, Board3x3)
{
	Board solver((std::string(RESOURCE_PATH) + std::string("Board3x3.txt")).c_str(), *s_dictionary);
	Timer timer;
	Results result = solver.FindWords();
	long long elapsedMs = timer.ElapsedMs();
	std::ofstream resultFile(std::string(RESOURCE_PATH) + std::string("Board3x3-Results.txt"));
	resultFile << result;
	resultFile.close();
	const char* expectedWords[] = { "daze", "daut", "zed", "zax", "zit", "eau", "eat", "adz", "adze", "ait", "qua", "quad",
		"quai", "uta", "tad", "tax", "taxi", "tae", "tau", "tui", "tuque" };
	Results expectedResults;
	expectedResults.Count = 21;
	expectedResults.Score = 22;
	expectedResults.Words = expectedWords;
	EXPECT_EQ(result, expectedResults);
	FreeWords(result);
	std::cout << "Time elapsed: " << elapsedMs << " ms. " << result.Count << std::endl;
	EXPECT_TRUE(elapsedMs < 10);
}

TEST_F(SolverTests, Board100x100)
{
	Board solver((std::string(RESOURCE_PATH) + std::string("Board100x100.txt")).c_str(), *s_dictionary);
	Timer timer;
	Results result = solver.FindWords();
	long long elapsedMs = timer.ElapsedMs();
	std::ofstream resultFile(std::string(RESOURCE_PATH) + std::string("Board100x100-Results.txt"));
	resultFile << result;
	resultFile.close();
	FreeWords(result);
	//EXPECT_EQ(result.Count, 21);
	std::cout << "Time elapsed: " << elapsedMs << " ms." << result.Count << std::endl;
	EXPECT_TRUE(elapsedMs < 250);
}

TEST_F(SolverTests, Board300x300)
{
	Board solver((std::string(RESOURCE_PATH) + std::string("Board300x300.txt")).c_str(), *s_dictionary);
	Timer timer;
	Results result = solver.FindWords();
	long long elapsedMs = timer.ElapsedMs();
	std::ofstream resultFile(std::string(RESOURCE_PATH) + std::string("Board300x300-Results.txt"));
	resultFile << result;
	resultFile.close();
	FreeWords(result);
	//EXPECT_EQ(result.Count, 21);
	std::cout << "Time elapsed: " << elapsedMs << " ms." << result.Count << std::endl;
	EXPECT_TRUE(elapsedMs < 2500);
}

TEST_F(SolverTests, Board500x500)
{
	Board solver((std::string(RESOURCE_PATH) + std::string("Board500x500.txt")).c_str(), *s_dictionary);
	Timer timer;
	Results result = solver.FindWords();
	long long elapsedMs = timer.ElapsedMs();
	std::ofstream resultFile(std::string(RESOURCE_PATH) + std::string("Board500x500-Results.txt"));
	resultFile << result;
	resultFile.close();
	FreeWords(result);
	//EXPECT_EQ(result.Count, 21);
	std::cout << "Time elapsed: " << elapsedMs << " ms." << result.Count << std::endl;
	EXPECT_TRUE(elapsedMs < 8000);
}

TEST_F(SolverTests, Board1000x1000)
{
	Board solver((std::string(RESOURCE_PATH) + std::string("Board1000x1000.txt")).c_str(), *s_dictionary);
	Timer timer;
	Results result = solver.FindWords();
	long long elapsedMs = timer.ElapsedMs();
	std::ofstream resultFile(std::string(RESOURCE_PATH) + std::string("Board1000x1000-Results.txt"));
	resultFile << result;
	resultFile.close();
	FreeWords(result);
	//EXPECT_EQ(result.Count, 21);
	std::cout << "Time elapsed: " << elapsedMs << " ms." << result.Count << std::endl;
	EXPECT_TRUE(elapsedMs < 55000);
}