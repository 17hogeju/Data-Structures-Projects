#include "stdafx.h"
#include "Deck.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <vector>

using namespace std;



Deck::Deck(int l) {
	srand(time(0));
	vector<int> dk;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			dk.push_back(j);
		}
	}
	random_shuffle(dk.begin(), dk.end());

	for (int i = 0; i < l; i++) {
		enqueue(dk.at(i));
	}
	qsize = l;
}

void Deck::enqueue(int c) { // adds cards to front of queue  4->3->2->1
	if (qsize == MAX_SIZE) {
		throw "Queue Undeflow Exception";
	}
	else {
		qsize++;
		Card* adder = new Card(c);
		if (head == nullptr) {
			head = adder;
		}
		else {
			adder->next = head;
			head = adder;
		}

	}
}

int Deck::dequeue() { //removes from back of queue 4->3->2 return 1
	if (head == nullptr || qsize == 0) {
		throw "Empty Queue Exception";
	}
	else if (head->next == nullptr) {
		int retVal = head->value;
		head = nullptr;
		qsize--;
		return retVal;
	}
	else {
		Card * temp = head;
		Card * previous = head;
		while (temp->next != nullptr) {
			previous = temp;
			temp = temp->next;
		}
		qsize--;
		int retVal = temp->value;
		previous->next = nullptr;
		delete temp;
		return retVal;
	}
}

int Deck::top() {
	Card * temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	return temp->value;
}

int Deck::getQsize() {
	return qsize;
}