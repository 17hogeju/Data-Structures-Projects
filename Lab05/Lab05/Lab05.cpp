// Lab05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Shelf.h"
using namespace std;

void overloadedFunct(BoardGame& b);

int main()
{
	bool cont = true;
	int response;
	Shelf s;
	while (cont == true) {
		do {
			if (!cin) {
				cin.clear(); // reset failbit
				cin.ignore(256, '\n'); //skip bad input
			}
			cout << "Press 1 to add a Board Game: " << endl;
			cout << "Press 2 to remove a Board Game from the shelf: " << endl;
			cout << "Press 3 to see how many board games are currently on the shelf: " << endl;
			cout << "Pres 4 to quit: " << endl;
			cin >> response;
		} while (!cin || response < 1 || response > 4);

		switch (response) {
		case 1: {
			BoardGame b;
			overloadedFunct(b);
			try {
				s.addBoardGame(b);
			}
			catch (Exception& e) {
				cout << "You threw an exception: " << e.getMessage() << endl;
				cout << endl;
			}
			break;
		}
		case 2: {
			BoardGame a;
			try {
				a = s.removeBoardGame();
				a.print();
			}
			catch (Exception& e) {
				cout << "You threw an exception: " << e.getMessage() << endl;
				cout << endl;
			}
			break;
		}
		case 3: {
			cout << "Number of Games on shelf: " << s.getNumGames() << endl;
			break;
		}
		case 4: {
			cout << "Thanks for using this program. Have a nice day :)" << endl;
			cont = false;
			break;
		}
		}
	}
	

    return 0;
}

void overloadedFunct(BoardGame& b) {
	string NoG;
	string r;
	int bs;
	cout << "Current value of boardgame instance: " << endl;
	cout << "Board Size: " << b.getBoardSize() << endl;
	cout << "Current values of game instance: " << endl;
	cout << "Name of Game: " << b.getNameOfGame() << endl;
	cout << "Rules: " << b.getRules() << endl;

	cout << endl;
	do {
		if (!cin) {
			cin.clear(); // reset failbit
			cin.ignore(256, '\n'); //skip bad input
		}
		cout << "Enter new value for Board Size: " << endl;
		cin >> bs;
	} while (!cin);
	cout << "Enter new value for Name of Game: " << endl;
	cin >> NoG;
	cin.clear();
	cin.ignore(256, '\n');
	cout << "Enter new value for Rules: " << endl;
	getline(cin, r);

	b.setBoardSize(bs);
	b.setNameOfGame(NoG);
	b.setRules(r);

	cout << endl;
	cout << "Board Size is now: " << b.getBoardSize() << endl;
	cout << "Name of Game is now: " << b.getNameOfGame() << endl;
	cout << "Rules are now: " << b.getRules() << endl;
	cout << endl;
}

