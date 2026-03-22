#ifndef MAKERSPACE_H
#define MAKERSPACE_H

#include "constants.h"
#include <cmath>
#include <iostream>

namespace Makerspace
{
	int inputInt(std::istream& userInput);
	void printPrice(const int hours, const int minutes);
	void getPrice();

	/**
	 * @brief Check if input values are acceptable as a format of time.
	 *
	 * @param hours Total hours to print (exclude minutes).
	 * @param minutes Total minutes to print (exclude hours).
	 *
	 * @returns boolean If true, the input time is invalid. Else false.
	 *
	 * @usage
	 * inputError(2, 40); 	// return false
	 * inputError(0, 25); 	// return false
	 * inputError(-1, 40); 	// return true
	 * inputError(1, -1); 	// return true
	 * inputError(1, 60); 	// return true
	 * inputError(0, 0); 		// return true
	 */
	constexpr bool inputError(const int hours, const int minutes)
	{
		constexpr int MAX_MINUTES {60};

		if (hours == 0 && minutes == 0)
		{
			return true;
		}

		if (hours < 0)
		{
			return true;
		}

		if (minutes < 0 || minutes >= MAX_MINUTES)
		{
			return true;
		}

		return false;
	}

	/**
	 * @brief Check if input time (hours only) exceeds max printing time.
	 *
	 * @param hours Total hours to print (exclude minutes).
	 *
	 * @returns boolean If true, the input time exceeds max printing time. Else false.
	 *
	 * @usage
	 * exceedTime(1); 	// return false
	 * exceedTime(2); 	// return false
	 * exceedTime(3); 	// return false
	 * exceedTime(4); 	// return true
	 * exceedTime(5); 	// return true
	 */
	constexpr bool exceedTime(const int hours)
	{

		return hours >= Constants::EXCEED_LIMIT_HOURS;
	}

	/**
	 * @brief Calculate the price of 3D print based on total time to print.
	 *
	 * @return double The price of the 3D print.
	 *
	 * @param hours Total hours to print (exclude minutes).
	 * @param minutes Total minutes to print (exclude hours).
	 *
	 * @details
	 * Charged as $2.00 for every hour; $0.50 for every 15 minutes.
	 * Price is rounded up (ceiling) to the nearest 15 minutes.
	 *
	 * @usage
	 * calculatePrice(2, 40);		// return 5.5
	 * calculatePrice(0, 25);		// return 1.0
	 */
	constexpr double calculatePrice(const int hours, const int minutes)
	{
		const double currHourPrice { hours * Constants::HOUR_PRICE };
		const double currMinPrice { ceil(minutes / Constants::MINUTE_RATE) * Constants::MINUTE_PRICE };

		return currHourPrice + currMinPrice;
	}
}

#endif
