/*********************************************************************
** Program name: Project 4 - character.hpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Character Base Class. Contains the template for each
				character such as dice, attack, defense, armor,
				strenth points, and special abilities.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Character
{
protected:

	int attack,
		defense,
		armor,
		strength;
	int adice1;
	int adice2;
	int ddice1;
	int ddice2;
	int ddice3;
	int lives;
	int maxStrength;
	std::string type;
	std::string name;
	Character* next;
	Character* prev;
public:

	Character();
	~Character();

	virtual void doAttack() = 0;
	virtual void setDefense() = 0;
	void setStrength(int); // Just one value
	void setStrength(int, int, int); // Calculate round value
	void setName();
	void setNext(Character*);
	void setPrev(Character*);

	int getAttack();
	int getDefense();
	int getArmor();
	int getStrength();
	int getRoll();
	int getMaxStrength();
	std::string getName();
	std::string getType();
	Character *getNext();
	Character *getPrev();

	virtual void printAttackRoll() = 0;
	virtual void printDefenseRoll() = 0;
	void resetHealth();

	void armorStats();
	void strengthStats();
	virtual void beforeAttackTrait();
	virtual void afterAttackTrait();

};

#endif