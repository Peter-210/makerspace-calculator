#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <istream>
#include "makerspace.h"

namespace makerspace
{
	/*
	 * @brief Check if input values as of type int.
	 *
	 * @param in Takes the provided istream (std::cin)
	 *
	 * @returns int Returns a positive or zero integer when valid. Else returns -1.
	 */
	int inputInt(std::istream& in)
	{
		int num {};
		in >> num;

		auto clearInput
		{
			[&](std::istream& s) -> void 
			{
				s.clear();
				s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		};

		if (in.fail()) 
		{
			clearInput(in);
			return -1;
		} 
		else if (in.peek() != '\n' && in.peek() != EOF) 
		{
			clearInput(in);
			return -1;
		}

		return num;
	}

	/*
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
	bool inputError(const int& hours, const int& minutes)
	{
		if (hours == 0 && minutes == 0)
		{
			return true;
		}

		if (hours < 0)
		{
			return true;
		}

		if (minutes < 0 || minutes >= 60)
		{
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
	bool exceedTime(const int& hours)
	{
		if (hours > 3)
		{
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
	 * Price is rounded up (ceiling) to the nearest 15 minutes.
	 *
	 * @usage
	 * calculatePrice(2, 40);		// return 5.5
	 * calculatePrice(0, 25);		// return 1.0
	 */
	double calculatePrice(const int& hours, const int& minutes)
	{
		constexpr double HOUR_PRICE { 2.00 };
		constexpr double MINUTE_PRICE { 0.50 };
		constexpr double MINUTE_RATE { 15 };

		double currHourPrice { hours * HOUR_PRICE };
		double currMinPrice { ceil(minutes / MINUTE_RATE) * MINUTE_PRICE };

		return currHourPrice + currMinPrice;
	}

	/*
	 * @brief Print the price of the 3D print in a readable format.
	 *
	 * @return void An output to the terminal for the price.
	 *
	 * @param hours Total hours to print (exclude minutes)
	 * @param minutes Total minutes to print (exclude hours)
	 */
	void printPrice(const int& hours, const int& minutes)
	{
		std::cout << "Time: " << hours << "h " << minutes << "m\n";
		std::cout << "Price: $" << std::fixed << std::setprecision(2) << calculatePrice(hours, minutes) << '\n';
	}

	/*
	 * @brief Run script to get the price of 3D print based on time
	 */
	void getPrice()
	{
		std::cout << "Input Hours:\n";
		int hours { inputInt(std::cin) };

		std::cout << "Input Minutes:\n";
		int minutes { inputInt(std::cin) };

		if (inputError(hours, minutes))
		{
			std::cout << "ERROR - Invalid time value\n";
			std::cout << "--------------------------\n";
			return;
		}

		std::cout << '\n';

		if (exceedTime(hours))
		{
			std::cout << "WARNING - Time exceeds max value\n";
		}

		printPrice(hours, minutes);
		std::cout << "--------------------------\n";
	}
}
