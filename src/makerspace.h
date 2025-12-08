#include <istream>

#pragma once

namespace makerspace {
	int inputInt(std::istream& in);
	bool inputError(const int& hours, const int& minutes);
	bool exceedTime(const int& hours);
	double calculatePrice(const int& hours, const int& minutes);
	void printPrice(const int& hours, const int& minutes);
	void getPrice();
}
