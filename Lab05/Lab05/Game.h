#pragma once
#include <string>
using namespace std;

class Game {
public:
	//String Getter for attribute 1
	string getNameOfGame();

	//Void Setter for attribute 1
	void setNameOfGame(string n);

	//String Getter got attribute 2
	string getRules();

	//Void Setter for attribute 2
	void setRules(string r);

	//Void Play(virtual function)
	virtual void play();

	//Void Winner(non-virtual)
	void winner();

	//Game constructors
	Game();
	Game(string n, string r);

private:
	string nameOfGame; //Attribute 1
	string rules; // Attribute 2
};