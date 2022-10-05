#pragma once
#include <functional>

#include "Monster.h"
#include "vector"

bool IsSameRace(Monster m1, Monster m2)
{
	return m1.GetRace() == m2.GetRace();
}

void PrintMonster(Monster m)
{
	std::cout << m.ToString() << std::endl;
}

void PrintHP(Monster m)
{
	std::cout << m.CurrentHPToString() << std::endl;
}

void Fight(Monster m1, Monster m2)
{
	if (!IsSameRace(m1, m2))
	{
		PrintMonster(m1);
		PrintMonster(m2);
		Monster* attacker;
		Monster* deffender;
		Monster* tempMonster;
		if (m1.GetS() > m2.GetS())
		{
			attacker = &m1;
			deffender = &m2;
		}
		else
		{
			attacker = &m2;
			deffender = &m1;
		}
		while (m1.GetHP() > 0 && m2.GetHP() > 0)
		{
			attacker->Attack(*deffender);

			tempMonster = attacker;
			attacker = deffender;
			deffender = tempMonster;
			PrintHP(m1);
			PrintHP(m2);
			std::cout << std::endl;
		}
		std::cout << std::endl << deffender->MonsterRaceToString() << " wins the fight !" << std::endl;

	}
	else
	{
		std::cout << "two monsters of the same race cant fight each other !!!" << std::endl;
	}
}

Monster orc(MonsterRace::Orc, 10, 6, 4, 4);
Monster goblin(MonsterRace::Goblin, 5, 2, 1, 7);
Monster troll(MonsterRace::Troll, 15, 8, 4, 2);
