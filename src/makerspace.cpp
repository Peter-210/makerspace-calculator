/**
 * @file makerspace.cpp
 * @brief This file handles the calculations and UI
 * for 3D printing costs.
 */

#include "makerspace.h"
#include "constants.h"

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
	 * @brief Check if input values as of type int.
	 *
	 * @param userInput Takes the provided istream (std::cin)
	 *
	 * @returns int Returns a positive or zero integer when valid. Else returns -1.
	 */
	int inputInt(std::istream& userInput)
	{
		int num {};
		userInput >> num;

		auto clearInput
		{
			[&](std::istream& stream) -> void 
			{
				stream.clear();
				stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		};

		if (userInput.fail()) 
		{
			clearInput(userInput);
			return -1;
		} 
		
		if (userInput.peek() != '\n' && userInput.peek() != EOF) 
		{
			clearInput(userInput);
			return -1;
		}

		return num;
	}

	/**
	 * @brief Print the price of the 3D print in a readable format.
	 *
	 * @return void An output to the terminal for the price.
	 *
	 * @param hours Total hours to print (exclude minutes)
	 * @param minutes Total minutes to print (exclude hours)
	 */
	void printPrice(const int hours, const int minutes)
	{
		std::cout << "Time: " << hours << "h " << minutes << "m\n";
		std::cout << "Price: $" << std::fixed << std::setprecision(2) << calculatePrice(hours, minutes) << '\n';
	}

	/**
	 * @brief Run script to get the price of 3D print based on time
	 */
	void getPrice()
	{
		std::cout << "Input Hours:\n";
		const int hours { inputInt(std::cin) };

		std::cout << "Input Minutes:\n";
		const int minutes { inputInt(std::cin) };

		if (inputError(hours, minutes))
		{
			std::cout << "ERROR - Invalid time value\n";
			std::cout << "--------------------------\n";
			return;
		}

		std::cout << '\n';

		if (exceedTime(hours))
		{
			std::cout << "WARNING - Time exceeds " << Constants::EXCEED_LIMIT_HOURS << " hour limit\n";
		}

		printPrice(hours, minutes);
		std::cout << "--------------------------\n";
	}
}
