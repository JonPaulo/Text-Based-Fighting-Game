/*********************************************************************
** Program name: Project 4 - medusa.hpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Medusa character subclass.
				Special ability: Rolling a 12 kills opponent.
*********************************************************************/

#ifndef MEDUSACLASS_HPP
#define MEDUSACLASS_HPP

#include "character.hpp"

class Medusa : public Character
{

public:
	Medusa();
	void doAttack();
	void setDefense();
	void printAttackRoll();
	void printDefenseRoll();
};

#endif