#pragma once
#include <string>
#include "Item.h"
#include "Physical.h"
#include "Character.h"

class Tile: public Physical
{
	std::string terrain;
	std::string description;
	Character person;
	int height = 0;
	bool characterBoolean = false;
	bool groundBoolean = false;
	Item ground;

	public:
		
		Tile(int x, int y);
		Tile() = default;

		void setDescription(std::string description);
		void setGround(Item onFloorItem);
		
		std::string getDescription();
		Item onGround();
		bool getCharacter();
		bool getGround();

		void setCharacter(Character newPerson);
		void leaveTile();
		Character getCharacterObject();

		std::string print();
};

