#pragma once

#include <iostream>
#include <string>

namespace readIn {

	short ReadNumberBetweenFromTo(short from, short to, std::string message, std::string fallMessage = "Number is out of Range, Please enter a vaild number >> ") {

		short number = 0;
		std::cout << message;
		std::cin >> number;

		while (number < from || number > to) {

			std::cout << fallMessage;
			std::cin >> number;


		}

		return number;

	}

	std::string ReadText(std::string message) {

		std::string text = "";

		std::cout << message;
		std::getline(std::cin >> std::ws, text);

		return text;

	}

}

