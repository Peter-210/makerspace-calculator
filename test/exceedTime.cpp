#include "makerspace.h"

#include "gtest/gtest.h"

TEST(ExceedTime, HoursOnly)
{
	EXPECT_EQ(Makerspace::exceedTime(0), false);
	EXPECT_EQ(Makerspace::exceedTime(1), false);
	EXPECT_EQ(Makerspace::exceedTime(2), false);
	EXPECT_EQ(Makerspace::exceedTime(3), false);
	EXPECT_EQ(Makerspace::exceedTime(4), true);
	EXPECT_EQ(Makerspace::exceedTime(5), true);
}
