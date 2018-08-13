#include "../googleTestLib/gtest/gtest.h"
#include <FuncToTest.h>

TEST(SampleTest, First)
{
	EXPECT_EQ(Add(2, 2), 4);
}