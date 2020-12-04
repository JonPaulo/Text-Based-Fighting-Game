/*********************************************************************
** Program name: Project 4 - harryPotter.hpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Harry Potter character subclass.
				Special Ability = 2 lives.
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"

class HarryPotter : public Character
{
private:
	int lives;
public:
	HarryPotter();
	void doAttack();
	void setDefense();
	void printAttackRoll();
	void printDefenseRoll();
	void afterAttackTrait();
};

#endif