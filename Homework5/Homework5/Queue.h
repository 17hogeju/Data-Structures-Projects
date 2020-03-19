#pragma once
#pragma once
#pragma once
#include <string>

using namespace std;

template <class T>
class Queue { //A quick and dirty queue class. Has fairly standard implementations, albeit more limited than a normal queue.
private:
	T** data;
	int len = 0;
	int maxSize;
public:
	Queue(int size = 10) {
		data = new T * [size];
		maxSize = size;
	}

	~Queue() {
		delete data;
	}

	T* peek() {
		if (len == 0) {
			string err = "Underflow!";
			throw err;
		}

		return data[0];
	}

	void enqueue(T* newData) {
		if (len == maxSize) {
			string err = "Overflow!";
			throw err;
		}

		data[len] = newData;
		len++;
	}

	T* dequeue() {
		T* toReturn;

		try {
			toReturn = peek();
		}
		catch (string err) {
			throw err;
		}

		data[0] = data[1];

		for (int i = 1; i < len - 1; i++) {
			data[i] = data[i + 1];
		}

		data[len - 1] = nullptr;

		len--;

		return toReturn;
	}

	T** retData() {
		return data;
	}

	bool isempty() {
		return (len == 0);
	}
};