#include "Tile.h"
#include <string>
#include "Physical.h"
#include "Item.h"
#include "Character.h"
#include <iostream>

Tile::Tile(int x, int y): Physical(x, y) {
	
}

void Tile::setDescription(std::string description) {
	Tile::description = description;
}

std::string Tile::getDescription() {
	return Tile::description;
}

Item Tile::onGround() {
	return Tile::ground;
}
void Tile::setGround(Item onFloorItem) {
	Tile::ground = onFloorItem;
}

bool Tile::getCharacter() {
	
	if (Tile::characterBoolean == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Tile::getGround() {
	if (Tile::groundBoolean == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Tile::setCharacter(Character newPerson) {
	Tile::characterBoolean = true;
	Tile::person = newPerson;
}

void Tile::leaveTile() {
	Tile::characterBoolean = false;
}

Character Tile::getCharacterObject() {
	return Tile::person;
}

std::string Tile::print() {
	int* coordinate = Tile::getCoord();
	std::string result;
	if (Tile::getCharacter() == 1) {
		result = Tile::getCharacterObject().getName() + " on " + Tile::getDescription();;
	}
	else {
		result = Tile::getDescription();
	}
	 
	return result;
}