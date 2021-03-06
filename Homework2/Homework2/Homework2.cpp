// Homework2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Player.h"
#include "Wheel.h"
#include <string>
#include <iostream>
#include <time.h>



using namespace std;

void welcome();

int main()
{ //emma code
	srand(time(NULL));
	bool cashOut = false; //this bool checks to see if player wants to keep playing 
	string playAgain = "";//this holds the value inputed by the user on wether they want to play again
	int bet = 0; //the amount the player is betting
	welcome(); //outputs all the rules
	Player p; //the player intsiated 
	double money = p.getCurrCash(); //this is a value to hold the money for player
	string hardMode = ""; //this holds the value if the player wants to play in hard mode 
	int count = 0; //this val hold how many times the house has won in a row in hard mode
	int pBall; //this val holds the value of player ball
	int houseBall; //this val holds the value of house ball
	string betMore = ""; //this val holds the value the player enters if they want to bet more
	int maxNewBet = 0; //this holds the value of the maximum value possible of the new bet
	int newBet = maxNewBet + 1; // this holds the value the user imputs the new bet
	int wheelSize = 0; //this holds the value of the wheel size
	int compWheelSize = wheelSize; //this holds the value of of the computer's wheel size

								   //set the max of the range of the player and house wheels
	do{ //this will loop until a proper wheelSize value is inputed
		if (!cin) {
			cin.clear(); // reset failbit
			cin.ignore(256, '\n'); //skip bad input
		}
		//this askes the user to enter a wheel size
		cout << "You begin this game with $100.00" << endl;
		cout << "Please enter a value for the wheel size greater than or equal to 6 and less than or equal to 20: ";
		cin >> wheelSize; //this saves the users value to wheel size

	}while (!cin || (wheelSize > 20) || (wheelSize < 6));

	p.setMaxVal(wheelSize); //this sets the wheel to the wheel size value
	p.setHardMaxVal(wheelSize);

	compWheelSize = wheelSize;

	//this while loop checks to see if the user wants to quit or runs out of money
	
	while (cashOut == false && money  > 0)
	{
		//this gets the current cash that the player has
		money = p.getCurrCash();
		//askes if the user wants to play in hard mode
		if (hardMode .compare("Y") != 0 && hardMode.compare("y") != 0) {
			cout << "Do you want to play hard mode?(type: Y or N)";
			cin >> hardMode;//stores the user's answer
							//askes ths user for a minimum bet
		}
		
		do
		{
			cout << "Make a minimum bet: ";
			cin >> bet; //Player is set up to return a bet of 1 if bet is <1
		} while (bet > p.getCurrCash() || bet < 1);

		maxNewBet = 2 * bet; //this calculates the maximun value that the new bet can be
		p.setBet(bet); //this sets the inputed bet to the bet value in player
						  //player releases the ball
			pBall = p.rollPlr();
		//return reults of where ball landed
		cout << "Player ball landed on: " << pBall << endl;
		//if want to increase wager
		cout << "Do you want to increase your bet? (Y/N): ";
			cin >> betMore; //this holds the values the user inputs 
									//check to see if the user wants to bet more money
		if (betMore.compare("Y") == 0 || betMore.compare("y") == 0)
		{
			int oldBet = newBet;

			//new value of bet
			do //this while loop that makes sure the inputed new bet is under the correct amount
			{
				//this asks the user to input their new bet
				cout << "Enter a new bet that is less than double your original bet: ";
				cin >> newBet; //this sets the inputes value to new bet
			} while (newBet > maxNewBet || newBet <= oldBet || newBet > money);

			//this sets newbet to bet
			bet = newBet;
			p.setBet(bet); //this sets the new bet to bet
		}
		//house releases ball
		houseBall = p.rollComp();
		cout << "Computer Ball landed on: " << houseBall << endl;
		//this if statemtn checks whether you are playing in nard mode or not.
		if (hardMode.compare("Y") == 0 ||  hardMode.compare("y") == 0)
		{
			//playing in hard mode
			//this if statement check to see if the player or computer wins
			if (p.compareRolls())
			{
				//player wins
				
				cout << "You win!" << endl;
				//add player bet to money
				p.setCurrCash(bet + money);
				//increase houses wheel by 1
				money = p.getCurrCash();
				cout << "Money: " << money << endl;
				compWheelSize += 1; //this increases the wheel size by one
				p.setHardMaxVal(compWheelSize); //sets the computer wheel to the new size
				count = 0; // count for the number of times in a row the house won set to zero
			}
			else
			{
				//house wins
				
				cout << "House wins!" << endl;
				//subtract player bet from their money
				p.setCurrCash(money - bet);
				money = p.getCurrCash();
				cout << "Money: " << money << endl;
				count += 1; //increas number of times house has won in a row
							//if count == 2 then
				if (count == 2)
				{
					//decrese number of sides
					compWheelSize -= 1;//this decreases the size of wheel by one
					p.setHardMaxVal(compWheelSize); //sets the computer wheel to the new size
					count = 0; // count for the number of times in a row the house won set to zero
				}
			}
			cout << "Computer's wheel size is now: " << p.getHardMaxVal() << endl;
		}
		else
		{
			//scince they are not playing in hard mode count is set to zero
			count = 0;
			//if player ball > house ball
			if (p.compareRolls())
			{
				//player wins
				
				cout << "You win!" << endl;
				//add player bet to money
				p.setCurrCash(bet + money);
				money = p.getCurrCash();
				cout << "Money: " << money << endl;
			}
			else
			{
				//house wins
				
				cout << "House wins!" << endl;
				//subtract player bet from their money
				p.setCurrCash(money - bet);
				money = p.getCurrCash();
				cout << "Money: " << money << endl;
			}
		}
		//ask if want to play again
		cout << "Do you want to play again?(Y or N)";
		cin >> playAgain; //sets the user's inputed values to play again
								  // if not want to contiue
		if (playAgain.compare("N") == 0 || playAgain.compare("n") == 0)
		{
			cashOut = true; //this will exit the loop
		}
		money = p.getCurrCash(); //this sets the new value of the money in p to money
	}
	//outputs the final amout of money the user has
	cout << "your final money is: " << money << endl;
	return 0;
}

void welcome() {
	string rules;
	cout << "************************************" << endl;
	cout << "Welcome to *Almost* Roulette!" << endl;
	cout << "************************************" << endl;
	cout << endl;
	
	do {
		cout << "Would you like to see the rules ? (Y / N)";
		cin >> rules;
		rules[0] = toupper(rules[0]);
	} while (!(rules.compare("N") == 0 || rules.compare("Y") == 0) || !isalpha(rules[0]));
	
	if (rules.compare("Y") == 0) {
		cout << "Player makes a minimum bet then releases the ball to see \n";
		cout << "where it lands on the wheel.The player may then look at \n ";
		cout << "their results and increase the wager by a maximum of double \n";
		cout << "the original wager if they choose.The house may then release \n";
		cout << "its ball.The player wins only if their ball lands on a spot that has \n";
		cout << "a larger value than the house(house wins all ties).The game \n";
		cout << "is over when the player chooses to stop or runs out of money. \n";
		cout << endl;
	}



}




