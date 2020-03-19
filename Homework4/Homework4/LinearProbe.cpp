#include "stdafx.h"
#include "LinearProbe.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

LinearProbe::LinearProbe() {
	numAvailableSlots = SLOTS;
	table = new int[SLOTS];
	isAllocated = new bool[SLOTS];
	for (int j = 0; j < SLOTS; ++j) {
		isAllocated[j] = false;
	}
}

LinearProbe::~LinearProbe() {
	delete[] table;
	delete[] isAllocated;
}

int LinearProbe::insert(int val) {
	int numOperations = 0;
	int key = hash(val);
	bool openSpot = true;
	while (openSpot) {
		if (isAllocated[key] == false) { //nullptr
			table[key] = val;
			openSpot = false;
			isAllocated[key] = true;
			numAvailableSlots--;
		}
		else {
			key++;
			key %= SLOTS;
		}
		numOperations++;
		
		
	}
	return numOperations;
}

int LinearProbe::find(int val) {
	int counter = 0;
	int key = hash(val);
	if (table[key] == val) {
		return ++counter;
	}
	else {
		while (table[key] != val && counter < SLOTS) {
			counter++;
			key++;
			key %= SLOTS;
		}
		return counter;
	}
	
}
int LinearProbe::remove(int val) {
	int key = hash(val);
	int counter = 0;
	int numOperations = 0;

	while (table[key] != val && counter < SLOTS) {
		numOperations++;
		counter++;
		key++;
		key %= SLOTS;
	}
	if (counter >= SLOTS) {
		return numOperations;
	}
	else {
		numAvailableSlots++;
		numOperations++;
		int temp = table[key];
		table[key] = 0;
		isAllocated[key] = false;
		return numOperations;
	}
}

int LinearProbe::hash(int val) {
	return val % numAvailableSlots;
}

void LinearProbe::print() {
	int space = findSpaceSize();
	int space2 = space;
	string s = " ";
	int split = 5;
	if (SLOTS >= 20) {
		split = 20;
	}
	for (int r = 0; r < SLOTS; r+=split) {
		for (int c = r; c < split+r && c < SLOTS; c++) {
			int nbool = isAllocated[c];
			if (nbool == false) {
				if (space > 4) {
					int i = 0;
					space2 = space - 4;
					while (i < space2) {
						s = s + " ";
						i++;
					}
				}
				cout << "NULL" << s;
				s = " ";
			}
			else {
				int n = table[c];
				int nd = numDigits(n);
				int i = 0;
				s = " ";
				space2 = space - nd;
				while (i < space2) {
					s = s + " ";
					i++;
				}
				cout << n << s;
				s = " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
int LinearProbe::findSpaceSize() {
	int maxNum = 0;
	for (int c = 0; c < SLOTS; c++) {
		if (isAllocated[c] == false) {
			maxNum = max(maxNum, 4);
		}
		else {
			maxNum = max(maxNum, numDigits(table[c]));
		}
	}
	
	return maxNum;
}
int LinearProbe::numDigits(int n) {
	int digits = 0;
	if (n < 0) digits = 1; // remove this line if '-' counts as a digit
	while (n) {
		n /= 10;
		digits++;
	}
	return digits;
}