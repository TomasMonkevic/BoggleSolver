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
	FreeWords(result);
	EXPECT_EQ(result.Count, 21);
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