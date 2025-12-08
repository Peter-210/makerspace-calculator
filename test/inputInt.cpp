#include "gtest/gtest.h"
#include <sstream>
#include "makerspace.h"

TEST(InputInt, ValidInputs) {
	{
		std::istringstream input("0\n");
		EXPECT_EQ(makerspace::inputInt(input), 0);
	}
	{
		std::istringstream input("1\n");
		EXPECT_EQ(makerspace::inputInt(input), 1);
	}
	{
		std::istringstream input("10\n");
		EXPECT_EQ(makerspace::inputInt(input), 10);
	}
	{
		std::istringstream input("-1\n");
		EXPECT_EQ(makerspace::inputInt(input), -1);
	}
	{
		std::istringstream input("-10\n");
		EXPECT_EQ(makerspace::inputInt(input), -10);
	}
}

TEST(InputInt, InvalidInputs) {
	{
		std::istringstream input("a\n");
		EXPECT_EQ(makerspace::inputInt(input), -1);
	}
	{
		std::istringstream input("1a\n");
		EXPECT_EQ(makerspace::inputInt(input), -1);
	}
	{
		std::istringstream input("a1\n");
		EXPECT_EQ(makerspace::inputInt(input), -1);
	}
	{
		std::istringstream input("1a1\n");
		EXPECT_EQ(makerspace::inputInt(input), -1);
	}
	{
		std::istringstream input("123a\n");
		EXPECT_EQ(makerspace::inputInt(input), -1);
	}
	{
		std::istringstream input("123a1\n");
		EXPECT_EQ(makerspace::inputInt(input), -1);
	}
	{
		std::istringstream input("\n");
		EXPECT_EQ(makerspace::inputInt(input), -1);
	}
}
