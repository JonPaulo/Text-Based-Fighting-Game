/*********************************************************************
** Program name: Project 4 - intNumChoice.hpp
** Author: Jon Paulo Bautista
** Date: 05/12/19
** Description: Simple function allows user to answer a simple question
**				via integer inputs and blocks invalid inputs
*********************************************************************/
#include <limits>
#include <iostream>
#include <string>
#include "intNumChoice.hpp"

// Answer stored in variable // Input cannot be under or over given parameters //
void intNumChoice(std::string question, int& answer, int min, int max)
{
	bool valid;
	char character;
	std::string input;
	int countNegatives = 0;

	do
	{
		countNegatives = 0;
		std::cout << question.c_str() << std::endl;
		std::cin >> (input);

		valid = true;

		for (int i = 0; (i < input.length()) && (valid == true); i++)
		{
			character = tolower((input)[i]);
			if (character == 45 || character > 47 && character < 58)
			{
				valid = true;
			}
			else
			{
				valid = false;
				std::cout << "Please enter a valid integer." << std::endl;
			}

			if (character == 45)
			{
				countNegatives++;
			}

		}

		// Check for negative numbers
		if (countNegatives > 1)
		{
			valid = false;
			std::cout << "Having more than one \"-\" is invalid." << std::endl;
		}
		else if (countNegatives == 1) // "-" only allowed in beginning
		{
			if (input.length() < 2) // There can't only be "-"
			{
				valid = false;
				std::cout << "- is not a number." << std::endl;
			}
			else if (tolower(input[0]) != 45)
			{
				valid = false;
				std::cout << "Negative numbers must be typed correctly." << std::endl;
			}
		}

		std::cout << "--------------------------------------------------------------------------------" << std::endl;

		if (valid == true)
		{
			answer = std::stoi(input);
		}

	} while ((valid == false) || (answer < min) || (answer > max));
}