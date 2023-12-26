#include "Tile.h"
#include <string>
#include "Item.h"

void Tile::setDescription(std::string description) {
	Tile::description = description;
}

Item Tile::onGround() {
	return Tile::ground;
}