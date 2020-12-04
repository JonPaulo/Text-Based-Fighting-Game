/*********************************************************************
** Program name: Project 4 - vampire.cpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Vampire character subclass.
				Special ability: 50% chance opponent doesn't attack.
*********************************************************************/

#include "vampire.hpp"

Vampire::Vampire()
{
	armor = 1;
	strength = 18;
	maxStrength = 18;
	type = "Vampire";
}

/*********************************************************************
** Description: Prints the attack dice rolled from the character
*********************************************************************/
void Vampire::printAttackRoll()
{
	std::cout << "Dice 1 rolled: " << adice1 << std::endl;
}

/*********************************************************************
** Description: Prints the defense dice rolled from the character
*********************************************************************/
void Vampire::printDefenseRoll()
{
	std::cout << "Dice 1 rolled: " << ddice1 << std::endl;
}

/*********************************************************************
** Description: Generates the attack damage from dice rolled
*********************************************************************/
void Vampire::doAttack()
{
	adice1 = rand() % 12 + 1;
	attack = adice1;
}


/*********************************************************************
** Description: Generates the character's defense from dice rolled
*********************************************************************/
void Vampire::setDefense()
{
	ddice1 = rand() % 6 + 1;
	defense = ddice1;
}

void Vampire::setDefense(int choose)
{
	defense = choose;
}

/*********************************************************************
** Description: Potential ability called before the attack round
				begins
*********************************************************************/
void Vampire::beforeAttackTrait()
{
	int chance = rand() % 2 + 1;
	if (chance == 1)
	{
		setDefense(1000);
		//std::cout << "The opponent was charmed! No damage was taken." << std::endl;
	}
}