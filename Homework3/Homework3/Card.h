#pragma once
class Card {
public:
	Card(int v) {
		value = v;
		next = nullptr;
	}
	int value;
	Card* next;
};