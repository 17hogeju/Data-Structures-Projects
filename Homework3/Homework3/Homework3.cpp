// Homework3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"
#include "SideDeck.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void welcome();
int choices(Deck p, SideDeck sd);
void peekCard(int n, string player);
int printCard(int n, string player, vector<int>& v);
int printCard(int n, string player, int n2, vector<int>& v);
string translateCard(int card);
int compChoose(Deck cd, SideDeck csd);
int compPrint(Deck& cd, SideDeck& csd, vector<int>& v);


int main()
{
	Deck playerDeck(MAX_SIZE);
	Deck computerDeck(0);
	SideDeck playerSideD;
	SideDeck computerSideD;
	bool win = false;
	int choice;
	int pchoice;
	int cchoice;
	vector<int> cardsForWinner;
	int i = 0;

	
	
	while (i < 26) { // Fill up computer deck with half of cards from player deck
		computerDeck.enqueue(playerDeck.dequeue());
		i++;
	}

	
	welcome();
	while (win == false) {
		if (playerDeck.getQsize() == 0 && playerSideD.getNumCards() == 0) { //winning condition computer wins
			cout << "You lose War." << endl;
			cout << "Thanks for playing!" << endl;
			win = true;
		}
		else if (computerDeck.getQsize() == 0 && computerSideD.getNumCards() == 0) {//winning condition player wins
			cout << "You win War!" << endl;
			cout << "Thanks for playing!" << endl;
			win = true;
		}
		else {
			if (playerDeck.getQsize() != 0) {
				choice = choices(playerDeck, playerSideD);
				switch (choice) {
				case 1://Play card from top of deck

					pchoice = printCard(playerDeck.dequeue(), "P", cardsForWinner);
					cout << "VS" << endl;
					cchoice = compPrint(computerDeck, computerSideD, cardsForWinner);

					if (cchoice >= pchoice) { // if computers total card score is greater
						cout << "Computer Wins." << endl;
						for (int i = 0; i < cardsForWinner.size(); i++) {
							computerDeck.enqueue(cardsForWinner.at(i));
						}
						cardsForWinner.clear();
					}
					else {
						cout << "Player Wins!" << endl;
						for (int i = 0; i < cardsForWinner.size(); i++) {
							playerDeck.enqueue(cardsForWinner.at(i));
						}
						cardsForWinner.clear();
					
					}

					break;
				case 3:// Pull additional card from side pile to play

					pchoice = printCard(playerDeck.dequeue(), "P",playerSideD.removeCard(),cardsForWinner);
					cout << "VS" << endl;
					cchoice = compPrint(computerDeck, computerSideD, cardsForWinner);

					if (cchoice >= pchoice) { // if computers total card score is greater
						cout << "Computer Wins." << endl;
						for (int i = 0; i < cardsForWinner.size(); i++) {
							computerDeck.enqueue(cardsForWinner.at(i));
						}
						cardsForWinner.clear();
						
					}
					else {
						cout << "Player Wins!" << endl;
						for (int i = 0; i < cardsForWinner.size(); i++) {
							playerDeck.enqueue(cardsForWinner.at(i));
						}
						cardsForWinner.clear();
					
					}

					break;
				case 4: // Push card to side pile and play next card from deck

					playerSideD.addCard(playerDeck.dequeue());
					pchoice = printCard(playerDeck.dequeue(), "P", cardsForWinner);
					cout << "VS" << endl;
					cchoice = compPrint(computerDeck, computerSideD, cardsForWinner);



					if (cchoice >= pchoice) { // if computers total card score is greater
						cout << "Computer Wins." << endl;
						for (int i = 0; i < cardsForWinner.size(); i++) {
							computerDeck.enqueue(cardsForWinner.at(i));
						}
						cardsForWinner.clear();
					
					}
					else {
						cout << "Player Wins!" << endl;
						for (int i = 0; i < cardsForWinner.size(); i++) {
							playerDeck.enqueue(cardsForWinner.at(i));
						}
						cardsForWinner.clear();
					
					}

					break;
				}
			}
			else { // pull from side deck
				pchoice = printCard(playerSideD.removeCard(), "P",cardsForWinner);
				cout << "VS" << endl;
				cchoice = compPrint(computerDeck, computerSideD, cardsForWinner);

				if (cchoice >= pchoice) { // if computers total card score is greater
					cout << "Computer Wins." << endl;
					for (int i = 0; i < cardsForWinner.size(); i++) {
						computerDeck.enqueue(cardsForWinner.at(i));
					}
					cardsForWinner.clear();
				
				}
				else {
					cout << "Player Wins!" << endl;
					for (int i = 0; i < cardsForWinner.size(); i++) {
						playerDeck.enqueue(cardsForWinner.at(i));
					}
					cardsForWinner.clear();
			
				}

			}


		}
		

	}

	
	
    return 0;
}

void welcome() {
	cout << "  _             _        _        _  _  _  _       " << endl;
	cout << " (_)           (_)     _(_)_     (_)(_)(_)(_) _    " << endl;
	cout << " (_)           (_)   _(_) (_)_   (_)         (_)   " << endl;
	cout << " (_)     _     (_) _(_)     (_)_ (_) _  _  _ (_)   " << endl;
	cout << " (_)   _(_)_   (_)(_) _  _  _ (_)(_)(_)(_)(_)      " << endl;
	cout << " (_)  (_) (_)  (_)(_)(_)(_)(_)(_)(_)   (_) _       " << endl;
	cout << " (_)_(_)   (_)_(_)(_)         (_)(_)      (_) _    " << endl;
	cout << "   (_)       (_)  (_)         (_)(_)         (_)   " << endl;
	cout << "***************************************************" << endl;
	cout << "***************************************************" << endl;
}

int choices(Deck p, SideDeck sd) {
	int c;
	cout << "Number of cards in your deck: " << p.getQsize() << endl;
	cout << "(1): Draw card" << endl;
	cout << "(2): Peek at card" << endl;
	cout << "What would you like to do?: ";
	while (!(cin >> c) || c < 1 || c > 2) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Not an available operation, try again" << endl;
	}

	if (c == 2) {
		peekCard(p.top(), "P");
		cout << "Number of cards in side deck: " << sd.getNumCards() << endl;
		cout << "(3): Pull additional card from side deck" << endl;
		cout << "(4): Push card to side pile" << endl;
		cout << "What would you like to do?: ";
		while (!(cin >> c) || c < 3 || c > 4 || (sd.getNumCards() == 0 && c == 3) || (sd.getNumCards() == 5 && c == 4)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Not an available operation, try again" << endl;
		}
	}
	return c;
}

void peekCard(int n, string player) {
	string s = translateCard(n);

	cout << " _____ " << endl;
	if (n == 10) {
		cout << "|" << s << "   |" << endl;
	}
	else {
		cout << "|" << s << "    |" << endl;
	}

	cout << "|     |" << endl;
	cout << "|  " << player << "  |" << endl;
	cout << "|     |" << endl;
	if (n == 10) {
		cout << "|___" << s << "|" << endl;
	}
	else {
		cout << "|____" << s << "|" << endl;
	}

	cout << endl;
}

int printCard(int n, string player, vector<int>& v) {

	string s = translateCard(n);

	cout << " _____ " << endl;
	if (n == 10) {
		cout << "|" << s << "   |" << endl;
	}
	else {
		cout << "|" << s << "    |" << endl;
	}
	
	cout << "|     |" << endl;
	cout << "|  " << player <<"  |" << endl;
	cout << "|     |" << endl;
	if (n == 10) {
		cout << "|___" << s << "|" << endl;
	}
	else {
		cout << "|____" << s << "|" << endl;
	}
	
	cout << endl;
	v.push_back(n);
	return n;
	
}

int printCard(int n, string player, int n2, vector<int>& v) {

	string s = translateCard(n);
	string s2 = translateCard(n2);

	cout << " _____   _____ " << endl;
	if (n == 10 && n2 != 10) {
		cout << "|" << s << "   | |" << s2 << "    |" << endl;
	}
	else if (n == 10 && n2 == 10) {
		cout << "|" << s << "   | |" << s2 << "   |" << endl;
	}
	else if(n != 10 && n2 == 10){
		cout << "|" << s << "    | |" << s2 << "   |" << endl;
	}
	else {
		cout << "|" << s << "    | |" << s2 << "    |" << endl;
	}
	cout << "|     | |     |" << endl;
	cout << "|  " << player << "  | |  "<< player <<"  |" << endl;
	cout << "|     | |     |" << endl;
	if (n == 10 && n2 != 10) {
		cout << "|___" << s << "| |____" << s2 << "|" << endl;
	}
	else if (n == 10 && n2 == 10) {
		cout << "|___" << s << "| |___" << s2 << "|" << endl;
	}
	else if (n != 10 && n2 == 10) {
		cout << "|____" << s << "| |___" << s2 << "|" << endl;
	}
	else {
		cout << "|____" << s << "| |____" << s2 << "|" << endl;
	}
	
	cout << endl;
	v.push_back(n);
	v.push_back(n2);
	return n + n2;

}

string translateCard(int card) { //Turns card integer into human readable value
	switch (card) {
		case 1:
			return "A";
		case 2:
			return "2";
		case 3:
			return "3";
		case 4:
			return "4";
		case 5:
			return "5";
		case 6:
			return "6";
		case 7:
			return "7";
		case 8:
			return "8";
		case 9:
			return "9";
		case 10:
			return "10";
		case 11:
			return "J";
		case 12:
			return "Q";
		case 13:
			return "K";
	}
}

int compChoose(Deck cd, SideDeck csd) {
	if (cd.getQsize() == 0) {
		return 3;
	}
	srand(time(0));
	int randomVal = rand() % 2;
	switch (randomVal) {
	case 0: // pull card
		return 0;
	case 1: // peek at card
		if ((cd.top() < 8 && csd.getNumCards() > 0) || csd.getNumCards() == MAX_SIDE_SIZE) { //pull from stack and play 2 cards
			return 2;
		}
		else { // push card onto stack and play next deck card
			return 1;
		}
		break;
	}
	return 0;
}

int compPrint(Deck& cd, SideDeck& csd, vector<int>& v) {
	int result;
	int compChoice = compChoose(cd, csd);
	if (compChoice == 0) { // play card from deck
		result = printCard(cd.dequeue(), "C", v);
		return result;
	}
	else if (compChoice == 1) {//play card from deck after pushing card to stack
		csd.addCard(cd.dequeue());
		result = printCard(cd.dequeue(),"C",v);
		return result;
	}
	else if (compChoice == 2) { //play two cards
		result = printCard(cd.dequeue(),"C",csd.removeCard(),v);
	}
	else { // play card from stack
		result = printCard(csd.removeCard(),"C",v);
	}
}