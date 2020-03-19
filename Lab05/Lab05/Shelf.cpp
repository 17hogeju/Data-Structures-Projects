// Shelf Declaration
#include "stdafx.h"
#include "Shelf.h"
#include <iostream>




using namespace std;

Shelf::Shelf() {
	numGames = 0;
}
void Shelf::addBoardGame(BoardGame b) {
	if (numGames >= BGSIZE) {
		throw Exception("Shelf is Full");
	}
	BG[numGames] = b;
	numGames += 1;
}
BoardGame Shelf::removeBoardGame() {
	if (numGames <= 0) {
		throw Exception("Shelf is Empty");
	}
	int n = numGames - 1;
	BoardGame out = BG[n];
	BG[n].setBoardSize(0);
	BG[n].setNameOfGame("");
	BG[n].setRules("");
	numGames -= 1;
	return out;

}
int Shelf::getNumGames() {
	return numGames;
}
void Shelf::setNumGames(int n) {
	numGames = n;
}