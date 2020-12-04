/*********************************************************************
** Program name: Project 4 - character.cpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Character Base Class. Contains the template for each
				character such as dice, attack, defense, armor,
				strenth points, and special abilities.
*********************************************************************/

#include "character.hpp"

Character::Character()
{
	type = "empty";
	attack = 0;
	maxStrength = 0;
	defense = 0;
	lives = 1;
}

Character::~Character()
{
	
}

int Character::getMaxStrength()
{
	return maxStrength;
}

/*********************************************************************
** Description: Recovers the fighter's strength points after a win.
*********************************************************************/
void Character::resetHealth()
{
	if (strength < (maxStrength * .25))
	{
		strength = (maxStrength * .25);
	}
	else if (strength < (maxStrength * .5))
	{
		strength = (maxStrength * .5);
	}
	else if (strength < (maxStrength * .75))
	{
		strength = (maxStrength * .75);
	}
	else
	{
		strength = maxStrength;
	}
}
/*********************************************************************
** Description: Returns the type of character it is
*********************************************************************/
std::string Character::getType()
{
	return type;
}

int Character::getRoll()
{
	return ddice1;
}

/*********************************************************************
** Description: Print armor stats
*********************************************************************/
void Character::armorStats()
{
	std::cout << "Armor Stat: " << armor << std::endl;
}

/*********************************************************************
** Description: Print strength stats
*********************************************************************/
void Character::strengthStats()
{
	std::cout << "Strength Stat: " << strength << std::endl;
}

void Character::setStrength(int newStrength)
{
	strength = newStrength;
}

void Character::setStrength(int attackRoll, int defendRoll, int defendArmor)
{
	int damage = attackRoll - defendRoll - defendArmor;
	if (damage < 0)
	{
		damage = 0;
	}
	else
	{
		strength -= damage;
	}
}

int Character::getAttack()
{
	return attack;
}

int Character::getDefense()
{
	return defense;
}

int Character::getArmor()
{
	return armor;
}

int Character::getStrength()
{
	return strength;
}

/*********************************************************************
** Description: Potential ability called before the attack round
				begins
*********************************************************************/
void Character::beforeAttackTrait()
{

}

/*********************************************************************
** Description: Potential ability called after the attack round
				ends
*********************************************************************/
void Character::afterAttackTrait()
{

}

void Character::setName()
{
	std::string fighterName;
	std::cout << "Please name your fighter: ";
	std::cin.ignore();
	std::getline(std::cin, fighterName);
	this->name = fighterName;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

std::string Character::getName()
{
	return name;
}