#pragma once
#include "Card.h"
#include <vector>
#include "Exception.h"
#define MAX_SIZE 52
#include <iostream>

using namespace std;

class Deck {
public:
	void printQueue() {
		if (head == nullptr || qsize == 0) {
			throw Exception("Empty List");
		}
		Card * ptr = head;
		while (ptr->next != nullptr) {
			cout << ptr->value << " -> ";
			ptr = ptr->next;
		}
		cout << ptr->value << endl;
	}
	Deck(int l);// Generates a vector of l integers shuffled randomly
	void enqueue(int c);
	int dequeue();
	int top();
	int getQsize();
	

private:
	Card * head;
	int qsize;
};
