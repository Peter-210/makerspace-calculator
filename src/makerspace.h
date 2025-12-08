#ifndef MAKERSPACE_H
#define MAKERSPACE_H

namespace makerspace {
	int inputInt();
	bool inputError(const int& hours, const int& minutes);
	bool exceedTime(const int& hours);
	double calculatePrice(const int& hours, const int& minutes);
	void printPrice(const int& hours, const int& minutes);
	void getPrice();
}

#endif // MAKERSPACE_H
