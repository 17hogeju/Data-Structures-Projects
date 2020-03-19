#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;


template <class T>
struct AdjListNode
{
	T dest;
	struct AdjListNode<T>* next;
};

/*
 * Adjacency List
 */
template <class T>
struct AdjList
{
	struct AdjListNode<T> * head;
};


template <class T>
class Graph {

private:
	int V;
	int numEdges = 0;
	struct AdjList<T>* array;
public:
	Graph(int V = 10)
	{
		this->V = V;
		array = new AdjList<T>[V];

		for (int i = 0; i < V; ++i) {
			array[i].head = nullptr;
		}
	}
	~Graph() {
		AdjListNode<T>* curr;
		for (int i = 0; i < V; ++i) {
			curr = array[i].head;
			while (curr != nullptr && curr->next != nullptr) {
				AdjListNode<T>* nextNode = curr->next;
				delete curr;
				curr = nextNode;
			}
			delete curr;
		}
	}
	
	AdjListNode<T>* newAdjListNode(int dest)
	{
		AdjListNode<T>* newNode = new AdjListNode<T>;
		newNode->dest = dest;
		newNode->next = nullptr;
		return newNode;
	}
	

	void addEdge(T src, T dest)
	{
		if (hasEdge(src,dest) == false) { //If there isn't an edge here...
			AdjListNode<T>* newNode = newAdjListNode(dest); //Make a new "edge" object...
			newNode->next = array[src].head; //And assign its values to equal the points of the edge.
			array[src].head = newNode;
		}
		else { //If there is an edge here, tell the user and do nothing.
			cout << "Graph already has edge from " << src << " to " << dest << endl;
		}
		
	}

	void removeEdge(T src, T dest) {
		AdjListNode<T>* ptr = array[src].head;

		if (ptr == nullptr) {
			cout << "No edge from " << src << " to " << dest << endl;
			return;
		}
		if (ptr->dest == dest && ptr->next != nullptr) { //If head is the data to be deleted
			/* Copy the data of next node to head */
			ptr->dest = ptr->next->dest;

			// store address of next node  
			AdjListNode<T>* n = ptr->next;

			// Remove the link of next node  
			ptr->next = ptr->next->next;

			// free memory  
			delete n;
			return;
		}
		else if (ptr->dest == dest) {
			AdjListNode<T>* temp = array[src].head;
			array[src].head = NULL;
			delete temp;
			return;
		}
		else {
			AdjListNode<T>* prev = array[src].head;
			while (ptr->next != nullptr) {
				if (ptr->dest == dest) {
					/* Copy the data of next node to head */
					ptr->dest = ptr->next->dest;

					// store address of next node  
					AdjListNode<T>* n = ptr->next;

					// Remove the link of next node  
					ptr->next = ptr->next->next;

					// free memory  
					delete n;
					return;
				}
				if (ptr->next->next == nullptr) {
					prev = ptr;
				}
				ptr = ptr->next;
			}
			if (ptr->dest == dest) {
				prev->next = nullptr;
				delete ptr;
			}
			else {
				cout << "No edge from " << src << " to " << dest << endl;
			}

		}


	}
	bool hasEdge(T src, T dest) {
		AdjListNode<T>* ptr = array[src].head;
		while (ptr != nullptr) { //While the pointer exists, and it isn't indicative of an edge...
			if (ptr->dest == dest){//Check the next one.
				return true; //Found it!
			}
			ptr = ptr->next;
		}
		return false; //All possible edges were checked, but none were found, so return false.
	}


	T* outEdges(T myVal) { //Returns a list of out edges found with a given i value.
		if (array[myVal].head != nullptr) {
			AdjListNode<T>* tmp = array[myVal].head;
			int numVerts = numOutEdges(myVal);
			int* myVals = new int[numVerts]; 
			for (int i = 0; i < numVerts; i++) { //Iterates through the children of a given vertex
				myVals[i] = tmp->dest; //And adds them to the list.
				tmp = tmp->next;
			}
			return myVals;
		}
		else {
			return nullptr; //If none were found, return a nullptr.
		}
	}

	int numOutEdges(T myVal) { //Same as outedges, but instead of displaying which were found, it displays the count.
		AdjListNode<T>* tmp = array[myVal].head;
		if (tmp != nullptr) {
			int i = 0;
			while (tmp != nullptr) {
				i++;
				tmp = tmp->next;
			}
			return i;
		}
		else {
			return 0;
		}

	}

	int numInEdges(T myVal) { //Same as inedges, but instead of displaying which were found, it displays the count.
		AdjListNode<T>* tmp;
		int* myVals = new int[V];
		int index = 0;
		for (int i = 0; i < V; i++) {
			tmp = array[i].head;
			while (tmp != nullptr) {
				if (tmp->dest == myVal) {
					index++;
				}
				tmp = tmp->next;
			}
		}
		return index;
	}

	T* inEdges(T myVal) {//Returns a list of in edges found with a given j value.
		AdjListNode<T>* tmp;
		int* myVals = new int[V];
		int index = 0; //Start at 0
		for (int i = 0; i < V; i++) { //Checks all of the vertices to see if they have an edge with this j value (stored in myVal)
			tmp = array[i].head;
			while (tmp != nullptr) {
				if (tmp->dest == myVal) {
					myVals[index] = i;
					index++;
				}
				tmp = tmp->next;
			}
		}
		return myVals;
	}

	T* breadthSearch(T src) {
		Queue<T> vQueue(V);
		T* visitedList = new T[V]; //List to be returned
		bool* hasBeenVisited = new bool[V]; //List to see if a vertex has been checked
		string emptyError = "Your starting point is empty!";
		int verticesVisited = 0; //Tracks how many have been checked

		if (array[src].head == nullptr) { //If it's empty, throw error
			throw emptyError;
		}

		visitedList[0] = src;
		hasBeenVisited[src] = true;
		vQueue.enqueue(&src);

		while (!vQueue.isempty()) { //While there are vertices left to check...
			try
			{
				AdjListNode<T>* vertexCheck = array[*(vQueue.peek())].head; //In a connection between [2] and [4], this is [4]

				while (vertexCheck != nullptr) { //Go to the next connection unless it has already been visited, then skip again
					if (hasBeenVisited[vertexCheck->dest] != true) { //If the vertex wasn't previously visited, add it to the visited list and increment the count
						verticesVisited += 1;
						hasBeenVisited[vertexCheck->dest] = true;
						visitedList[verticesVisited] = vertexCheck->dest;
						vQueue.enqueue(&(vertexCheck->dest)); //Add it to the queue in order to check for children
					}
					vertexCheck = vertexCheck->next;
				}

				vQueue.dequeue(); //All of the children in this vertex have been checked, so we can remove it from our check list
			}
			catch (string err) {
				throw err;
			}
		}

		for (int i = verticesVisited+1; i < V; i++) { //Populate rest of the list with null values
			visitedList[i] = NULL;
		}

		return visitedList; //Return list of vertices visited!
	}

	T* depthSearch(T src) {
		Stack<T> vStack(V);
		T* visitedList = new T[V]; //List to be returned
		bool* hasBeenVisited = new bool[V]; //Tracks which vertices have been visited
		string emptyError = "Your starting point is empty!";
		int verticesVisited = 0; //Tracks how many have been visited

		if (array[src].head == nullptr) { //If empty, throw error
			throw emptyError;
		}

		visitedList[0] = src;
		hasBeenVisited[src] = true;
		vStack.push(&src); //Adds "head" to the related lists, as well as the stack

		while (!vStack.isempty()) { //While there are still nodes to check...
			try
			{
				AdjListNode<T>* vertexCheck = array[*(vStack.peek())].head; //In a connection between [2] and [4], this is [4]

				while (vertexCheck != nullptr && hasBeenVisited[vertexCheck->dest] == true) { //Go to the next connection unless it has already been visited, then skip again
					vertexCheck = vertexCheck->next;
				}

				if (vertexCheck == nullptr) { //This vertex has no more children, so we can remove it from the stack
					vStack.pop();
				}
				else {
					verticesVisited = verticesVisited + 1; //Increment number of vertices visited
					visitedList[verticesVisited] = vertexCheck->dest; //Add vertex to list
					hasBeenVisited[vertexCheck->dest] = true; //Mark vertex as visited
					vStack.push(&(vertexCheck->dest)); //Add next vertex to stack for checking
				}
			}
			catch (string err) {
				throw err;
			}
		}

		for (int i = verticesVisited + 1; i < V; i++) { //Populate the rest of the array with null values...
			visitedList[i] = NULL;
		}

		return visitedList; //Then return the array!
	}

	void printStuff()
	{
		int v;
		for (v = 0; v < V; ++v) //For each vertex...
		{
			AdjListNode<T>* pCrawl = array[v].head;
			cout << "\n Adjacency list of vertex " << v << "\n head "; //Mark which vertex we're displaying...
			while (pCrawl) //And iterate through its child nodes until we reach a nullptr, displaying which ones are children nodes along the way
			{
				cout << "-> " << pCrawl->dest;
				pCrawl = pCrawl->next;
			}
			cout << endl;
		}
	}
};