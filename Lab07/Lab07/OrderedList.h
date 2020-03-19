#pragma once
#include "Exception.h"
#define MAX_ITEMS 30

template <typename T>
class OrderedList {
public:
	
	bool isFull() {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (items[i] == nullptr) {
				return false;
			}
		}
		return true;
	}

	bool isEmpty() {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (items[i] != nullptr) {
				return false;
			}
		}
		return true;
	}

	OrderedList() {
		opAdd = 0;
		opRemove = 0;
		items = new T*[MAX_ITEMS]();
		
	}

	/*
	Start at the front of the array (index 0) when searching for a place to insert 
	a new item at the first empty location. Every operation should increment the 
	counter created in step b (except checks to see if an array location holds a nullptr).
	*/
	void addItem(T* obj) {
		int i = 0;
		while (items[i] != nullptr) {
			i++;
		}
		
		if (i >= MAX_ITEMS || this->isFull()) {
			throw Exception("Exceeded number of max items- Stack Overflow");
		}
		items[i] = obj;
		opAdd++;
	}

	/*
	It should be able to remove any item from the array(by accepting an index location) 
	and also ensure that the items in the array are still in order and there are no empty 
	spots between items. Every operation should increment the counter created in step b 
	(except checks to see if an array location holds a nullptr).
	*/
	void removeItem(int index) {
		if (items[index] == nullptr || this->isEmpty()) {
			throw Exception("Can not remove an empty item");
		}
		if (index == MAX_ITEMS - 1) {
			items[index] = nullptr;
			opRemove++;
		}
		else {
			for (int i = index; items[i] != nullptr; i++) {
				T* next = items[i + 1];
				items[i] = next;
				opRemove++;

			}
			items[MAX_ITEMS - 1] = nullptr;
		}
	}

	void makeEmpty() {
		for (int i = 0; i < MAX_ITEMS; i++) {
			items[i] = nullptr;
		}
	}

	void printResults() {
		cout << "Operations Performed by Add method : " << opAdd << endl;
		cout << "Operations Performed by Remove method : " << opRemove << endl;
		cout << "Total Operations Performed: " << opAdd + opRemove << endl;
	}
protected:
	T ** items;
	int opAdd;
	int opRemove;

};



