#include "gtest/gtest.h"
#include "makerspace.h"

TEST(ExceedTime, HoursOnly) {
	ASSERT_EQ(makerspace::exceedTime(0), false);
	ASSERT_EQ(makerspace::exceedTime(1), false);
	ASSERT_EQ(makerspace::exceedTime(2), false);
	ASSERT_EQ(makerspace::exceedTime(3), false);
	ASSERT_EQ(makerspace::exceedTime(4), true);
	ASSERT_EQ(makerspace::exceedTime(5), true);
}
