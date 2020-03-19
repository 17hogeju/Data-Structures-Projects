#include "stdafx.h"
#include "SideDeck.h"

SideDeck::SideDeck() {
	for (int i = 0; i < MAX_SIDE_SIZE; i++) {
		pile[i] = 0;
	}
	numCards = 0;
}

void SideDeck::addCard(int c) {
	if (numCards >= MAX_SIDE_SIZE) {
		throw "Stack Overflow";
	}
	else {
		pile[numCards] = c;
		numCards++;
	}
	
}

int SideDeck::removeCard() {
	if (numCards <= 0) {
		throw "Stack Underflow";
	}
	else {
		numCards--;
		int temp;
		temp = pile[numCards];
		pile[numCards] = 0;
		return temp;
	}
	
}

int SideDeck::getNumCards() {
	return numCards;
}

