#include <string_view>
#include <limits>
#include <iostream>

/**
 * @brief A set of functions for dealing with input validation.
 *
 * @details
 * This is my personal version of input validation.
 * Code refactored from https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
 */
namespace StreamValid {
	/**
	 * @brief Discards all invalid characters on the right side of input.
	 */
	void rstrip() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/**
	 * @brief Clears the fail status for std::cin and discards all remaining characters in input.
	 */
	void resetStream() {
		std::cin.clear();
		rstrip();
	}

	/**
	 * @brief Check if the input extracted has failed. (eg. EOF, Invalid Type, Overflow, etc.)
	 *
	 * @returns boolean If true, the input extraction has failed.
	 */
	bool failedExtraction() {
		if (std::cin) {return false;}

		if (std::cin.eof()) {std::exit(0);}
		resetStream();

		return true;
	}

	/**
	 * @brief Check and remove trailing characters on the right side of the extracted input.
	 *
	 * @returns boolean If true, the input extraction has trailing characters.
	 */
	bool unextractedInput() {
		bool hasTrailing {!std::cin.eof() && std::cin.peek() != '\n'};

		if (hasTrailing) {
			rstrip();
			return true;
		}

		return false;
	}

	/**
	 * @brief Check if input values are acceptable as a format of time.
	 *
	 * @param errorMessage Prints the error message if the input validation fails.
	 *
	 * @returns boolean If true, the input extraction is invalid. Therefore, the invalid input will be handled.
	 *
	 * @code{.cpp}
	 * int getInteger() {
	 * 	while (true) {
	 * 		std::cout << "Enter a integer: ";
	 * 		int num {};
	 * 		std::cin >> num;
	 *
	 * 		if (StreamValid::invalidInput()) {
	 * 			std::cout << "Invalid input. Please try again.\n";
	 * 			continue;
	 * 		}
	 *
	 * 		return num;
	 * 	}
	 * }
	 * @endcode
	 */
	bool invalidInput() {
		if (failedExtraction()) {return true;}
		if (unextractedInput()) {return true;}

		rstrip();
		return false;
	}
}
