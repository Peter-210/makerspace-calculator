#include "gtest/gtest.h"
#include "makerspace.h"

TEST(CalculatePrice, HoursOnly)
{
	EXPECT_EQ(makerspace::calculatePrice(1, 0), 2.0);
	EXPECT_EQ(makerspace::calculatePrice(2, 0), 4.0);
	EXPECT_EQ(makerspace::calculatePrice(3, 0), 6.0);
	EXPECT_EQ(makerspace::calculatePrice(4, 0), 8.0);
	EXPECT_EQ(makerspace::calculatePrice(5, 0), 10.0);
}

TEST(CalculatePrice, MinutesOnly)
{
	EXPECT_EQ(makerspace::calculatePrice(0, 1), 0.5);
	EXPECT_EQ(makerspace::calculatePrice(0, 15), 0.5);
	EXPECT_EQ(makerspace::calculatePrice(0, 22), 1.0);
	EXPECT_EQ(makerspace::calculatePrice(0, 23), 1.0);
	EXPECT_EQ(makerspace::calculatePrice(0, 30), 1.0);
	EXPECT_EQ(makerspace::calculatePrice(0, 37), 1.5);
	EXPECT_EQ(makerspace::calculatePrice(0, 38), 1.5);
	EXPECT_EQ(makerspace::calculatePrice(0, 45), 1.5);
	EXPECT_EQ(makerspace::calculatePrice(0, 52), 2.0);
	EXPECT_EQ(makerspace::calculatePrice(0, 53), 2.0);
	EXPECT_EQ(makerspace::calculatePrice(0, 59), 2.0);
}

TEST(CalculatePrice, OneHourAnyMinutes)
{
	EXPECT_EQ(makerspace::calculatePrice(1, 1), 2.5);
	EXPECT_EQ(makerspace::calculatePrice(1, 7), 2.5);
	EXPECT_EQ(makerspace::calculatePrice(1, 8), 2.5);
	EXPECT_EQ(makerspace::calculatePrice(1, 15), 2.5);
	EXPECT_EQ(makerspace::calculatePrice(1, 22), 3.0);
	EXPECT_EQ(makerspace::calculatePrice(1, 23), 3.0);
	EXPECT_EQ(makerspace::calculatePrice(1, 30), 3.0);
	EXPECT_EQ(makerspace::calculatePrice(1, 37), 3.5);
	EXPECT_EQ(makerspace::calculatePrice(1, 38), 3.5);
	EXPECT_EQ(makerspace::calculatePrice(1, 45), 3.5);
	EXPECT_EQ(makerspace::calculatePrice(1, 52), 4.0);
	EXPECT_EQ(makerspace::calculatePrice(1, 53), 4.0);
	EXPECT_EQ(makerspace::calculatePrice(1, 59), 4.0);
}

TEST(CalculatePrice, MaxHoursAnyMinutes)
{
	EXPECT_EQ(makerspace::calculatePrice(3, 1), 6.5);
	EXPECT_EQ(makerspace::calculatePrice(3, 7), 6.5);
	EXPECT_EQ(makerspace::calculatePrice(3, 8), 6.5);
	EXPECT_EQ(makerspace::calculatePrice(3, 15), 6.5);
	EXPECT_EQ(makerspace::calculatePrice(3, 22), 7.0);
	EXPECT_EQ(makerspace::calculatePrice(3, 23), 7.0);
	EXPECT_EQ(makerspace::calculatePrice(3, 30), 7.0);
	EXPECT_EQ(makerspace::calculatePrice(3, 37), 7.5);
	EXPECT_EQ(makerspace::calculatePrice(3, 38), 7.5);
	EXPECT_EQ(makerspace::calculatePrice(3, 45), 7.5);
	EXPECT_EQ(makerspace::calculatePrice(3, 52), 8.0);
	EXPECT_EQ(makerspace::calculatePrice(3, 53), 8.0);
	EXPECT_EQ(makerspace::calculatePrice(3, 59), 8.0);
}
