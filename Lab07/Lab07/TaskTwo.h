#pragma once
#include "OrderedList.h"


template <typename T>
class TaskTwo : public OrderedList<T> {
public:
	
	void addItem(T* obj) {
		int i = MAX_ITEMS -1;
		while (this->items[i] != nullptr) {
			i--;
		}

		if (i < 0 || this->isFull()) {
			throw Exception("Exceeded number of max items- Stack Overflow");
		}
		this->items[i] = obj;
		this->opAdd++;
	}
};

