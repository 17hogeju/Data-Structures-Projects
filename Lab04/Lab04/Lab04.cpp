// Lab04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "BoardGame.h"
#include "VideoGame.h"
#include "Game.h"
using namespace std;

void currVal(int n);

int main()
{
	bool cont = true;
	string cont2;
	int response;
	while (cont == true) {
		do {
			cout << "Press 1 for an instance of game." << endl;
			cout << "Press 2 for an instance of board game." << endl;
			cout << "Press 3 for an instance of video game." << endl;
			cout << "Press 4 for an instance of a board game declared as a game" << endl;
			cout << "Press 5 for an instance of a video game declared as a game" << endl;
			cin >> response;
		} while (cin.fail() || response > 5 || response < 1);

		currVal(response);
		// Funtion that Displaly current value of attributes and asks for updated values

		do {
			cout << "Would you like to continue? (Y/N)" << endl;
			cin >> cont2;
			cont2[0] = toupper(cont2[0]);
		} while (cin.fail() || (cont2.compare("N") == 1 && cont2.compare("Y") == 1));
		if (cont2.compare("N") == 0) {
			cont = false;
		}
	}


    return 0;
}

void currVal(int n) {
	switch (n) {
	case 1:{
		Game inst1;
		//inst1.play();
		//inst1.winner();
		break;
	}
	case 2:{
		BoardGame inst2;
		//inst2.play();
		//inst2.winner();
		break;
	}
	case 3:{
		VideoGame inst3;
		//inst3.play();
		//inst3.winner();
		break;
	}
	case 4:{
		BoardGame inst5;
		Game *inst4 = &inst5;
		//inst4->play();
		//inst4->winner();
		break;
	}
	case 5:{
		VideoGame inst7;
		Game *inst6 = &inst7;
		//inst6->play();
		//sinst6->winner();
		break;
	}
	}
}

