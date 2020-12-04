/*********************************************************************
** Program name: Project 4 - vampire.hpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Vampire character subclass.
				Special ability: 50% chance opponent doesn't attack.
*********************************************************************/

#ifndef VAMPIRECLASS_HPP
#define VAMPIRECLASS_HPP

#include "character.hpp"

class Vampire : public Character
{

public:
	Vampire();
	void doAttack();
	void setDefense();
	void setDefense(int);
	void printAttackRoll();
	void printDefenseRoll();
	void beforeAttackTrait();
};

#endif