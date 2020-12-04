/*********************************************************************
** Program name: Project 4 - barbarian.hpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Barbarian character subclass.
				Special ability: None.
*********************************************************************/

#ifndef BARBARIANCLASS_HPP
#define BARBARIANCLASS_HPP

#include "character.hpp"

class Barbarian : public Character
{

public:
	Barbarian();
	void doAttack();
	void setDefense();
	void printAttackRoll();
	void printDefenseRoll();
};

#endif