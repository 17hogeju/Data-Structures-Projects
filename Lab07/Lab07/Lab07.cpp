// Lab07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Exception.h"
#include "OrderedList.h"
#include "TaskTwo.h"
#include "TaskThree.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;


int main()
{

	srand(time(NULL));
	OrderedList<int> o;
	TaskTwo<int> t;
	TaskThree<int> e;
	int* a,* b,* c;
	int randomNum1, randomNum2, randomNum3, randomNum4, randomNum5, randomNum6;
	int randomIndices[MAX_ITEMS];
	int addCounto = 0, addCountt = 0, addCounte = 0;
	int removeCounto = 0, removeCountt = 0, removeCounte = 0;
	int randomVal;
	int programCount = 0;

	
	for (int i = 0; i < MAX_ITEMS; i++) { // Creates an array of indices that can be shuffled in order to have unique random indices for removal
		randomIndices[i] = i;
	}
	for (int z = 0; z < 100; z++) {
		while (addCounto < 30 || removeCounto < 25) {
			randomVal = rand() % 2;
			if (randomVal == 0) {//add
				randomNum1 = (rand() % 100);

				a = new int(randomNum1);

				try {
					o.addItem(a);
				}
				catch (Exception& ex) {
					cout << "You threw an exception: " << ex.getMessage() << endl;
					cout << endl;
					addCounto--;
				}
				addCounto++;
			}
			else {//remove
				random_shuffle(&randomIndices[0], &randomIndices[MAX_ITEMS - 1]);

				randomNum4 = randomIndices[0];


				try {
					o.removeItem(randomNum4);
				}
				catch (Exception& ex) {
					cout << "You threw an exception: " << ex.getMessage() << endl;
					cout << endl;
					removeCounto--;
				}

	
				removeCounto++;
			}
		}
		while (addCountt < 30 || removeCountt < 25) {
			randomVal = rand() % 2;
			if (randomVal == 0) {//add
				randomNum2 = (rand() % 100);
				b = new int(randomNum2);
				try {
					t.addItem(b);
				}
				catch (Exception& ex) {
					cout << "You threw an exception: " << ex.getMessage() << endl;
					cout << endl;
					addCountt--;
				}

				addCountt++;
			}
			else {//remove
				random_shuffle(&randomIndices[0], &randomIndices[MAX_ITEMS - 1]);

				randomNum5 = randomIndices[0];


				try {
					t.removeItem(randomNum5);
				}
				catch (Exception& ex) {
					cout << "You threw an exception: " << ex.getMessage() << endl;
					cout << endl;
					removeCountt--;
				}


				removeCountt++;
			}
		}
		while (addCounte < 30 || removeCounte < 25) {
			randomVal = rand() % 2;
			if (randomVal == 0) {//add
				randomNum3 = (rand() % 100);
				c = new int(randomNum3);
				try {
					e.addItem(c);
				}
				catch (Exception& ex) {
					cout << "You threw an exception: " << ex.getMessage() << endl;
					cout << endl;
					addCounte--;
				}
				addCounte++;
			}
			else {//remove
				random_shuffle(&randomIndices[0], &randomIndices[MAX_ITEMS - 1]);

				randomNum6 = randomIndices[0];


				try {
					e.removeItem(randomNum6);
				}
				catch (Exception& ex) {
					cout << "You threw an exception: " << ex.getMessage() << endl;
					cout << endl;
					removeCounte--;
				}
				
				removeCounte++;

			}
		}
		
		o.makeEmpty();
		t.makeEmpty();
		e.makeEmpty();
		addCounto = 0;
		addCountt = 0;
		addCounte = 0;
		removeCounto = 0;
		removeCountt = 0;
		removeCounte = 0;
	}
	cout << "Counts after 100 runs: (Array size " << MAX_ITEMS << ")" << endl;
	cout << "Base Class: " << endl;
	o.printResults();
	cout << "Derrived Class 1: " << endl;
	t.printResults();
	cout << "Derrived Class 2: " << endl;
	e.printResults();

	
    return 0;
}

