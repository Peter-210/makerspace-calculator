#include <iostream>
#include <cmath>

/*
 * @brief Check if input values are valid
 *
 * @param hours = Total hours to print (exclude minutes)
 * @param minutes = Total minutes to print (exclude hours)
 */
bool errorCheck(const int& hours, const int& minutes) {
	if (hours < 0) {
		return false;
	} else {
		if (minutes >= 0 && minutes < 60) {
			return true;
		}
	}

	if (minutes > 0 && minutes < 60) {
		return true;
	}

	return false;
}

/*
 * @brief Calculate the price of 3D print based on total time to print
 *
 * @return double The price of the 3D print
 *
 * @param hours = Total hours to print (exclude minutes)
 * @param minutes = Total minutes to print (exclude hours)
 *
 * @info Charged as $2.00 for every hour; $0.50 for every 15 minutes
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


void printPrice(const int& hours, const int& minutes) {
	if (!errorCheck(hours, minutes)) {
		std::cout << "ERROR - Invalid time value\n";
		std::cout << "Inputted Hours: " << hours << '\n';
		std::cout << "Inputted Minutes: " << minutes << '\n'; 
	}

	std::cout << "Price: $" << calculatePrice(hours, minutes) << '\n';
}

int main() {
	int myHours = 0;
	int myMinutes = 0;

	printPrice(myHours, myMinutes);
  return 0;
}
