/**
 * @file makerspace.h
 * @brief This files holds forward declarations for makerspace.cpp
 */

#ifndef MAKERSPACE_H
#define MAKERSPACE_H

#include "makerspace-constexpr.h"
#include <iostream>

/**
 * @brief Holds the logic for 3D print calculations and UI
 */
namespace Makerspace
{
	int inputInt(std::istream& userInput);
	void printPrice(int hours, int minutes);
	void getPrice();
}

#endif
