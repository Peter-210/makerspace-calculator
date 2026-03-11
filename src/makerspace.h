#ifndef MAKERSPACE_H
#define MAKERSPACE_H

#include <iostream>

namespace Makerspace
{
	int inputInt(std::istream& userInput);
	bool inputError(const int& hours, const int& minutes);
	bool exceedTime(const int& hours);
	double calculatePrice(const int& hours, const int& minutes);
	void printPrice(const int& hours, const int& minutes);
	void getPrice();
}

#endif
