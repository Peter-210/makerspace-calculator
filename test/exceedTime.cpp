#include "gtest/gtest.h"
#include "makerspace.h"

TEST(ExceedTime, HoursOnly)
{
	EXPECT_EQ(makerspace::exceedTime(0), false);
	EXPECT_EQ(makerspace::exceedTime(1), false);
	EXPECT_EQ(makerspace::exceedTime(2), false);
	EXPECT_EQ(makerspace::exceedTime(3), false);
	EXPECT_EQ(makerspace::exceedTime(4), true);
	EXPECT_EQ(makerspace::exceedTime(5), true);
}
