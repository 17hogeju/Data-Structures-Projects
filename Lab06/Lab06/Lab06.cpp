// Lab06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include "iostream"
#include <stdio.h>
#include <ctype.h>

using namespace std;


void welcome(); 
void setA(Stack<int> &a, int nd);
void moveDisks(Stack<int> &a, Stack<int> &b, Stack<int> &c, int nd);
bool checkWin(Stack<int> b, Stack<int> c, int nd);
bool illegalMoveTo(Stack<int> &A, Stack<int> &B, Stack<int> &C, string m, string f, int nd);
bool illegalMoveFrom(Stack<int> &A, Stack<int> &B, Stack<int> &C, string m);

int main()
{
	bool cont = true;
	bool win = false;
	int numDisks;
	string contResponse;

	welcome();
	while (cont) {
		do {
			if (!cin) {
				cin.clear(); // reset failbit
				cin.ignore(256, '\n'); //skip bad input
			}
			cout << "Enter number of disks you wish to play with: ";
			cin >> numDisks;
		} while (!cin || numDisks <= 0);

		
		Stack<int> a(numDisks);
		Stack<int> b(numDisks);
		Stack<int> c(numDisks);

		setA(a, numDisks);
		print(a, b, c, numDisks);

		while (win == false) {
			moveDisks(a, b, c, numDisks);
			print(a, b, c, numDisks);
			win = checkWin(b,c, numDisks);
		}
		cout << "You win!" << endl;
		win = false; // Must be reset for following possible game
		do {
			if (isdigit(contResponse[0])) {
				cin.clear(); // reset failbit
				cin.ignore(256, '\n'); //skip bad input
			}

			cout << "Would you like to play again? (Y/N): ";
			cin >> contResponse;
			contResponse = toupper(contResponse[0]);
		} while ((contResponse.compare("Y") == 1 || contResponse.compare("N") == 1 ) && isdigit(contResponse[0]));
		
		if (contResponse.compare("N") == 0) {
			cout << "Thanks for playing!" << endl;
			cont = false;
		}

		
	}
	



    return 0;
}

void welcome() {
	cout << "**********************************************************************" << endl;
	cout << "*************************** Towers of Hanoi **************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << "Rules:" << endl;
	cout << "1: You can only move one disk at a time." << endl;
	cout << "2: Each move consists of taking the upper disk from one of the stacks " << endl;
	cout << "   and placing it on top of another stack or on an empty rod." << endl;
	cout << "3: No larger disk may be placed on top of a smaller disk." << endl;
	cout << endl;

}

void setA(Stack<int> &a, int nd) {
	for (int i = nd-1; i >= 0; i--) {
		a.push(new int(i+1));
	}
}

/*****************************MOVEDISKS******************************
* This function takes in the three stacks and the max size of the
* stacks. It takes in the locations the player wants to move to and
* from. If the move is legal, it moves the ring/number to the
* appropriate stack the user selected.
*********************************************************************/
void moveDisks(Stack<int> &a, Stack<int> &b, Stack<int> &c, int nd) {
	string moveTo;
	string moveFrom;
	int* mT;
	bool Illegal = false;
	
	do {
		if (isdigit(moveFrom[0]) || Illegal) {
			cin.clear(); // reset failbit
			cin.ignore(256, '\n'); //skip bad input
			Illegal = false;
		}

		cout << "Where would you like to move from? (A/B/C): ";
		cin >> moveFrom;
		moveFrom = toupper(moveFrom[0]);
		Illegal = illegalMoveFrom(a, b, c, moveFrom);
	} while ((moveFrom.compare("A") == 1 || moveFrom.compare("B") == 1 || moveFrom.compare("C") == 1) && isdigit(moveFrom[0]) || Illegal); //Asks for user input again if input is not A/B/C 

	do {
		if (isdigit(moveTo[0]) || Illegal) {
			cin.clear(); // reset failbit
			cin.ignore(256, '\n'); //skip bad input
			Illegal = false;
		}
		
		cout << "Where would you like to move to? (A/B/C): ";
		cin >> moveTo;
		moveTo = toupper(moveTo[0]);
		Illegal = illegalMoveTo(a, b, c, moveTo, moveFrom, nd);
	} while ((moveTo.compare("A") == 1 || moveTo.compare("B") == 1 || moveTo.compare("C") == 1) && isdigit(moveTo[0]) || Illegal);

	if (moveFrom.compare("A") == 0) {
		mT = a.pop();
	}
	else if (moveFrom.compare("B") == 0) {
		mT = b.pop();
	}
	else {
		mT = c.pop();

	}

	if (moveTo.compare("A") == 0) {
		a.push(mT);
	}
	else if (moveTo.compare("B") == 0) {
		b.push(mT);
	}
	else {
		c.push(mT);

	}
	
}


/******************************CHECKWIN*******************************
* This function takes in the second and third stack and the max size 
* of the stack. If the length of the second or third stack is equal 
* to the max size of the stack, you win. Stacks should be in descending
* order based on illegal moves. 
*********************************************************************/
bool checkWin(Stack<int> b, Stack<int> c, int nd) {
	//Stack<int> cTest = c;
	bool correct = true;
	if (c.length() < nd && b.length() < nd) {
		correct = false;
	}
	return correct;
}

bool illegalMoveTo(Stack<int> &A, Stack<int> &B, Stack<int> &C, string m, string f, int nd) {
	int fMove;
	int mMove;
	bool illMove = false;

	if (m.compare("A") == 0 && A.length() != 0) {
		mMove = *A.top();
	}
	else if (m.compare("B") == 0 && B.length() != 0) {
		mMove = *B.top();
	}
	else if (m.compare("C") == 0 && C.length() != 0) {
		mMove = *C.top();
	}
	else {
		mMove = nd;
	}

	if (f.compare("A") == 0) {
		fMove = *A.top();
	}
	else if (f.compare("B") == 0) {
		fMove = *B.top();
	}
	else {
		fMove = *C.top();
	}


	if (fMove > mMove) {
		illMove = true;
	}
	
	
	if (illMove == true) {
		cout << "Illegal move: please try again." << endl;
	}
	return illMove;
}

bool illegalMoveFrom(Stack<int> &A, Stack<int> &B, Stack<int> &C, string m) {

	bool illMove = false;

	if (A.length() == 0 && m.compare("A") == 0) {
		illMove = true;
	}
	if (B.length() == 0 && m.compare("B") == 0) {
		illMove = true;
	}
	if (C.length() == 0 && m.compare("C") == 0) {
		illMove = true;
	}

	if (illMove == true) {
		cout << "Illegal move: please try again." << endl;
	}
	return illMove;
}