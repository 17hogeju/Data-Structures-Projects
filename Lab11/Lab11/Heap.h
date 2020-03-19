#pragma once
#include <iomanip>
#include <iostream>
#define COUNT 10

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

template <class t>
class Heap {
private:
	int size;
	Node<t>* root;
public:
	Heap() { //default constructor
		root = nullptr;
		size = 0;
	}
	Heap(Node<t>* myroot) {
		root = myroot;
		size = 1;
	}
	void insert(t inVal) {
		Node<t>* ptr = root;
		if (root == nullptr) {
			root = new Node<t>(inVal);
			size++;
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
				size++;
				//balance(root);

			}
			else {
				ptr->right = new Node<t>(inVal);
				size++;
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

	void print2DUtil(Node<t> *root, int space)
	{
		// Base case  
		if (root == NULL)
			return;

		// Increase distance between levels  
		space += COUNT;

		// Process right child first  
		print2DUtil(root->right, space);

		// Print current node after space  
		// count  
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << root->data << "\n";

		// Process left child  
		print2DUtil(root->left, space);
	}

	// Wrapper over print2DUtil()  
	void print2D(Node<t> *root)
	{
		// Pass initial space count as 0  
		print2DUtil(root, 0);
	}

	Node<t>* getroot() { //returns root (mostly for testing)
		return root;
	}

	void heapify(t arr[], int index) {
		int largest = index;
		int l = 2 * index + 1;
		int r = 2 * index + 2;

		if (l < ARRSIZE && arr[l] > arr[largest]) {
			largest = l;
		}
		if (r < ARRSIZE && arr[r] > arr[largest]) {
			largest = r;
		}
		if (largest != index) {
			t temp = arr[i];
			arr[i] = arr[largest];
			arr[largest] = temp;

			heapify(arr, largest);
		}
	}


};