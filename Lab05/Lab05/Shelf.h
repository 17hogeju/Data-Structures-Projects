#pragma once
#define BGSIZE 10
#include "BoardGame.h"
#include "Exception.h"
// Shelf Class definition
using namespace std;

class Shelf {
public:
	Shelf();
	void addBoardGame(BoardGame b);
	BoardGame removeBoardGame();
	int getNumGames();
	void setNumGames(int n);
	BoardGame BG[BGSIZE];
	

private:
	int numGames; // Current number of board games being stored in Shelf 
	

};