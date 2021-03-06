// Homework4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Buckets.h"
#include "LinearProbe.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>


using namespace std;

const int TESTSIZE = 100;

int main()
{
	srand(time(NULL));
	Buckets b;
	LinearProbe l;
	int randNums[100];
	int spotsCheckedL = 0;
	int spotsCheckedB = 0;

	cout << "Random Numbers and their indeces:" << endl;
	for (int i = 0; i < TESTSIZE; i++) { // Generate array of random numbers
		randNums[i] = rand() % SLOTS;
		cout << "i: " << i << " Num: " << randNums[i] << endl;
	}
	cout << endl;


	for (int i = 0; i < TESTSIZE/2; i++) { //Insert first 50 items
		spotsCheckedL += l.insert(randNums[i]);
		spotsCheckedB += b.insert(randNums[i]);
	}
	cout << "Number of spots checked while inserting first " << TESTSIZE/2 << " items" << endl;
	cout << "1D Hash Table: " << spotsCheckedL << endl;
	cout << "2D Hash Table: " << spotsCheckedB << endl;
	spotsCheckedL = 0;
	spotsCheckedB = 0;
	l.print();

	for (int i = 0; i < TESTSIZE; i++) { //Remove items where index of the value % 7 == 0
		if (i % 7 == 0) {
			cout << "Removing " << randNums[i] << endl;
			cout << "l.remove(" << randNums[i] << "): " << l.remove(randNums[i]) << endl;
			spotsCheckedL += l.remove(randNums[i]);
			spotsCheckedB += b.remove(randNums[i]);
		}
	}
	cout << "Number of spots checked while removing items where index % 7 == 0" << endl;
	cout << "1D Hash Table: " << spotsCheckedL << endl; // This number will be large because some of the items wont be there because not
	cout << "2D Hash Table: " << spotsCheckedB << endl; //     all randomly generated numbers have been added
	spotsCheckedL = 0;
	spotsCheckedB = 0;
	l.print();

	for (int i = TESTSIZE/2; i < TESTSIZE; i++) { //Insert last 50 items
		spotsCheckedL += l.insert(randNums[i]);
		spotsCheckedB += b.insert(randNums[i]);
	}
	cout << "Number of spots checked while inserting last " << TESTSIZE/2 <<" items" << endl;
	cout << "1D Hash Table: " << spotsCheckedL << endl;
	cout << "2D Hash Table: " << spotsCheckedB << endl;
	spotsCheckedL = 0;
	spotsCheckedB = 0;
	l.print();

	for (int i = 0; i < TESTSIZE; i++) { //Remove items where index of the value % 9 == 0 and item wasn't previously removed
		if (i % 9 == 0 && i % 7  != 0) {
			cout << "Removing " << randNums[i] << endl;
			cout << "l.remove("<<randNums[i] <<"): " << l.remove(randNums[i]) << endl;
			//spotsCheckedB += b.remove(randNums[i]);
		}
	}
	cout << "Number of spots checked while removing items where index % 9 == 0 and item wasn't previously removed" << endl;
	cout << "1D Hash Table: " << spotsCheckedL << endl; // This number should be smaller because all random numbers have been added so 
	cout << "2D Hash Table: " << spotsCheckedB << endl; //	  it wont try to remove an object that isn't there
	spotsCheckedL = 0;
	spotsCheckedB = 0;
	l.print();
    return 0;
}

