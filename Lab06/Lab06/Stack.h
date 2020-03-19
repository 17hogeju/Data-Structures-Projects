#pragma once
#include "Exception.h"

template <class T>
class Stack {
public:
	// Functions
	template <class T>
	friend void print(Stack<T> a, Stack<T> b, Stack<T> c, int nd);

	Stack(int size) {
		MAXSIZE = size;
		currSize = 0;
		data = new T*[size];
	}


	Stack() {
		MAXSIZE = 0;
		currSize = 0;
		data = new T*[0];
	}

	void push(T* d) {
		if (currSize >= MAXSIZE) {
			throw Exception("Stack is full- Stack Overflow");
		}
		data[currSize] = d;
		currSize++;
	}


	T* pop() {
		T* n = data[currSize-1];
		if (currSize == 0) {
			throw Exception("Stack is empty- Stack Underflow");
		}
		
		//data[currSize-1] = new T(0);
		currSize--;
		return n;
	}


	T* top() {
		return data[currSize-1];
	}


	int length() {
		return currSize;
	}

	void empty() {
		for (int i = 0; i < MAXSIZE; i++) {
			delete data[i];
		}
		currSize = 0;
	}



private:
	int MAXSIZE;
	int currSize;
	T** data = NULL;
};

template <class T>
void print(Stack<T> a, Stack<T> b, Stack<T> c, int nd) {
	cout << endl;
	int alength = a.length();
	int blength = b.length();
	int clength = c.length();
	for (int i = nd-1; i >= 1; i--) { //Prints the stacks excluding the bottom of the stacks which are printed separately
		if (alength < nd) { //If stack has an empty slot, it is printed as such
			cout << "    | " << " " << " |    | ";
			alength++;
		}
		else {
			cout << "    | " << *a.data[i] << " |    | ";
		}
		if (blength < nd) {
			cout << " " << " |    | ";
			blength++;
		}
		else {
			cout << *b.data[i] << " |    | ";
		}
		if (clength < nd) {
			cout << " " << " |" << endl;
			clength++;
		}
		else {
			cout << *c.data[i] << " |" << endl;
		}
		
	}

	//Special case for bottom of the stack for aesthetics
	if (alength < nd) { 
		cout << "    |_" << " " << "_|    |_";
	}
	else {
		cout << "    |_" << *a.data[0] << "_|    |_";
	}
	if (blength < nd) {
		cout << " " << "_|    |_";
	}
	else {
		cout << *b.data[0] << "_|    |_";
	}
	if (clength < nd) {
		cout << " " << "_|" << endl;
	}
	else {
		cout <<*c.data[0] << "_|" << endl;
	}
	cout << "      A        B        C" << endl;

}




