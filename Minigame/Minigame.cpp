#include <iostream>
#include "Combat.h"
#include "Controller.h"
#include "string"

int main()
{
	std::vector<Monster> monsters = SetupMonsterList(); // creates a monster vector with 3 default entries

	Monster playerMonster = CreateMonster(); // the user creates his own monster

	std::cout << std::endl << "Choose your oponnent !" << std::endl;
	for (auto monster : monsters)
	{
		PrintMonster(monster);
	}

	Fight(playerMonster, ReturnMonsterByRace(monsters, ChooseMonsterRace())); // user choose the oponnent

}