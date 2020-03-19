#include "stdafx.h"
#include "Buckets.h"
#include <iostream>
#include <algorithm>
using namespace std;


Buckets::Buckets() {
	hashTable = new int*[rows];
	for (int i = 0; i < rows; ++i) { //Create a 
		hashTable[i] = new int[cols];
	}
	isAllocated = new bool* [rows];
	for (int j = 0; j < rows; ++j) {
		isAllocated[j] = new bool[cols];

	}
	for (int c = 0; c < cols; c++) {
		for (int r = 0; r < rows; r++) {
			isAllocated[r][c] = false;
		}
	}


}
Buckets::~Buckets() {
	for (int i = 0; i < rows; ++i) {
		delete[] hashTable[i];
	}
	delete[] hashTable;

}
int Buckets::insert(int n) {
	return 0;
}
int Buckets::find(int n) {
	return 0;
}
int Buckets::remove(int n) {
	return 0;
}
void Buckets::print() {
	int space = findSpaceSize();
	int space2 = space;
	string s = " ";
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			int n = hashTable[r][c];
			int nbool = isAllocated[r][c];
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
int Buckets::findSpaceSize() {
	int maxNum = 0;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (isAllocated[r][c] == false) {
				maxNum = max(maxNum, 4);
			}
			else {
				maxNum = max(maxNum, numDigits(hashTable[r][c]));
			}
		}
	}
	return maxNum;
}
int Buckets::numDigits(int n) {
	int digits = 0;
	if (n < 0) digits = 1; // remove this line if '-' counts as a digit
	while (n) {
		n /= 10;
		digits++;
	}
	return digits;
}
int Buckets::hash(int n) {
	return 0;
}