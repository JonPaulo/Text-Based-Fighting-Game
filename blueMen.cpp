/*********************************************************************
** Program name: Project 4 - blueMen.cpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Blue Men character subclass.
				Special ability: Use 3 defense dices. Lose 1 die per
				4 points of damage.
*********************************************************************/

#include "blueMen.hpp"

BlueMen::BlueMen()
{
	armor = 3;
	strength = 12;
	maxStrength = 12;
	type = "Blue Men";
}

/*********************************************************************
** Description: Prints the attack dice rolled from the character
*********************************************************************/
void BlueMen::printAttackRoll()
{
	std::cout << "Dice 1 rolled: " << adice1 << std::endl;
	std::cout << "Dice 2 rolled: " << adice2 << std::endl;
}

/*********************************************************************
** Description: Prints the defense dice rolled from the character
*********************************************************************/
void BlueMen::printDefenseRoll()
{
	std::cout << "Dice 1 rolled: " << ddice1 << std::endl;

	if (strength > 4)
	{
		std::cout << "Dice 2 rolled: " << ddice2 << std::endl;
	}
	if (strength > 8)
	{
		std::cout << "Dice 3 rolled: " << ddice3 << std::endl;
	}
}

/*********************************************************************
** Description: Generates the attack damage from dice rolled
*********************************************************************/
void BlueMen::doAttack()
{
	adice1 = rand() % 10 + 1;
	adice2 = rand() % 10 + 1;
	attack = adice1 + adice2;
}


/*********************************************************************
** Description: Generates the character's defense from dice rolled
*********************************************************************/
void BlueMen::setDefense()
{
	if (strength > 8)
	{
		ddice1 = rand() % 6 + 1;
		ddice2 = rand() % 6 + 1;
		ddice3 = rand() % 6 + 1;
		defense = ddice1 + ddice2 + ddice3;
	}
	else if (strength > 4)
	{
		ddice1 = rand() % 6 + 1;
		ddice2 = rand() % 6 + 1;
		defense = ddice1 + ddice2;
	}
	else
	{
		ddice1 = rand() % 6 + 1;
		defense = ddice1;
	}
}

/*********************************************************************
** Description: Generates the character's defense from dice rolled
*********************************************************************/
void BlueMen::setDefense(int choose)
{
	defense = choose;
}