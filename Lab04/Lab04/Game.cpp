#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "Game.h"
using namespace std;

//Game()
Game::Game()
{
	rules = "how do you not know the rules ? ";
	nameOfGame = "how do you not know the name of the Game ? ";
}

Game::Game(string n, string r)
{
	rules = r;
	nameOfGame = n;
}

string Game::getNameOfGame()
{
	return nameOfGame;
}

//Void Setter for attribute 1
void Game::setNameOfGame(string n)
{
	nameOfGame = n;
}

//String Getter got attribute 2
string Game::getRules()
{
	return rules;
}

//Void Setter for attribute 2
void Game::setRules(string r)
{
	rules = r;
}

//Void Play(virtual function)
void Game::play()
{
	cout << "This is play() in Game" << endl;
}

//Void Winner(non-virtual)
void Game::winner()
{
	cout << "not yet" << endl;
}

