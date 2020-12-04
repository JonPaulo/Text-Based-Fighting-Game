/*********************************************************************
** Program name: Project 4 - main.cpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Main function creates game object and calls the menu.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "game.hpp"
#include "character.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"

int main()
{
	// Seed required to generate random numbers
	unsigned seed;
	seed = time(0);
	srand(seed);

	std::cout << "Welcome to the Fantasy Combat Game!\n" << std::endl;

	Game game;
	game.menu();

	return 0;
}