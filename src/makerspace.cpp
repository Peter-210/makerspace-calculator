#include <iostream>
#include <cmath>
#include <iomanip>

#include "makerspace.h"

namespace makerspace {
	/*
	 * @brief Check if input values for time are acceptable.
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
	bool inputError(const int& hours, const int& minutes) {
		if (hours == 0 && minutes == 0) {
			return true;
		}

		if (hours < 0) {
			return true;
		}

		if (minutes < 0 || minutes >= 60) {
			return true;
		}

		return false;
	}

	/*
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
	bool exceedTime(const int& hours) {
		if (hours > 3) {
			return true;
		}

		return false;
	}

	/*
	 * @brief Calculate the price of 3D print based on total time to print.
	 *
	 * @return double The price of the 3D print.
	 *
	 * @param hours Total hours to print (exclude minutes).
	 * @param minutes Total minutes to print (exclude hours).
	 *
	 * @details
	 * Charged as $2.00 for every hour; $0.50 for every 15 minutes.
	 * If time is closest to 15 minutes with an hour of 0, returned price is $0.50.
	 *
	 * @usage
	 * calculatePrice(2, 40);		// return 5.5
	 * calculatePrice(0, 25);		// return 0.5
	 */
	double calculatePrice(const int& hours, const int& minutes) {
		constexpr double HOUR_PRICE = 2.00;
		constexpr double MINUTE_PRICE = 0.50;

		constexpr int MINUTE_RATE = 15;
		const int MINUTE_HALF_RATE = floor(MINUTE_RATE / 2);

		double currMinPrice = 0;
		double sum = 0;

		sum += hours * HOUR_PRICE;

		if (hours == 0 && minutes < MINUTE_RATE + MINUTE_HALF_RATE) {
			return sum + MINUTE_PRICE;
		}

		if (minutes % MINUTE_RATE <= MINUTE_HALF_RATE) {
			currMinPrice = floor(minutes / MINUTE_RATE) * MINUTE_PRICE;
		} else {
			currMinPrice = (floor(minutes / MINUTE_RATE) + 1) * MINUTE_PRICE;
		}

		return sum + currMinPrice;

	}

	/*
	 * @brief Print the price of the 3D print in a readable format.
	 *
	 * @return void An output to the terminal for the price.
	 *
	 * @param hours Total hours to print (exclude minutes)
	 * @param minutes Total minutes to print (exclude hours)
	 */
	void printPrice(const int& hours, const int& minutes) {
		if (inputError(hours, minutes)) {
			std::cout << "ERROR - Invalid time value\n";
			std::cout << "Time: " << hours << "h " << minutes << "m\n";
			return;
		}

		if (exceedTime(hours)) {
			std::cout << "WARNING - Time exceeds max value\n";
		}

		std::cout << "Time: " << hours << "h " << minutes << "m\n";
		std::cout << "Price: $" << std::fixed << std::setprecision(2) << calculatePrice(hours, minutes) << '\n';
	}
}
