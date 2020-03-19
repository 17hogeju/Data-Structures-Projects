#include "stdafx.h"
#include "Player.h"


void Player::changeRange(int change) {
	w.changeRange(change);
}
void Player::setMaxVal(int max) {
	w.setMaxVal(max);
}


// Getters and setters
double Player::getCurrCash() { 
	return currCash; 
}
void Player::setCurrCash(double c) { 
	currCash = c; 
}
void Player::setBet(int newBet) { //If currBet = 0 and If newBet <1, sets to 1. Otherwise, only change if newBet > currBet and <= currBet*2
	currBet = newBet;
}
int Player::getBet() {
	return currBet;
}


int Player::rollPlr() {
	int n = w.spin();
	plrBall = n;
	return n;
}
int Player::rollComp() { //call spin, save values into comp/plrBall, then return the same val
	int n = w.spin();
	compBall = n;
	return n;

}
bool Player::compareRolls() { //compares plr and comp rolls. Returns true if player wins, false if comp wins.Increments compWins.
	if (plrBall > compBall) {
		return true;
	}
	else {
		return false;
	}
}
bool Player::checkCompWins() { //returns true is compWins is 2 or greater, and sets compWins back to 0. Returns false and does not modify compWins otherwise.
	if (compWins >= 2) {
		compWins = 0;
		return true;
	}
	else {
		return false;
	}
}

Player::Player() {
	currCash = 100;
	plrBall = 0;
	compBall = 0;
	currBet = 0;
	compWins = 0;
}

void Player::setHardMaxVal(int n) {
	h.setCompRange(n);
}
int Player::getHardMaxVal() {
	return h.getCompRange();
}
int Player::rollCompHard() {
	return h.spinComp();
}