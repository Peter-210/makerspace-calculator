/**
 * @file constants.h
 * @brief This file holds all constants.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

/**
 * @brief Holds all constants for the Makerspace namespace
 */
namespace Constants {
	/**
	 * @brief A constant for the maximum limit of hours allowed in a 3D print.
	 */
	inline constexpr int k_exceedLimitHours {4};

	/**
	 * @brief A constant for the price per hour.
	 */
	inline constexpr double k_hourPrice {2.00};

	/**
	 * @brief A constant for the price per minute rate.
	 */
	inline constexpr double k_minutePrice {0.50};

	/**
	 * @brief A constant for the rate to charge for minutes.
	 */
	inline constexpr double k_minuteRate {15};
}

#endif
