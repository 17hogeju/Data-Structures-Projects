#pragma once
#include <string>

using namespace std;

template <class T>
class Stack { //A quick and dirty stack class. Has fairly standard implementations, albeit more limited than a normal stack.
private:
	T** data;
	int len = 0;
	int maxSize;
public:
	Stack(int size = 10) {
		data = new T * [size];
		maxSize = size;
	}

	~Stack() {
		delete data;
	}

	T* peek() {
		if (len == 0) {
			string err = "Underflow!";
			throw err;
		}

		return data[len - 1];
	}

	void push(T* newData) {
		if (len == maxSize) {
			string err = "Overflow!";
			throw err;
		}

		data[len] = newData;
		len++;
	}

	T* pop() {
		T* toReturn;

		try {
			toReturn = peek();
		}
		catch (string err) {
			throw err;
		}

		data[len - 1] = nullptr;
		len--;

		return toReturn;
	}

	bool isempty() {
		return (len == 0);
	}
};