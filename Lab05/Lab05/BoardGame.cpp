#include "stdafx.h"
#include "BoardGame.h"
#include "Game.h"
#include "Shelf.h"
#include <iostream>


using namespace std;

//play is from the game class 
void BoardGame::play()
{
	cout << "roll the dice" << endl; // this outputs the string to show how to 
									 //play the game
}

//this is from the game class
void BoardGame::winner()
{
	cout << "Dancing time" << endl; // this outputs the string to show what to 
									//do when someone wins the game
}

//this is the getter for the board size variable. It allows you to get the value of //board size		
int BoardGame::getBoardSize()
{
	return boardSize; //this is what will be returned when getBoard size is 
					  //called
}

//this is the setter for the board size variable. It allwes you to set the value of //board size to a different value
void BoardGame::setBoardSize(int b)
{
	boardSize = b; //this changes the value of board size to what you inputed 
				   //into setBoardSize
}

BoardGame::BoardGame() {
	boardSize = 0;
}

void BoardGame::print() {
	cout << "This is what is in BoardGame: " << endl;
	cout << "Board Size: " << boardSize << endl;
	cout << "Name of Game: " << this->getNameOfGame() << endl;
	cout << "Rules: " << this->getRules() << endl;
	cout << endl;
}

