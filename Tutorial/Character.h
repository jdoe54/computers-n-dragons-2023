#pragma once
#include <string>
#include <list>
#include "Physical.h"
#include "Item.h"

class Character
{
	std::string name = "";
	std::string type = "";

	list<Item> inventory;

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

	bool isAlive = true;
	bool isEquipped = false;

	int level = 1;
	int xp = 0;

	Item equipped;

	public:
		Character(std::string name, int level, int health, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int x, int y);
		Character() = default;

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
		std::string getName() { return name; }
		std::string getType() { return type; }

		int setXp(int addXp);
		int takeDamage(int damage);
		int attack(Character other, Item equipped);

		list<Item> getInventory();
		
		bool checkIfEquipped();
		Item getEquipped();
		void removeEquipped();
		void wield(Item newTool);
		void setType(std::string type);

		

};

class Bandit : public Character 
{
public:
	Bandit();
};

class Player : public Character {
public:
	Player();
};