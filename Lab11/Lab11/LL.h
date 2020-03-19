#pragma once
#include "Node.h"
#include "Exception.h"
#include <iostream>
template <class T>
class LL {
public:

	void reverseList() {
		Node<T>* temp = nullptr;
		Node<T>* curr = head;
		Node<T>* prev = nullptr;
		while (curr != nullptr) {
			temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		head = prev;
	}

	LL() {
		head = nullptr;
		location = 0;
	}
	~LL() {
		Node<T>* curr = head;
		if (curr != nullptr) {
			while (curr->next != nullptr) {
				Node<T>* nextNode = curr->next;
				delete curr;
				curr = nextNode;
			}
			delete curr;
		}

	}
	void addItem(T* item) {
		Node<T>* adder = new Node<T>(item);
		if (head == nullptr) {
			head = adder;
		}
		else {
			Node<T>* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = adder;
		}
	}
	T* getItem(T* item) {
		if (head == nullptr) {
			throw Exception("Empty List");
		}
		if (*head->data == *item) {
			Node<T>* temp = head;
			T* retVal = head->data;
			head = head->next;
			delete temp;
			return retVal;

		}
		Node<T>* ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->data == item) {
				Node<T>* temp = ptr->next;
				ptr->next = ptr->next->next;
				T* retVal = temp->data;
				delete temp;
				return retVal;
			}
			ptr = ptr->next;
		}
		return nullptr;
	}
	bool isInList(T* item) {
		if (head == nullptr) {
			return false;
		}
		Node<T>* ptr = head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		if (*ptr->data == *item) { // calls operator overload ==
			return true;
		}
		else {
			return false;
		}

	}
	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		return false;
	}
	int size() {
		int count = 1;
		if (this->isEmpty()) {
			return 0;
		}
		Node<T>* ptr = head;
		while (ptr->next != nullptr) {
			count++;
			ptr = ptr->next;
		}
		return count;
	}
	T* seeNext() {
		if (this->isEmpty()) {
			throw Exception("Empty List");
		}
		if (location >= this->size()) {
			throw Exception("Index out of bounds");
		}
		Node<T>* ptr = head;
		for (int i = 0; i < location && i < this->size(); i++) {// iterates to the correct location in the LL
			ptr = ptr->next;
		}
		location++;
		return ptr->data;
	}
	T* seeAt(int l) {
		if (this->isEmpty()) {
			throw Exception("Empty List");
		}
		if (l >= this->size() || l < 0) {
			throw Exception("Index out of bounds");
		}
		location = l + 1;
		Node<T>* ptr = head;
		for (int i = 0; i < l; i++) {
			ptr = ptr->next;
		}
		return ptr->data;
	}
	void reset() {
		location = 0;
	}

	//Testing Zone
	void printList() {
		if (head == nullptr) {
			throw Exception("Empty List");
		}
		Node<T>* ptr = head;
		while (ptr->next != nullptr) {
			cout << *ptr->data << " -> ";
			ptr = ptr->next;
		}
		cout << *ptr->data << endl;
	}
private:
	Node<T>* head;
	int location;
};