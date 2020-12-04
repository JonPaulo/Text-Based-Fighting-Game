/*********************************************************************
** Program name: Project 4 - game.hpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Game class. Holds the menu and functions that play
				the rounds and calculate damage.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"

class Game
{

private:

	Character* team1;
	Character* team2;
	Character* loserPile;
	int team1Score;
	int team2Score;

public:

	Game();
	~Game();

	void menu();
	void round(Character*&, Character*&);
	void freeMem(Character*&);
	void damage(Character*&, Character*&);
	void addBack(Character* newChar, Character*& team);
	bool isEmpty(Character*&);
	void chooseCharacter(Character*& team, int& teamSize, std::string);
	void removeFront(Character*& team);
	void moveLoser(Character*& team);
	void printLosers();

};

#endif // !GAME_HPP


