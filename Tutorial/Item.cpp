#include "Item.h"
#include <string>

Item::Item(std::string name, std::string type, int weight, int strength, int durability, int range, int damage) {
	Item::name = name;
	Item::type = type;
	Item::weight = weight;
	Item::strength = strength;
	Item::durability = durability;
}

std::string Item::getName() {
	return Item::name;
}

int Item::getDamage() {
	return Item::damage;
}

std::string Item::getType() {
	return Item::type;
}

int Item::getRange() {
	return Item::range;
}

Sword::Sword() : Item("Sword", "Melee", 2, 1, 1, 1, 8) {}
Bow::Bow() : Item("Bow", "Range", 1, 1, 1, 4, 2) {}
Mace::Mace() : Item("Mace", "Melee", 2, 2, 1, 1, 10) {}