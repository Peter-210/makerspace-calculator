#include "gtest/gtest.h"
#include "makerspace.h"

TEST(InputError, ValidHoursOnly) {
	ASSERT_EQ(makerspace::inputError(1, 0), false);
	ASSERT_EQ(makerspace::inputError(2, 0), false);
}

TEST(InputError, InvalidHoursOnly) {
	ASSERT_EQ(makerspace::inputError(-1, 0), true);
	ASSERT_EQ(makerspace::inputError(-2, 0), true);
}

TEST(InputError, ValidMinutesOnly) {
	ASSERT_EQ(makerspace::inputError(0, 1), false);
	ASSERT_EQ(makerspace::inputError(0, 13), false);
	ASSERT_EQ(makerspace::inputError(0, 45), false);
	ASSERT_EQ(makerspace::inputError(0, 59), false);
}

TEST(InputError, InvalidMinutesOnly) {
	ASSERT_EQ(makerspace::inputError(0, 60), true);
	ASSERT_EQ(makerspace::inputError(0, 61), true);
	ASSERT_EQ(makerspace::inputError(0, -1), true);
	ASSERT_EQ(makerspace::inputError(0, -2), true);
	ASSERT_EQ(makerspace::inputError(0, -59), true);
}

TEST(InputError, ValidHoursAndMinutes) {
	ASSERT_EQ(makerspace::inputError(1, 1), false);
	ASSERT_EQ(makerspace::inputError(1, 15), false);
	ASSERT_EQ(makerspace::inputError(2, 15), false);
	ASSERT_EQ(makerspace::inputError(3, 47), false);
	ASSERT_EQ(makerspace::inputError(3, 59), false);
}

TEST(InputError, InvalidHoursAndMinutes) {
	ASSERT_EQ(makerspace::inputError(0, 0), true);
	ASSERT_EQ(makerspace::inputError(-1, -1), true);
	ASSERT_EQ(makerspace::inputError(-1, 59), true);
	ASSERT_EQ(makerspace::inputError(10, -1), true);
}
