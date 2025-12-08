#ifndef MAKERSPACE_H
#define MAKERSPACE_H

namespace makerspace {
	bool inputError(const int& hours, const int& minutes);
	bool exceedTime(const int& hours);
	double calculatePrice(const int& hours, const int& minutes);
	void printPrice(const int& hours, const int& minutes);
}

#endif // MAKERSPACE_H
