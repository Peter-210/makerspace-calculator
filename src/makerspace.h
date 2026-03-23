/**
 * @file makerspace.h
 * @brief This files holds forward declarations for makerspace.cpp
 */

#ifndef MAKERSPACE_H
#define MAKERSPACE_H

#include "constants.h"
#include <iostream>

/**
 * @brief Holds the logic for 3D print calculations and UI
 */
namespace Makerspace
{
	bool inputError(int hours, int minutes);
	bool exceedTime(int hours, 
			int exceedLimitHours = Constants::k_exceedLimitHours
			);
	double calculatePrice(int hours, int minutes, 
			double hourPrice = Constants::k_hourPrice, 
			double minuteRate = Constants::k_minuteRate, 
			double minutePrice = Constants::k_minutePrice
			);
	void getPrice(
			int exceedLimitHours = Constants::k_exceedLimitHours
			);
}

#endif
