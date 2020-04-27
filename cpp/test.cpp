#include "test.h"

#include <vector>

int main() {

	Test::EXPECT_EQ(1,1,"basic pass");
	Test::EXPECT_EQ(1,0,"basic fail");
	Test::EXPECT_EQ("hello", "hello", "string pass");
	std::string HELLO = "HELLO";
	Test::EXPECT_EQ("HELLO", HELLO, "string using variable pass");
	Test::EXPECT_EQ(1, 1.000, "int and float pass");
	Test::EXPECT_EQ(1.0001, 1, "int and float fail");
	Test::EXPECT_EQ(1, 1.0001, "int and float fail");
	std::vector<int> exp = {1,2};
	Test::EXPECT_VECTOR_EQ(exp, {1,2}, "vector pass");
	Test::EXPECT_VECTOR_EQ(exp, {1,2,3}, "vector size fail");
	Test::EXPECT_VECTOR_EQ(exp, {1,3}, "vector value fail");
	return 0;
}
