

#include <iostream>
#include <list>
#include <windows.h>
#include <conio.h>
#include <array>

#include "Physical.h"
#include "Character.h"
#include "Tile.h"

using namespace std;

Tile map[30][100];
Player newPlayer;

int playerChance = 0;
bool loading = true;
int playerX = 0;
int playerY = 0;

void changeTextColor(string color) {
	int actualColor = 0;

	if (color == "RED") {
		actualColor = 4;
	}
	else if (color == "BLUE") {
		actualColor = 1;
	}
	else if (color == "GREEN") {
		actualColor = 2;
	}
	else if (color == "YELLOW") {
		actualColor = 6;
	}
	else if (color == "WHITE" || color == "DEFAULT") {
		actualColor = 7;
	}
	else if (color == "GRAY") {
		actualColor = 8;
	}
	else if (color == "DARK BLUE") {
		actualColor = 9;
	}
	else if (color == "LIME") {
		actualColor = 10;
	}

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, actualColor);
}

int startGame() {
	cout << "A dangerous world!" << endl;
	return 0;
}

int quitGame() {
	cout << "Goodbye!" << endl;
	return 0;
}

Tile randomThing(Tile area, int cx, int cy) {
	int chance = rand() % 100 + 1;
	int enemyChance = rand() % 10 + 1;

	

	//cout << chance << endl;
	if (chance > 60) {
		//cout << "Grass" << endl;
		area.setDescription("Grass");
	}
	else if (chance > 10 && chance < 20) {
		//cout << "Water" << endl;
		area.setDescription("Water");
	}
	else if (chance == 30) {
		//cout << "Tree" << endl;
		area.setDescription("Tree");
	}
	else if (chance == 1 && playerChance == 0) {
		playerChance = 1;
		
		area.setDescription("Grass");
		area.setCharacter(newPlayer);
	}
	else {
		////cout << "Air" << endl;
		area.setDescription("Air");
		//cout << "Description: " << area.getDescription() << endl;
		

		if (enemyChance == 1) {
			Bandit enemy;
			//int* coordinate = area.getCoord();
			//enemy.setCoord(coordinate[0], coordinate[1]);
			area.setCharacter(enemy);
		}
	}
	area.setCoord(cx, cy);
	//cout << "Set to " << area.getCoord()[0] << ", " << area.getCoord()[1] << endl;

	return area;
}

string getTerrain(Tile area) {
	
	if (area.getCharacter() == 1) {
		//cout << area.print() << endl;
		if (area.getCharacterObject().getType() == "Enemy") {
			changeTextColor("RED");
			return "E";
		}
		else if (area.getCharacterObject().getType() == "Ally") {
			changeTextColor("GREEN");
			return "A";
		}
		else if (area.getCharacterObject().getType() == "NPC") {
			
			changeTextColor("BLUE");
			return "C";
		}
		else if (area.getCharacterObject().getType() == "Player") {
			changeTextColor("YELLOW");
			return "P";
		}
	}
	else {
		
		if (area.getDescription() == "Water") {
			changeTextColor("DARK BLUE");
			return "~";
		}
		else if (area.getDescription() == "Grass") {
			changeTextColor("GREEN");
			return ".";
		}
		else if (area.getDescription() == "Air") {
			changeTextColor("WHITE");
			return " ";
		}
		else if (area.getDescription() == "Tree") {
			changeTextColor("LIME GREEN");
			return "*";
		}
		else if (area.getDescription() == "Wall") {
			changeTextColor("GREY");
			return "█";
		}
	}
	
}

int loadGame() {

	cout << "Loading game" << endl;

	for (int i = 0; i < 30; i++) {
		
		for (int k = 0; k < 100; k++) {
			if (loading == 1) {
				map[i][k] = randomThing(map[i][k], i, k);
			}
			
			string result = getTerrain(map[i][k]);
			if (result == "P") {
				playerX = k;
				playerY = i;
			}

			cout << result;
			changeTextColor("DEFAULT");
		}
		cout << endl;
		
	}

	
	return 0;
}

string prompt(string option1, string option2, string option3, string option4) {
	cout << option1 << endl;
	cout << "Let us list out the options." << endl;
	list<string> options = { option1, option2, option3, option4 };
	int index = 0;

	changeTextColor("YELLOW");
	for (auto v : options) {
		if (v != "") {
			index += 1;
			cout << index << " - " << v << endl;
		}
	}

	changeTextColor("DEFAULT");
	string response = "";
	cin >> response;


	return response;
}


void movement(string command) {
	map[playerY][playerX].leaveTile();

	if (command == "1") {
		if (playerY - 1 < 0) {
			playerY = playerY - 1;
			map[playerY][playerX].setCharacter(newPlayer);
		}
	}
	else if (command == "3") {
		if (playerY + 1 < (end(map) - begin(map))) {
			playerY = playerY + 1;
			map[playerY][playerX].setCharacter(newPlayer);
		}
		
	}
	else if (command == "4") {
		if (playerX - 1 > 0) {
			playerX = playerX - 1;
			map[playerY][playerX].setCharacter(newPlayer);
		}
	}
	else if (command == "2") {
		if (playerX + 1 < (end(map[0]) - begin(map[0]))) {
			playerX = playerX + 1;
			map[playerY][playerX].setCharacter(newPlayer);
		}
	}
}

void interact() {

}

void attack() {

}

void gameplay() {
	string response = prompt("Move", "Interact", "Attack", "Quit");
	if (response == "1") {
		cout << "You move which direction?" << endl;
		string move = prompt("Up", "Left", "Down", "Right");
		movement(move);
	}
	else {
		cout << "You do nothing." << endl;
	}
}



int main() {
	// Start function

	cout << "Welcome to Computers N Dragons!" << endl;

	
	string response = prompt("Start", "Load Game", "Quit", "");

	if (response == "1") {
		startGame();
	}
	else if (response == "2") {
		

		loadGame();
		loading = false;

		while (true) {
			gameplay();
			loadGame();
		}
			

		
		
		
	}
	else if (response == "3") {
		quitGame();
	}

	return 0;
}


