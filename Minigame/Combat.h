#pragma once

#include "Monster.h"
#include "vector"
#include <Windows.h>

bool IsSameRace(Monster m1, Monster m2) // return true if monster are f same race
{
	return m1.GetRace() == m2.GetRace();
}

bool AbleToFight(Monster m1, Monster m2) // return true if min 1 monster can take damages
{
	return m1.GetAD() - m2.GetDP() > 0 || m2.GetAD() - m1.GetDP() > 0;
}

void PrintMonster(Monster m)
{
	std::cout << m.ToString() << std::endl;
}

void PrintHP(Monster m)
{
	std::cout << m.CurrentHPToString() << std::endl;
}

void Fight(Monster& m1, Monster m2)
{
	if (!IsSameRace(m1, m2)) // check if monsters are same race
	{
		if (AbleToFight(m1, m2)) // check if min 1 monster is able to deal damages to the other
		{
			PrintMonster(m1);
			PrintMonster(m2);
			Monster* attacker;
			Monster* deffender;

			if (m1.GetS() > m2.GetS()) // initiativ
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
				//Sleep(1000);
				if (deffender->GetHP() <= 0)
				{
					break;
				}
				Monster* tempMonster = attacker;
				attacker = deffender;
				deffender = tempMonster;
				PrintHP(m1);
				PrintHP(m2);
				std::cout << std::endl;

			}
			std::cout << std::endl << attacker->MonsterRaceToString() << " wins the fight !" << std::endl;
		}
		else
		{
			std::cout << "Both monster armor is too high to take damages !!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Two monsters of the same race cant fight each other !!!" << std::endl;
	}
}
