#pragma once
#include <random>
#include <limits>
#include <iostream>

int getRandomInt(int min, int max) {
	std::random_device os_seed;
	uint_least32_t seed = os_seed();

	std::mt19937 generator(seed);
	std::uniform_int_distribution<uint_least32_t> distribute(min, max);

	return distribute(generator);
}

MonsterRace ChooseMonsterRace()
{
	std::string monster;
	std::cout << "Enter a monster race: " << std::endl;
	while (std::cin >> monster) {// allows the user to only input text values (troll orc goblin)
		if (monster == "orc")
			return MonsterRace::Orc;
		else if (monster == "goblin")
			return MonsterRace::Goblin;
		else if (monster == "troll")
			return MonsterRace::Troll;
		std::cout << "Invalid input.  Try again: ";
	}
}

Monster ReturnMonsterByRace(std::vector<Monster> monsters, MonsterRace race)
{
	for (auto monster : monsters)
	{
		if (monster.GetRace() == race)
			return monster;
	}
}

float EnterValue(std::string _waitedValue)
{
	float value;
	std::cout << "Enter a Value to set your " << _waitedValue << ": " << std::endl;
	while (!(std::cin >> value)) {// allows the user to only input numerical values
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	return value;
}
std::vector<Monster> SetupMonsterList()
{
	Monster orc(MonsterRace::Orc, getRandomInt(5, 20), 6, 4, 4);
	Monster goblin(MonsterRace::Goblin, getRandomInt(5, 20), 2, 1, 7);
	Monster troll(MonsterRace::Troll, getRandomInt(5, 20), 8, 4, 2);
	std::vector<Monster> monsters;
	monsters.emplace_back(goblin);
	monsters.emplace_back(orc);
	monsters.emplace_back(troll);
	return monsters;
}

Monster CreateMonster()
{
	std::cout << "Create your monster !" << std::endl;
	MonsterRace playerRace = ChooseMonsterRace();
	float playerHP = EnterValue("HP");
	float playerAD = EnterValue("AD");
	float playerDP = EnterValue("DP");
	float playerS = EnterValue("S");
	Monster playerMonster(playerRace, playerHP, playerAD, playerDP, playerS);
	return playerMonster;
}