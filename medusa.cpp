/*********************************************************************
** Program name: Project 4 - medusa.cpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Medusa character subclass.
				Special ability: Rolling a 12 kills opponent.
*********************************************************************/

#include "medusa.hpp"

Medusa::Medusa()
{
	armor = 3;
	strength = 8;
	maxStrength = 8;
	type = "Medusa";
}

/*********************************************************************
** Description: Prints the attack dice rolled from the character
*********************************************************************/
void Medusa::printAttackRoll()
{
	std::cout << "Dice 1 rolled: " << adice1 << std::endl;
	std::cout << "Dice 2 rolled: " << adice2 << std::endl;
}

/*********************************************************************
** Description: Prints the defense dice rolled from the character
*********************************************************************/
void Medusa::printDefenseRoll()
{
	std::cout << "Dice 1 rolled: " << ddice1 << std::endl;
}


/*********************************************************************
** Description: Generates the attack damage from dice rolled
*********************************************************************/
void Medusa::doAttack()
{
	adice1 = rand() % 6 + 1;
	adice2 = rand() % 6 + 1;
	attack = adice1 + adice2;

	if (attack == 12)
	{
		//std::cout << getName() << " used glare!" << std::endl;
		attack = 100;
	}
}

/*********************************************************************
** Description: Generates the character's defense from dice rolled
*********************************************************************/
void Medusa::setDefense()
{
	ddice1 = rand() % 6 + 1;
	defense = ddice1;
}