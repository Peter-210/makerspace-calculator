/**
 * @file makerspace.cpp
 * @brief This file handles the calculations and UI
 * for 3D printing costs.
 */

#include "makerspace.h"
#include "constants.h"
#include "stream_validation.h"

#include <string>
#include <string_view>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <limits>

/**
 * @brief Holds the logic for 3D print calculations and UI
 */
namespace Makerspace
{
	/**
	 * @brief Get an integer value from the user. Comes with input validation.
	 *
	 * @returns int Returns a positive or zero integer when valid.
	 */
	int inputInt(std::string_view message)
	{
		while (true) {
			std::cout << message;
			int num {};
			std::cin >> num;

			if (StreamValid::invalidInput()) {
				std::cout << "Invalid input. Please try again.\n";
				continue;
			}

			return num;
		}
	}

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
	bool inputError(int hours, int minutes)
	{
		constexpr int maxMinutes {60};

		if (hours == 0 && minutes == 0)
		{
			return true;
		}

		if (hours < 0)
		{
			return true;
		}

		if (minutes < 0 || minutes >= maxMinutes)
		{
			return true;
		}

		return false;
	}

	/**
	 * @brief Check if input time (hours only) exceeds max printing time.
	 *
	 * @param hours Total hours to print (exclude minutes).
	 * @param k_exceedLimitHours A constant for the maximum limit of hours allowed in a 3D print.
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
	bool exceedTime(int hours, int k_exceedLimitHours)
	{

		return hours >= k_exceedLimitHours;
	}

	/**
	 * @brief Calculate the price of 3D print based on total time to print.
	 *
	 * @return double The price of the 3D print.
	 *
	 * @param hours Total hours to print (exclude minutes).
	 * @param minutes Total minutes to print (exclude hours).
	 * @param k_hourPrice A constant for the price per hour.
	 * @param k_minuteRate A constant for the rate to charge for minutes.
	 * @param k_minutePrice A constant for the price per minute rate.
	 *
	 * @details
	 * Charged as $2.00 for every hour; $0.50 for every 15 minutes.
	 * Price is rounded up (ceiling) to the nearest 15 minutes.
	 *
	 * @usage
	 * calculatePrice(2, 40);		// return 5.5
	 * calculatePrice(0, 25);		// return 1.0
	 */
	double calculatePrice(int hours, int minutes, double k_hourPrice, double k_minuteRate, double k_minutePrice)
	{
		const double currHourPrice { hours * k_hourPrice };
		const double currMinPrice { ceil(minutes / k_minuteRate) * k_minutePrice };

		return currHourPrice + currMinPrice;
	}

	/**
	 * @brief Print the price of the 3D print in a readable format.
	 *
	 * @return void An output to the terminal for the price.
	 *
	 * @param hours Total hours to print (exclude minutes)
	 * @param minutes Total minutes to print (exclude hours)
	 */
	void printPrice(int hours, int minutes)
	{
		std::cout << "Time: " << hours << "h " << minutes << "m\n";
		std::cout << "Price: $" << std::fixed << std::setprecision(2) << calculatePrice(hours, minutes) << '\n';
	}

	/**
	 * @brief Run script to get the price of 3D print based on time
	 *
	 * @param k_exceedLimitHours A constant for the maximum limit of hours allowed in a 3D print.
	 */
	void getPrice(int k_exceedLimitHours)
	{
		std::string hourMessage {"Input Hours: "};
		const int hours { inputInt(hourMessage) };

		std::string minuteMessage {"Input Minutes: "};
		const int minutes { inputInt(minuteMessage) };

		if (inputError(hours, minutes))
		{
			std::cout << "ERROR - Invalid time value\n";
			std::cout << "--------------------------\n";
			return;
		}

		std::cout << '\n';

		if (exceedTime(hours))
		{
			std::cout << "WARNING - Time exceeds " << k_exceedLimitHours << " hour limit\n";
		}

		printPrice(hours, minutes);
		std::cout << "--------------------------\n";
	}
}
