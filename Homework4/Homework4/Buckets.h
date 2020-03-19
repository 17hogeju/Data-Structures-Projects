#pragma once
#include <string>
#define rows 10
#define cols 5

using namespace std;

class Buckets {
public:
	Buckets();
	~Buckets();
	int insert(int n);
	int find(int n);
	int remove(int n);
	void print();
private:
	int hash(int n);
	int **hashTable ;
	bool **isAllocated;
	int findSpaceSize();
	int numDigits(int n);
};