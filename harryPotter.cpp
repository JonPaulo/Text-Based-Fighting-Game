/*********************************************************************
** Program name: Project 4 - harryPotter.cpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Harry Potter character subclass.
				Special Ability = 2 lives.
*********************************************************************/

#include "harryPotter.hpp"

HarryPotter::HarryPotter()
{
	lives = 2;
	armor = 0;
	strength = 10;
	maxStrength = 10;
	type = "Harry Potter";
}

/*********************************************************************
** Description: Prints the attack dice rolled from the character
*********************************************************************/
void HarryPotter::printAttackRoll()
{
	std::cout << "Dice 1 rolled: " << adice1 << std::endl;
	std::cout << "Dice 2 rolled: " << adice2 << std::endl;
}

/*********************************************************************
** Description: Prints the defense dice rolled from the character
*********************************************************************/
void HarryPotter::printDefenseRoll()
{
	std::cout << "Dice 1 rolled: " << ddice1 << std::endl;
	std::cout << "Dice 2 rolled: " << ddice2 << std::endl;
}

/*********************************************************************
** Description: Generates the attack damage from dice rolled
*********************************************************************/
void HarryPotter::doAttack()
{
	adice1 = rand() % 6 + 1;
	adice2 = rand() % 6 + 1;
	attack = adice1 + adice2;

}

/*********************************************************************
** Description: Generates the character's defense from dice rolled
*********************************************************************/
void HarryPotter::setDefense()
{
	ddice1 = rand() % 6 + 1;
	ddice2 = rand() % 6 + 1;
	defense = ddice1 + ddice2;
}

/*********************************************************************
** Description: Potential ability called after the attack round
				ends
*********************************************************************/
void HarryPotter::afterAttackTrait()
{
	if (lives > 1 && strength <= 0)
	{
		strength = 20;
		lives--;
		//std::cout << getName() << " used their Hogwarts ability and has been revived!" << std::endl;
	}
}