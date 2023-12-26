#pragma once
#include <string>

class Item
{
	std::string name;
	int weight;
	int strength;
	int durability;
	std::string type;
	
public:
	Item(std::string name, std::string type, int weight, int strength, int durability);
	std::string getName();
};

