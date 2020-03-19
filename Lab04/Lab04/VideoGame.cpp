
#include "stdafx.h"
#include "VideoGame.h"
#include "Game.h"
#include <iostream>

using namespace std;

//play is from the game class 
void VideoGame::play()
{
	cout << "Mash the buttons" << endl;  // this outputs the string to show 
										 //how to play the game
}

//this is from the game class
void VideoGame::winner()
{
	cout << "Winner, winner, chicken dinner!" << endl; // this outputs the 
													   //string to show what to 
													   //do when someone 
													   //wins the game
}

//this is the getter for the is single player variable. It allows you to get the value of 
//is single player
bool VideoGame::getIsSinglePlayer()
{
	return isSinglePlayer;//this is what will be returned when /	
						  //geIsSinglePlayer called
}

//this is the setter for the is single playervariable. It allwes you to set the value of //is single player to a different value
void VideoGame::setIsSinglePlayer(bool s)
{
	isSinglePlayer = s; //this changes the value of is single player to what you 
						//inputed into setIsSinglePlayer

}

