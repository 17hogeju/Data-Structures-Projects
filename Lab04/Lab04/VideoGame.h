#pragma once
#include "Game.h"
class VideoGame : public Game {
public:
	void play();
	void winner();
	bool getIsSinglePlayer();
	void setIsSinglePlayer(bool s);
private:
	bool isSinglePlayer;
};