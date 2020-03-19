#pragma once
#include <string>
#include <iostream>
#include "Node.h"
#include "Exception.h"
using namespace std;

template <class T>
class HashTable {
private:
	int count = 0;
	int maxHash;
	T ** table;
	int numOperations;
	int size;
	int hash(string s) {
		int num = 0;
		for (int i = 0; i < s.length(); i++) {
			num = num + (int)s[i];
		}
		return num % maxHash;
	}
public:
	HashTable(int m = 100) {
		maxHash = m;
		size = 0;
		table = new T*[maxHash];
		for (int i = 0; i < maxHash; i++) {
			table[i] = nullptr;
		}
	}
	~HashTable() {
		for (int i = 0; i < maxHash; i++) {
			table[i] = nullptr;
		}
	}
	void addItem(T* item) {
		string strItem = *item;
		int key = hash(strItem);
		bool openSpot = true;
		while (openSpot) {
			cout << "Key: " << key << endl;
			if (table[key] == nullptr) { //nullptr
				table[key] = item;
				openSpot = false;
				size++;
			}
			key++;
			key %= maxHash;
			numOperations++;
		}
	}
	T* removeItem(T item) {
		string strItem = item;
		int counter = 0;
		int key = hash(strItem);
		while (*table[key] != item && counter < maxHash) {
			counter++;
			key++;
			key %= maxHash;
		}
		if (counter >= maxHash) {
			return nullptr;
		}
		else {
			size--;			
			T* temp = table[key];
			table[key] = nullptr;
			return temp;
		}

	}
	T* getItem(T item) {
		string strItem = item;
		int counter = 0;
		int key = hash(strItem);
		while (*table[key] != item && counter < maxHash) {
			counter++;
			key++;
			key %= maxHash;
		}
		if (counter >= maxHash) {
			return nullptr;
		}
		else {
			return table[key];
		}

	}

	void print() {
		for (int i = 0; i < maxHash; i++) {
			if (table[i] == nullptr) {
				cout << "null" << endl;
			}
			else {
				cout << *table[i] << endl;
			}
		}
	}

	int getLength() {
		return size;
	}
	int getCount() 
	{
		return count;
	}
	int getNumOperations() {
		return numOperations;
	}

};