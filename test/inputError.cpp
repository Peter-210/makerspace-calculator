#include "gtest/gtest.h"
#include "makerspace.h"

TEST(InputError, ValidHoursOnly) {
	EXPECT_EQ(makerspace::inputError(1, 0), false);
	EXPECT_EQ(makerspace::inputError(2, 0), false);
}

TEST(InputError, InvalidHoursOnly) {
	EXPECT_EQ(makerspace::inputError(-1, 0), true);
	EXPECT_EQ(makerspace::inputError(-2, 0), true);
}

TEST(InputError, ValidMinutesOnly) {
	EXPECT_EQ(makerspace::inputError(0, 1), false);
	EXPECT_EQ(makerspace::inputError(0, 13), false);
	EXPECT_EQ(makerspace::inputError(0, 45), false);
	EXPECT_EQ(makerspace::inputError(0, 59), false);
}

TEST(InputError, InvalidMinutesOnly) {
	EXPECT_EQ(makerspace::inputError(0, 60), true);
	EXPECT_EQ(makerspace::inputError(0, 61), true);
	EXPECT_EQ(makerspace::inputError(0, -1), true);
	EXPECT_EQ(makerspace::inputError(0, -2), true);
	EXPECT_EQ(makerspace::inputError(0, -59), true);
}

TEST(InputError, ValidHoursAndMinutes) {
	EXPECT_EQ(makerspace::inputError(1, 1), false);
	EXPECT_EQ(makerspace::inputError(1, 15), false);
	EXPECT_EQ(makerspace::inputError(2, 15), false);
	EXPECT_EQ(makerspace::inputError(3, 47), false);
	EXPECT_EQ(makerspace::inputError(3, 59), false);
}

TEST(InputError, InvalidHoursAndMinutes) {
	EXPECT_EQ(makerspace::inputError(0, 0), true);
	EXPECT_EQ(makerspace::inputError(-1, -1), true);
	EXPECT_EQ(makerspace::inputError(-1, 59), true);
	EXPECT_EQ(makerspace::inputError(10, -1), true);
}
