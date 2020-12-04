/*********************************************************************
** Program name: Project 4 - barbarian.cpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Barbarian character subclass.
				Special ability: None.
*********************************************************************/

#include "barbarian.hpp"

Barbarian::Barbarian()
{
	armor = 0;
	strength = 12;
	maxStrength = 12;
	type = "Barbarian";
}

/*********************************************************************
** Description: Prints the attack dice rolled from the character
*********************************************************************/
void Barbarian::printAttackRoll()
{
	std::cout << "Dice 1 rolled: " << adice1 << std::endl;
	std::cout << "Dice 2 rolled: " << adice2 << std::endl;
}

/*********************************************************************
** Description: Prints the defense dice rolled from the character
*********************************************************************/
void Barbarian::printDefenseRoll()
{
	std::cout << "Dice 1 rolled: " << ddice1 << std::endl;
	std::cout << "Dice 2 rolled: " << ddice2 << std::endl;
}

/*********************************************************************
** Description: Generates the attack damage from dice rolled
*********************************************************************/
void Barbarian::doAttack()
{
	adice1 = rand() % 6 + 1;
	adice2 = rand() % 6 + 1;
	attack = adice1 + adice2;
}

/*********************************************************************
** Description: Generates the character's defense from dice rolled
*********************************************************************/
void Barbarian::setDefense()
{
	ddice1 = rand() % 6 + 1;
	ddice2 = rand() % 6 + 1;
	defense = ddice1 + ddice2;
}