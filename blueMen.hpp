/*********************************************************************
** Program name: Project 4 - blueMen.hpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Blue Men character subclass.
				Special ability: Use 3 defense dices. Lose 1 die per
				4 points of damage.
*********************************************************************/

#ifndef BLUEMENCLASS_HPP
#define BLUEMENCLASS_HPP

#include "character.hpp"

class BlueMen : public Character
{

public:
	BlueMen();
	void doAttack();
	void setDefense();
	void setDefense(int);
	void printAttackRoll();
	void printDefenseRoll();
};

#endif