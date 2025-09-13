#include "Character.h"
#include "Player.h"
#include "Physical.h"
#include <string>
#include <list>


Character::Character(std::string name, int level, int health, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int x, int y) {

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
	if (Character::getHealth() < 0) {
		Character::isAlive = false;
	}
	return Character::getHealth();
}

int Character::attack(Character other, Item equipped) {
	other.takeDamage(equipped.getDamage());
	return equipped.getDamage();
}

void Character::setType(std::string newType) {
	Character::type = newType;
}

void Character::wield(Item newTool) {
	Character::isEquipped = true;
	Character::equipped = newTool;
}

void Character::removeEquipped() {
	Character::isEquipped = false;
}

bool Character::checkIfEquipped() {
	return Character::isEquipped;
}

Item Character::getEquipped() {
	return Character::equipped;
}

list<Item> Character::getInventory() {
	return Character::inventory;
}

Bandit::Bandit() : Character("Bandit", 1, 4, 1, 1, 1, 1, 1, 1, 0, 0) {
	Bandit::setType("Enemy");
}

Player::Player() : Character("Player", 1, 16, 1, 1, 1, 1, 1, 1, 0, 0) {
	Player::setType("Player");
}