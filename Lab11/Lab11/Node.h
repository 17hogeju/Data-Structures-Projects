#pragma once
using namespace std;

template <class T>
class Node {
public:
	Node(T* d) {
		data = d;
		next = nullptr;
	}
	Node() {
		data = nullptr;
		next = nullptr;
	}
	T* data;
	Node* next;

	//Testing Zone 
	void print() {
		cout << "Data: " << *data << endl;
		cout << "Next: " << next << endl;
	}
private:
};