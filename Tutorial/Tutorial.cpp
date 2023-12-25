

#include <iostream>
#include <list>
#include <windows.h>

using namespace std;




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
	return 0;
}

void changeTextColor(string color) {
	int actualColor = 0;
	if (color == "RED") {

	}
	else if (color == "BLUE") {

	}
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);                                  // h is your link to the console
	SetConsoleTextAttribute(h, );
}


string prompt(string option1, string option2, string option3, string option4) {
	cout << option1 << endl;
	cout << "Let us list out the options." << endl;
	list<string> options = { option1, option2, option3, option4 };
	int index = 0;

	

	for (auto v : options) {
		if (v != "") {
			index += 1;
			cout << index << " - " << v << endl;
		}
	}

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
		quitGame();
	}
	else if (response == "3") {
		loadGame();
	}

	return 0;
}


