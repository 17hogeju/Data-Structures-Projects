#pragma once
#include <iostream>
#define MAX_SIDE_SIZE 5

using namespace std;

class SideDeck {
private:
	int numCards;
	int pile[MAX_SIDE_SIZE];
public:
	SideDeck();
	void addCard(int c); //adds card to end of stack ie: 1->2->3->4->5
	int removeCard(); //returns the last card put in the stack ie: 1->2->3->4 returns 5
	int getNumCards(); //returns the number of cards in the stack
	friend void printSD(SideDeck s) {
		int length = s.numCards;
		for (int i = (MAX_SIDE_SIZE - 1); i >= 1; i--) {
			if (length < MAX_SIDE_SIZE) { //If stack has an empty slot, it is printed as such
				cout << "| " << " " << " |" << endl;
				length++;
			}
			else {
				cout << "| " << s.removeCard() << " |" << endl;
			}
		}
		if (length < MAX_SIDE_SIZE) {
			cout << "|___|" << endl;
		}
		else {
			cout << "|_" << s.removeCard() << "_|" << endl;
		}
	}
};

