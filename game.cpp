/*********************************************************************
** Program name: Project 4 - game.cpp
** Author: Jon Paulo Bautista
** Date: 05/25/19
** Description: Game class. Holds the menu and functions that play
				the rounds and calculate damage.
*********************************************************************/

#include "intNumChoice.hpp"
#include "game.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"

#include <string>

Game::Game()
{
	team1 = NULL;
	team2 = NULL;
	loserPile = NULL;
	team1Score = 0;
	team2Score = 0;
}

Game::~Game()
{
	freeMem(team1); // Free Memory
	freeMem(team2); // Free Memory
	freeMem(loserPile); // Free Memory
}

/*********************************************************************
** Description: Menu allows user to choose their characters.
*********************************************************************/
void Game::menu()
{
	int keepPlaying = 1;
	int numFighters1 = 0;
	int numFighters2 = 0;
	int fightCount = 0;
	int choice;

	std::string fiveCharacters = "Please pick a character:\n" + 
		std::string("1. Vampire\n") +
		std::string("2. Barbarian\n") +
		std::string("3. Blue Men\n") +
		std::string("4. Medusa\n") +
		std::string("5. Harry Potter\n");

	intNumChoice("1. Play\n2. Exit", keepPlaying, 1, 2);

	while (keepPlaying == 1)
	{
		fightCount = 0;
		team1Score = 0;
		team2Score = 0;


		intNumChoice("Please enter the number of fighters for team #1.", numFighters1, 1, 20);

		chooseCharacter(team1, numFighters1, "Team A");

		intNumChoice("Please enter the number of fighters for team #2.", numFighters2, 1, 20);

		chooseCharacter(team2, numFighters2, "Team B");

		while (team1 != NULL && team2 != NULL)
		{
			fightCount++;
			std::cout << "\n================================================================================" << std::endl;
			std::cout << "FIGHT #" << fightCount << "\n" << std::endl;

			round(team1, team2);
		}
		std::cout << "\n================================================================================" << std::endl;
		std::cout << "There were " << fightCount << " fights total.\n\n";

		std::cout << "Team A's score: " << team1Score << std::endl;
		std::cout << "Team B's score: " << team2Score << std::endl;
		if (team1Score > team2Score)
		{
			std::cout << "Team A has won the game!" << std::endl;
		}
		else if (team2Score > team1Score)
		{
			std::cout << "Team B has won the game!" << std::endl;
		}
		else
		{
			std::cout << "It is a tie! Game Over!" << std::endl;
		}

		intNumChoice("\nWould you like to see the losers?\n1. Yes\n2. No", choice, 1, 2);
		if (choice == 1)
		{
			printLosers();
		}

		// Free Memory
		freeMem(team1);
		freeMem(team2);
		freeMem(loserPile);

		intNumChoice("\n1. Play Again\n2. Exit", keepPlaying, 1, 2);
	}

}

/*********************************************************************
** Description: Plays out 1 round of the game. Both characters
				attack and defend per round.
*********************************************************************/
void Game::round(Character*& attacker, Character*& defender)
{
	std::cout << "Team A: " << attacker->getName() << " (" << attacker->getType() << ") vs ";
	std::cout << "Team B: " << defender->getName() << " (" << defender->getType() << ")\n" << std::endl;
	for (int round = 1; attacker->getStrength() > 0 && defender->getStrength() > 0; round++)
	{
		damage(attacker, defender);
		damage(defender, attacker);
	}

	// Team 2 wins the battle
	if (attacker->getStrength() < 1)
	{
		std::cout << attacker->getName() << " (" << attacker->getType() << ")" << " has lost the fight!" << std::endl;
		std::cout << defender->getName() << " (" << defender->getType() << ")" << " wins!" << std::endl;
		// Health Recovery
		if (defender->getStrength() < defender->getMaxStrength())
		{
			defender->resetHealth();
			std::cout << defender->getName() << " (" << defender->getType() << ")" << "'s strength points have been restored to ";
			std::cout << defender->getStrength() << std::endl;
		}
		else
		{
			std::cout << defender->getName() << " (" << defender->getType() << ")" << " did not need recovery.\n";
			std::cout << defender->getName() << " (" << defender->getType() << ")" << "'s strength points: ";
			std::cout << defender->getStrength() << std::endl;
		}

		moveLoser(attacker);	// Move loser to loser pile

		team2 = team2->getNext();
		team2Score += 1;

	}
	// Team 1 wins the battle
	else
	{
		std::cout << defender->getName() << " (" << defender->getType() << ")" << " has lost the fight!" << std::endl;
		std::cout << attacker->getName() << " (" << attacker->getType() << ")" << " wins!" << std::endl;
		// Health Recovery
		if (attacker->getStrength() < attacker->getMaxStrength())
		{
			attacker->resetHealth();
			std::cout << attacker->getName() << " (" << attacker->getType() << ")" << "'s strength points have been restored to ";
			std::cout << attacker->getStrength() << std::endl;
		}
		else
		{
			std::cout << attacker->getName() << " (" << attacker->getType() << ")" << " did not need recovery.\n";
			std::cout << attacker->getName() << " (" << attacker->getType() << ")" << "'s strength points: ";
			std::cout << attacker->getStrength() << std::endl;
		}

		moveLoser(defender);	// Move loser to loser pile

		team1 = team1->getNext();
		team1Score += 1;
	}
}

/*********************************************************************
** Description: Calculates damage from the attack to the defender.
*********************************************************************/
void Game::damage(Character*& attacker, Character*& defender)
{

	attacker->doAttack();
	defender->setDefense();

	// ABILITIES USED BEFORE ATTACKS
	defender->beforeAttackTrait(); // Vampire, Harry Potter

	// DAMAGE FUNCTION
	int damage = attacker->getAttack() - defender->getDefense() - defender->getArmor();
	if (damage > 0)
	{
		defender->setStrength(attacker->getAttack(), defender->getDefense(), defender->getArmor());
	}
	else
	{
		damage = 0;
	}

	// ABILITIES USED AFTER ATTACKS
	defender->afterAttackTrait(); // Vampire, Harry Potter

}

/*********************************************************************
** Description: Frees the memory from the program.
*********************************************************************/
void Game::freeMem(Character*& team)
{
	// Remove all characters from the list
	while (isEmpty(team) == false)
	{
		removeFront(team);
	}
}

/*********************************************************************
** Description: Adds a number to the end of the list
*********************************************************************/
void Game::addBack(Character* newChar, Character*& team)
{

	// If empty, create a head node
	if (team == NULL)
	{
		team = newChar;
		newChar->setNext(team);
		newChar->setPrev(team);
	}
	// Only 1 node
	else if (team->getPrev() == NULL || team->getPrev() == team)
	{
		newChar->setNext(team);
		newChar->setPrev(team);
		team->setNext(newChar);
		team->setPrev(newChar);
	}
	// 2+ nodes
	else
	{
		// Middle
		newChar->setNext(team);
		newChar->setPrev(team->getPrev());
		// Tail's Next
		team->getPrev()->setNext(newChar);
		// Head's Prev
		team->setPrev(newChar);
	}
}

/*********************************************************************
** Description: Menu that allows the user to choose a character
*********************************************************************/
void Game::chooseCharacter(Character*& team, int& teamSize, std::string teamName)
{
	int choice;
	int numFighters1;
	int numFighters2;

	std::string fiveCharacters = "Please pick a character:\n" +
		std::string("1. Vampire\n") +
		std::string("2. Barbarian\n") +
		std::string("3. Blue Men\n") +
		std::string("4. Medusa\n") +
		std::string("5. Harry Potter\n");

	for (int i = 0; i < teamSize; i++)
	{
		std::cout << teamName << " fighter count: (" << i << "/" << teamSize << ")" << std::endl;
		intNumChoice(fiveCharacters, choice, 1, 5);

		switch (choice)
		{
		case 1:
		{
			std::cout << "The Vampire has been picked!\n" << std::endl;
			Character* v = new Vampire();
			v->setName();
			addBack(v, team);
			break;
		}
		case 2:
		{
			std::cout << "The Barbarian has been picked!\n" << std::endl;
			Character* b = new Barbarian();
			b->setName();
			addBack(b, team);
			break;
		}
		case 3:
		{
			std::cout << "The Blue Men have been picked!\n" << std::endl;
			Character* bm = new BlueMen();
			bm->setName();
			addBack(bm, team);
			break;
		}
		case 4:
		{
			std::cout << "Medusa has been picked!\n" << std::endl;
			Character* m = new Medusa();
			m->setName();
			addBack(m, team);
			break;
		}
		case 5:
		{
			std::cout << "Harry Potter has been picked!\n" << std::endl;
			Character* hp = new HarryPotter();
			hp->setName();
			addBack(hp, team);
			break;
		}
		}
	}
}

/*********************************************************************
** Description: Checks if the Queue is empty
*********************************************************************/
bool Game::isEmpty(Character*& team)
{
	if (team == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*********************************************************************
** Description: Removes a character from the beginning of the list
*********************************************************************/
void Game::removeFront(Character*& team)
{
	if (isEmpty(team) == false)
	{
		Character* nodePtr = team;

		// If only 1 node exists
		if (team->getPrev() == NULL || team == team->getPrev())
		{
			team = NULL;
		}
		// If there is more than one node
		else
		{
			team = team->getNext();
			team->setPrev(team->getPrev()->getPrev());
			team->getPrev()->setNext(team);
		}

		delete nodePtr;
	}
}

/*********************************************************************
** Description: Moves the loser to the loser pile.
*********************************************************************/
void Game::moveLoser(Character*& team)
{
	Character* loser = team;
	Character* temp = loserPile;

	// Remove loser from the team
	if (isEmpty(team) == false)
	{
		// If only 1 node exists
		if (team->getPrev() == NULL || team == team->getPrev())
		{
			team = NULL;
		}
		// If there is more than one node
		else
		{
			// Connect prev to next
			team->getPrev()->setNext(team->getNext());
			// Connect next to prev
			team->getNext()->setPrev(team->getPrev());

			team = team->getNext();
		}
	}

	// Add the loser to the loserPile
	// Loser pile is empty
	if (loserPile == NULL)
	{
		loserPile = loser;

		loser->setPrev(loser);
		loser->setNext(loser);
	}
	// Loser pile has 1 node
	else if (loserPile->getNext() == loserPile)
	{
		loserPile->setNext(loser);
		loserPile->setPrev(loser);
		loser->setNext(loserPile);
		loser->setPrev(loserPile);
	}
	// Loser pile has 2+ nodes
	else
	{
		// Make temp the last node on the list
		while (temp->getNext() != NULL && temp->getNext() != loserPile && temp->getNext() != temp)
		{
			temp = temp->getNext();
		}

		temp->setNext(loser);
		loserPile->setPrev(loser);
		loser->setPrev(temp);
		loser->setNext(loserPile);

	}

}

/*********************************************************************
** Description: Prints the list of losers to the console.
*********************************************************************/
void Game::printLosers()
{
	Character* temp = loserPile;

	if (loserPile != NULL)
	{
		bool lastOne = false;
		std::cout << "\nLOSER PILE:\n" << std::endl;
		while (lastOne == false)
		{
			std::cout << temp->getName() << " (" << temp->getType() << ")" << std::endl;

			if (temp->getNext() != NULL && temp->getNext() != loserPile)
			{
				temp = temp->getNext();
			}
			else
			{
				lastOne = true;
			}
		}
	}
}

void Character::setNext(Character *next)
{
	this->next = next;
}

void Character::setPrev(Character *prev)
{
	this->prev = prev;
}

Character *Character::getNext()
{
	return next;
}

Character *Character::getPrev()
{
	return prev;
}