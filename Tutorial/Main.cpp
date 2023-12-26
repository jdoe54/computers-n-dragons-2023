

#include <iostream>
#include <list>
#include <windows.h>

#include "Physical.h"

using namespace std;

string map[30][100];

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

int loadGame() {
	cout << "Loading game" << endl;
	int player = 0;

	for (int i = 0; i < 30; i++) {
		
		for (int k = 0; k < 100; k++) {
			
			int chance = rand() % 2 + 1;
			if (chance == 1 && player == 0) {
				changeTextColor("GREEN");
				map[i][k] = "P";
				player = 1;
				
			}
			else {
				map[i][k] = ".";
			}
			
			cout << map[i][k];
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


int main() {
	// Start function

	cout << "Welcome to Computers N Dragons!" << endl;

	
	string response = prompt("Start", "Load Game", "Quit", "");

	if (response == "1") {
		startGame();
	}
	else if (response == "2") {
		
		loadGame();
	}
	else if (response == "3") {
		quitGame();
	}

	return 0;
}


