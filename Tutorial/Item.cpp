#include "Item.h"
#include <string>

Item::Item(std::string name, std::string type, int weight, int strength, int durability) {
	Item::name = name;
	Item::type = type;
	Item::weight = weight;
	Item::strength = strength;
	Item::durability = durability;
}

std::string Item::getName() {
	return Item::name;
}