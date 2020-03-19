#pragma once

using namespace std;

template <class t> class Node {
public:
	t data;
	Node<t>* left;
	Node<t>* right;

	Node() { //default contructor
		left = nullptr;
		right = nullptr;
	}
	Node(t val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

class Heap {
private:
	//int size;
	Node<t>* root;
public:
	Heap() { //default constructor
		root = nullptr;
		size = 0;
	}
	Heap(Node<t>* myroot) {
		root = myroot;
		//size = 1;
	}
	void insert(t inVal) {
		Node<t>* ptr = root;
		if (root == nullptr) {
			root = new Node<t>(inVal);
			//size++;
		}
		else {
			while ((inVal > ptr->data && ptr->right != nullptr) || (inVal <= ptr->data && ptr->left != nullptr)) {
				if (inVal > ptr->data) {
					ptr = ptr->right;
				}
				else {
					ptr = ptr->left;
				}

			}
			if (inVal <= ptr->data) {
				ptr->left = new Node<t>(inVal);
				//size++;
				//balance(root);

			}
			else {
				ptr->right = new Node<t>(inVal);
				//size++;
				//balance(root);
			}
		}

	}

	void fillarray(Node<t> myarray[], int& pos, Node<t>* myNode) { //Fills array to be sorted in ascending or descending
		if (myNode == nullptr) {
			return;
		}
		if (myNode->left != nullptr) {
			fillarray(myarray, pos, myNode->left);
			myarray[pos] = *(myNode->left);
			pos++;
		}
		if (myNode->data == root->data) {
			myarray[pos] = *myNode;
			pos++;
		}
		if (myNode->right != nullptr) {
			fillarray(myarray, pos, myNode->right);
			myarray[pos] = *(myNode->right);
			pos++;
		}
		return;
	}

	Node<t>* getAllAscending() { //Returns array of Nodes in ascending order
		Node<t>* ascendarray = new Node<t>[size];
		int pos = 0;
		fillarray(ascendarray, pos, root);
		for (int i = 0; i < size; i++) {
			pos = i;
			for (int c = i + 1; c < size; c++) {
				if (ascendarray[c].data < ascendarray[pos].data) {
					pos = c;
				}
			}
			Node<t> temp = ascendarray[pos];
			ascendarray[pos] = ascendarray[i];
			ascendarray[i] = temp;
		}
		return ascendarray;
	}

};