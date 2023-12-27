#pragma once
#include <string>

class Item
{
	std::string name;
	int weight = 0;
	int strength = 0;
	int durability = 0;
	int damage = 0;
	int range = 0;
	std::string type;
	
public:
	Item(std::string name, std::string type, int weight, int strength, int durability, int range, int damage);
	Item() = default;
	std::string getName();
	int getDamage();
	std::string getType();
	int getRange();
};

class Sword : public Item { Sword(); };
class Bow : public Item { Bow(); };
class Mace : public Item { Mace(); };

