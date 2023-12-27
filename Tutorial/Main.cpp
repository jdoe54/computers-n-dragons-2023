

#include <iostream>
#include <list>
#include <windows.h>
#include <conio.h>
#include <array>

#include "Physical.h"
#include "Character.h"
#include "Tile.h"

using namespace std;

Tile map[20][100];
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

	if (chance > 60) {
		area.setDescription("Grass");
	}
	else if (chance > 10 && chance < 20) {
		area.setDescription("Water");
	}
	else if (chance == 30) {
		area.setDescription("Tree");
	}
	else if (chance == 1 && playerChance == 0) {
		playerChance = 1;
		
		area.setDescription("Grass");
		area.setCharacter(newPlayer);
	}
	else {

		area.setDescription("Air");

		if (enemyChance == 1) {
			Bandit enemy;
			area.setCharacter(enemy);
		}
	}
	area.setCoord(cx, cy);

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

	for (int i = 0; i < 20; i++) {
		
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
	
	if (command == "1") { // Up
		if (playerY - 1 < 0) {
			playerY = playerY - 1;
			map[playerY][playerX].setCharacter(newPlayer);
		}
	}
	else if (command == "3") { // Down
		if (playerY + 1 < (end(map) - begin(map))) {
			playerY = playerY + 1;
			map[playerY][playerX].setCharacter(newPlayer);
		}
	}
	else if (command == "4") { // Left
		if (playerX - 1 > 0) {
			playerX = playerX + 1;  
			map[playerY][playerX].setCharacter(newPlayer);
		}
	}
	else if (command == "2") { // Right
		if (playerX + 1 < (end(map[0]) - begin(map[0]))) {
			playerX = playerX - 1;
			map[playerY][playerX].setCharacter(newPlayer);
		}
	}
}

void interact(string command) {
	int interactX = 0;
	int interactY = 0;
	if (command == "1") { // Up
		if (playerY - 1 < 0) {
			interactY = playerY - 1;
			cout << "You see " << map[playerY - 1][playerX].print() << " on your north." << endl;
		}
	}
	else if (command == "3") { // Down
		if (playerY + 1 < (end(map) - begin(map))) {
			interactY = playerY + 1;
			cout << "You see " << map[playerY + 1][playerX].print() << " on your south." << endl;
		}
	}
	else if (command == "4") { // Left
		if (playerX - 1 > 0) {
			interactX = playerX + 1;
			cout << "You see " << map[playerY][playerX + 1].print() << " on your left." << endl;
		}
	}
	else if (command == "2") { // Right
		if (playerX + 1 < (end(map[0]) - begin(map[0]))) {
			interactX = playerX - 1;
			cout << "You see " << map[playerY][playerX - 1].print() << " on your right." << endl;
		}
	}
	Sleep(1000);
	if (map[interactY][interactX].getGround() == 1) {
		cout << "There is also " << map[interactY][interactX].onGround().getName() << " on the ground!" << endl;
	}
	cin;
	
}
list<Character> getZone(int startX, int startY, int endX, int endY) {
	list<Character> characterRoster = {};

	cout << startX << " " << startY << " to " << endX << " " << endY << endl;
	

	for (startY; startY < endY; startY++) {
		for (startX; startX < endX; startX++) {
			if (map[startY][startX].getCharacter() == 1) {
				characterRoster.push_back(map[startY][startX].getCharacterObject());
			}
		}
	}

	return characterRoster;
}

void findEnemy(Item equipped) {
	list<Character> characterRoster = getZone(playerX - equipped.getRange(), playerY - equipped.getRange(), playerX + equipped.getRange(), playerY + equipped.getRange());
	for (auto enemy : characterRoster) {
		cout << enemy.getName() << endl;
	}
}

void attack(string mode) {
	if (mode == "1") { // Fist
		cout << "You put up your fist and can attack: " << endl;

		Item fist = Item("Fist", "Melee", 0, 0, 0, 1, 1);
		newPlayer.wield(fist);
		findEnemy(fist);
	}
	else if (mode == "2") { // Feet
		cout << "You lift your feet and can attack: " << endl;

		Item feet = Item("Feet", "Melee", 0, 0, 0, 2, 1);
		newPlayer.wield(feet);
		findEnemy(feet);
	}
	else if (mode == "3") { // Head
		cout << "You lean back, poise to strike at: " << endl;

		Item head = Item("Head", "Melee", 0, 0, 0, 1, 2);
		newPlayer.wield(head);
		findEnemy(head);
	}
	else if (mode == "4") {
		cout << "You check your hand..." << endl;

		if (newPlayer.checkIfEquipped() == 1) {
			cout << "And you have an item on your hand!" << endl;
			Item equipped = newPlayer.getEquipped();
			if (equipped.getType() == "Ranged") {
				cout << "You hold your " << equipped.getName() << " and can aim at: " << endl;
				
			}
			else if (equipped.getType() == "Melee") {
				cout << "You draw out your " << equipped.getName() << " and can strike: " << endl;
			}
			findEnemy(equipped);
		}
		else {
			cout << "There's nothing on your hand, go to your bag." << endl;
		}
		
	}
	cin;
	Sleep(5000);

}

void gameplay() {
	string response = prompt("Move", "Interact", "Attack", "Bag");
	if (response == "1") {
		cout << "You move which direction?" << endl;
		string move = prompt("Up", "Left", "Down", "Right");
		movement(move);
	}
	else if (response == "2") {
		cout << "What do you interact with?" << endl;
		string touch = prompt("Up", "Left", "Down", "Right");
		interact(touch);
	}
	else if (response == "3") {
		cout << "What will you use?" << endl;
		string weapons = prompt("Fist", "Feet", "Head", "Item");
		attack(weapons);
	}
	else if (response == "4") {
		cout << "You check your bag." << endl;
		list<Item> inventory = newPlayer.getInventory();
		for (auto tool : inventory) {
			cout << tool.getName() << " | " << tool.getDamage() << endl;
		}
		cin;
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
			system("cls");
			loadGame();
		}
	}
	else if (response == "3") {
		quitGame();
	}

	return 0;
}


