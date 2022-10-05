#include "Monster.h"

#include <iostream>

Monster::Monster(MonsterRace race, float hp, float ad, float dp, float s)
{
	Race = race;
	HP = hp;
	AD = ad;
	DP = dp;
	S = s;
}

void Monster::Attack(Monster& attackedMonster)
{
	float dmg = this->GetAD() - attackedMonster.GetDP();
	if (dmg < 0)
	{
		dmg = 0;
	}
	attackedMonster.SetHP(attackedMonster.GetHP() - dmg);
	std::cout << MonsterRaceToString() << " deals " << dmg << " damages to " << attackedMonster.MonsterRaceToString() + "\n";
}

std::string Monster::MonsterRaceToString()
{
	switch (GetRace())
	{
	case MonsterRace::Goblin:
		return "Goblin";
	case MonsterRace::Orc:
		return "Orc";
	case MonsterRace::Troll:
		return "Troll";
	}
}

std::string Monster::ToString()
{
	std::string ad = std::format("{:.2f}", GetAD());
	std::string hp = std::format("{:.2f}", GetHP());
	std::string dp = std::format("{:.2f}", GetDP());
	std::string s = std::format("{:.2f}", GetS());
	return MonsterRaceToString() + ": " + hp + " Hp\nAd = " + ad + "\nDp = " + dp + "\nS = " + s + "\n";
}

std::string Monster::CurrentHPToString()
{
	std::string hp = std::format("{:.2f}", GetHP());
	return MonsterRaceToString() + ": " + hp + " Hp";
}
