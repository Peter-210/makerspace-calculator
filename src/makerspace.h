/**
 * @file makerspace.h
 * @brief This files holds forward declarations for makerspace.cpp
 */

#ifndef MAKERSPACE_H
#define MAKERSPACE_H

#include <iostream>

/**
 * @brief Holds the logic for 3D print calculations and UI
 */
namespace Makerspace
{
	bool inputError(int hours, int minutes);
	bool exceedTime(int hours);
	double calculatePrice(int hours, int minutes);
	void getPrice();
}

#endif
