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

template <class t> class BST {
private:
	int size;
	Node<t>* root;
public:
	BST() { //default constructor
		root = nullptr;
		size = 0;
	}
	BST(Node<t>* myroot) {
		root = myroot;
		size = 1;
	}

	Node<t>* getroot() { //returns root (mostly for testing)
		return root;
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
				balance(root);

			}
			else {
				ptr->right = new Node<t>(inVal);
				size++;
				balance(root);
			}
		}

	}

	void test() { //For testing
		balance(root);
	}

	void balance(Node<t>*& myNode) { //Balances tree by calling rotateright or left based on heights
		if (myNode == nullptr) {
			return;
		}
		balance(myNode->right);
		balance(myNode->left);
		if ((height(myNode->right) - height(myNode->left)) > 1) {
			myNode = rotateLeft(myNode);
		}
		if ((height(myNode->left) - height(myNode->right)) > 1) {
			myNode = rotateRight(myNode);
		}
		return;
	}
	Node<t>* rotateLeft(Node<t>* parent) {
		Node<t>* tempR = parent->right;
		Node<t>* tempL = tempR->left;
		if (parent->right->left != nullptr) {
			Node<t>* temp = rotateRight(parent->right);
			parent->right = temp;
			tempR = rotateLeft(parent);

		}
		else {
			tempR->left = parent;
			parent->right = tempL;
		}
		return tempR;
	}
	Node<t>* rotateRight(Node<t>* parent) { //needs to be changed
		Node<t>* tempL = parent->left;
		Node<t>* tempR = tempL->right;
		if (parent->left->right != nullptr) {
			Node<t>* temp = rotateLeft(parent->left);
			parent->left = temp;
			tempL = rotateRight(parent);
		}
		else {
			tempL->right = parent;
			parent->left = tempR;
		}
		return tempL;

	}

	Node<t>* find(t val) {
		Node<t> * ptr = root;
		while (ptr != nullptr)
		{
			if (ptr->data > val)
			{
				ptr = ptr->left;
			}
			else if (ptr->data < val)
			{
				ptr = ptr->right;
			}
			else if (ptr->data == val)
			{
				return ptr;
			}
			else {
				return nullptr;
			}
		}
		return nullptr;

	}

	int getSize() { //returns size of tree
		return size;
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

	Node<t>* getAllDescending() { //Returns array of Nodes in descending order
		Node<t>* descendarray = new Node<t>[size];
		int pos = 0;
		fillarray(descendarray, pos, root);
		for (int i = 0; i < size; i++) {
			pos = i;
			for (int c = i + 1; c < size; c++) {
				if (descendarray[c].data > descendarray[pos].data) {
					pos = c;
				}
			}
			Node<t> temp = descendarray[pos];
			descendarray[pos] = descendarray[i];
			descendarray[i] = temp;
		}
		return descendarray;
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

	Node<t>* remove(t val) { //Removes a values Node from the array
		if (find(val) == nullptr) {
			return nullptr;
		}
		else {
			size--;
			Node<t>* tmp = find(val);
			Node<t>* tmppar = findparent(root, val);
			if (val == root->data) {
				//Rotate then repeat
				if (root->left == nullptr && root->right == nullptr) {
					tmp = root;
					delete root;
					return root;
				}
				else if (root->left != nullptr) {
					root = rotateleft(root);
					size++;
					remove(val);
				}
				else {
					root = rotateright(root);
					size++;
					remove(val);
				}
			}
			else if (tmp->left == nullptr && tmp->right == nullptr) {
				if (tmppar->left->data == tmp->data) {
					tmppar->left = nullptr;
					balance(root);
					delete tmp;
					return tmp;
				}
				else {
					tmppar->right = nullptr;
					balance(root);
					delete tmp;
					return tmp;
				}
			}
			else if (tmp->left == nullptr && tmp->right != nullptr) {
				if (tmppar->left->data == tmp->data) {
					tmppar->left = tmp->right;
					balance(root);
					delete tmp;
					return tmp;
				}
				else {
					tmppar->right = tmp->right;
					balance(root);
					delete tmp;
					return tmp;
				}
			}
			else if (tmp->left != nullptr && tmp->right == nullptr) {
				if (tmppar->left->data == tmp->data) {
					tmppar->left = tmp->left;
					balance(root);
					delete tmp;
					return tmp;
				}
				else {
					tmppar->right = tmp->left;
					balance(root);
					delete tmp;
					return tmp;
				}
			}

		}
	}

	Node<t>* findparent(Node<t>* myNode, int val) { //Finds parent of Node (used in deletion)
		if (myNode == nullptr) { //No Node
			return nullptr;
		}
		if (myNode->left == nullptr && myNode->right == nullptr) { //Only root in tree
			return nullptr;
		}
		if ((myNode->left != nullptr && myNode->left->data == val) || (myNode->right != nullptr && myNode->right->data == val)) { //Node is found
			return myNode;
		}
		if (myNode->data > val) {
			return findparent(myNode->left, val);
		}
		if (myNode->data < val) {
			return findparent(myNode->right, val);
		}
	}

	void emptytree() { //Empties tree without data leaks by calling recursive function (needed to use root)
		emptytreerec(root);
		size = 0;
	}

	void emptytreerec(Node<t>* myNode) { //Empties tree recursively
		if (myNode == nullptr) {
			return;
		}
		else {
			if (myNode->left != nullptr) {
				emptytreerec(myNode->left);
				myNode->left = nullptr;
			}
			if (myNode->right != nullptr) {
				emptytreerec(myNode->right);
				myNode->right = nullptr;
			}
			if (myNode->right == nullptr && myNode->left == nullptr) {
				delete myNode;
			}
		}
		return;
	}

	int height(Node<t>* myNode) { //Returns height of a given Node
		int lheight, rheight;
		if (myNode == nullptr) {
			return 0;
		}
		lheight = height(myNode->left);
		rheight = height(myNode->right);

		if (rheight > lheight) {
			return rheight + 1;
		}
		else {
			return lheight + 1;
		}
	}
};