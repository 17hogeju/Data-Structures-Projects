#pragma once
#define SLOTS 500

class LinearProbe {
private:
	int hash(int val);
	int numAvailableSlots;
	int * table;
	bool * isAllocated;
	int findSpaceSize();
	int numDigits(int n);
public:
	LinearProbe();
	~LinearProbe();
	int insert(int val);
	int find(int val);
	int remove(int val);
	void print();

};