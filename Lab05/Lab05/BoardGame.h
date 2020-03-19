#pragma once
#include "Game.h"
class BoardGame : public Game {
public:
	void play();
	void winner();
	int getBoardSize();
	void setBoardSize(int b);
	BoardGame();
	void print();
	
private:
	int boardSize;
};