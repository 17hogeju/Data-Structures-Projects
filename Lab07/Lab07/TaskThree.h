#pragma once
#include "OrderedList.h"


template <typename T>
class TaskThree : public OrderedList<T> {
public:


	void addItem(T* obj) {
		if (this->isFull()) {
			throw Exception("Exceeded number of max items- Stack Overflow");
		}
		int mid = ceil(MAX_ITEMS / 2.0) - 1;
		if (this->items[mid] == nullptr) {
			this->items[mid] = obj;
			this->opAdd++;
		}
		else {
			int arr[MAX_ITEMS * 2]; // creates an array that flows circularly ie: 0123401234 if MAX_ITEMS = 5
			for (int k = 0; k < MAX_ITEMS; k++) {
				arr[k] = k;
			}
			for (int l = MAX_ITEMS; l < (MAX_ITEMS * 2); l++) {
				arr[l] = l - MAX_ITEMS;
			}


			int i = mid;
			
			while (this->items[arr[i]] != nullptr) { //Locates the rightmost blank space. Uses the circular array for indices larger than MAX_ITEMS
				i++;
				if (i >= ((2*MAX_ITEMS)-1)) {
					throw Exception("Exceeded number of max items- Stack Overflow");
					break;
				}
			}
			for (int j = i; j > mid; j--) {
				this->items[arr[j]] = this->items[arr[j-1]];// Sets the rightmost blank space equal to the space before it
				this->opAdd++;								// Also uses the circular array for indices larger than MAX_ITEMS
			}
			this->items[mid] = obj;
			this->opAdd++;
			
		}

			
	}

	void removeItem(int index) {
		if (this->items[index] == nullptr || this->isEmpty()) {
			throw Exception("Can not remove an empty item");
		}
		this->items[index] = nullptr;
		this->opRemove++;
	}
};
