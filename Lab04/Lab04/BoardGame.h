#pragma once
#include "Game.h"
class BoardGame : public Game {
public:
	void play();
	void winner();
	int getBoardSize();
	void setBoardSize(int b);
	
private:
	int boardSize;
};