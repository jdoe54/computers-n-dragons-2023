#pragma once
#include <string>
#include "Physical.h"

class Character: public Physical
{
	std::string name = "";

	int curHealth = 0;
	int maxHealth = 0;

	int curMana = 0;
	int maxMana = 0;

	int curTech = 0;
	int maxTech = 0;

	int strength = 0;
	int dexterity = 0;
	int constitution = 0;

	int intelligence = 0;
	int wisdom = 0;
	int charisma = 0;

	int level = 1;
	int xp = 0;

	public:
		Character(std::string name, int level, int health, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int x, int y);

		int getHealth() { return curHealth; }
		int getMana() { return curMana; }
		int getTech() { return curTech; }
		int getStrength() { return strength; }
		int getDexterity() { return dexterity; }
		int getConstitution() { return constitution; }
		int getIntelligence() { return intelligence; }
		int getWisdom() { return wisdom; }
		int getCharisma() { return charisma; }
		int getLevel() { return level; }
		int getXp() { return xp; }

		int setXp(int addXp);
		int takeDamage(int damage);

};

