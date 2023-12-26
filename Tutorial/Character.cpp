#include "Character.h"
#include "Physical.h"
#include <string>


Character::Character(std::string name, int level, int health, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int x, int y): Physical(x, y) {

	Character::level = level;
	Character::curHealth = health;
	Character::strength = strength;
	Character::dexterity = dexterity;
	Character::constitution = constitution;
	Character::intelligence = intelligence;
	Character::wisdom = wisdom;
	Character::charisma = charisma;
	Character::name = name;
}

int Character::setXp(int addXp) {
	Character::xp = Character::getXp() + addXp;
	return Character::getXp();
}

int Character::takeDamage(int damage) {
	Character::curHealth = Character::getHealth() - damage;
	return Character::getHealth();
}

