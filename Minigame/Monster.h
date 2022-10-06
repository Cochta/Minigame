#pragma once
#include <string>
#include <format>
enum class MonsterRace
{
	Orc = 1,
	Troll,
	Goblin,
	End
};
class Monster
{
public:
	Monster();
	Monster(MonsterRace, float hp, float ad, float dp, float s);

	MonsterRace GetRace() { return Race; }
	float GetHP() { return HP; }
	float GetAD() { return AD; }
	float GetDP() { return DP; }
	float GetS() { return S; }

	void SetRace(MonsterRace race) { Race = race; }
	void SetHP(float hp) { HP = hp; }
	void SetAD(float ad) { AD = ad; }
	void SetDP(float dp) { DP = dp; }
	void SetS(float s) { S = s; }

	void Attack(Monster& attackedMonster); // calculated using this attack - attackedmonster defense

	std::string MonsterRaceToString();
	std::string ToString();
	std::string CurrentHPToString();

private:
	MonsterRace Race;

	float HP; // Health Points
	float AD; // Attack Damage
	float DP; // Defense Points
	float S;  // Speed, used to determine initiativ
};

