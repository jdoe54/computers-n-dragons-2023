#pragma once
#include <string>
#include "Item.h"
#include "Physical.h"

class Tile: public Physical
{
	std::string terrain;
	std::string description;
	int height = 0;
	Item ground;

	public:
		void setDescription(std::string description);
		Item onGround();
};

