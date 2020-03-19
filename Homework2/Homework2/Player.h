#pragma once
#include "Wheel.h"
#include "HardWheel.h"

class Player {
public:
	double getCurrCash();
	void setCurrCash(double c);

	void changeRange(int change);
	void setMaxVal(int max);
	void setBet(int newBet); //If currBet = 0 and If newBet <1, sets to 1. Otherwise, only change if newBet > currBet and <= currBet*2
	int getBet();
	int rollPlr();
	int rollComp(); //call spin, save values into comp/plrBall, then return the same val
	bool compareRolls(); //compares plr and comp rolls. Returns true if player wins, false if comp wins.Increments compWins.
	bool checkCompWins(); //returns true is compWins is 2 or greater, and sets compWins back to 0. Returns false and does not modify compWins otherwise.
	Player();
	void setHardMaxVal(int n);
	int getHardMaxVal();
	int rollCompHard();

private:
	Wheel w;
	HardWheel h;
	double currCash;
	int plrBall;
	int compBall;
	int currBet;
	int compWins;

};