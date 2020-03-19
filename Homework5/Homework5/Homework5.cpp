#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
	Graph<int> giraffe(10);

	int cont = 0;
	int inpt1 = 0;
	int inpt2 = 0;
	int vert = 10;

	cout << "WELCOME TO GRAPH WORLD\n";
	while (cont != 9) { //While the user still wants to operate on the graph...
		cout << "Press 1 to add an edge to graph.\n"; //Display these options...
		cout << "Press 2 remove an edge from graph.\n";
		cout << "Press 3 Find an edge in the graph.\n";
		cout << "Press 4 Find the out edges of a vertex.\n";
		cout << "Press 5 Find the in edges of a vertex.\n";
		cout << "Press 6 to do a depth search of the graph." << endl;
		cout << "Press 7 to do a breadth search of the graph." << endl;
		cout << "Press 8 to print.\n";
		cout << "Press 9 to quit.\n";
		cout << "Choice: ";
		cin >> cont; //And take in user input corresponding to these inputs.
		while (cont < 1 || cont > 9) {
			cout << "Enter a valid option (1-9).\n";
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> cont;
		}
		switch (cont) { //Switch case set up...
		case 1: //Where the cases are the user input.
		{
			cout << "i: "; //Takes in a valid i and j...
			cin >> inpt1;
			while (cin.fail() || inpt1 >= vert || inpt1 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "i: ";
				cin >> inpt1;
			}
			cout << "j: ";
			cin >> inpt2;
			while (cin.fail() || inpt2 >= vert || inpt2 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "j: ";
				cin >> inpt2;
			}

			giraffe.addEdge(inpt1, inpt2); //And creates an edge! The class displays errors on its own for this.
			break;
		}
		case 2:
		{
			cout << "i: "; //Takes in a valid i and j...
			cin >> inpt1;
			while (cin.fail() || inpt1 >= vert || inpt1 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "i: ";
				cin >> inpt1;
			}
			cout << "j: ";
			cin >> inpt2;
			while (cin.fail() || inpt2 >= vert || inpt2 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "j: ";
				cin >> inpt2;
			}

			giraffe.removeEdge(inpt1, inpt2); //And removes an edge! The class displays errors on its own for this.
			break;
		}
		case 3:
		{
			cout << "i: "; //Takes in a valid i and j...
			cin >> inpt1;
			while (cin.fail() || inpt1 >= vert || inpt1 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "i: ";
				cin >> inpt1;
			}
			cout << "j: ";
			cin >> inpt2;
			while (cin.fail() || inpt2 >= vert || inpt2 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "j: ";
				cin >> inpt2;
			}
			bool response = giraffe.hasEdge(inpt1, inpt2); //And checks for an edge!
			if (response) {
				cout << "There is an edge from " << inpt1 << " to " << inpt2 << endl; //If an edge exists, say so.
			}
			else {
				cout << "There is not an edge from " << inpt1 << " to " << inpt2 << endl; //Otherwise, tell the user.
			}
			break;
		}
		case 4:
		{
			cout << "i: "; //Enter a valid i...
			cin >> inpt1;
			while (cin.fail() || inpt1 >= vert || inpt1 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "i: ";
				cin >> inpt1;
			}
			int* myEdges = giraffe.outEdges(inpt1); //And find the number of out edges.
			int numVals = giraffe.numOutEdges(inpt1);
			if (numVals == 0) { //If there are none, tell the user.
				cout << "No out edges\n";
			}
			else {
				cout << "Out edges: "; //Otherwise...
			}
			for (int i = 0; i < numVals; i++) { //Iterate through the out edges and display them to the user.
				if (i == numVals - 1) {
					cout << myEdges[i] << endl;
				}
				else {
					cout << myEdges[i] << ", ";
				}

			}

			cout << endl;

			break;
		}
		case 5:
		{
			cout << "j: "; //Enter a valid j...
			cin >> inpt1;
			while (cin.fail() || inpt1 >= vert || inpt1 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "j: ";
				cin >> inpt1;
			}
			int* myEdges = giraffe.inEdges(inpt1); //And check for in edges.
			int numVals = giraffe.numInEdges(inpt1);
			if (numVals == 0) {
				cout << "No in edges." << endl;  //If there are none, tell the user.
			}
			else {
				cout << "In edges: "; //Otherwise...
			}
			for (int i = 0; i < numVals; i++) { //Iterate through the out edges and display them to the user.
				if (i == numVals - 1) {
					cout << myEdges[i] << endl;
				}
				else {
					cout << myEdges[i] << ", ";
				}

			}

			cout << endl;

			break;
		}
		case 6:
		{
			cout << "i: "; //Enter a valid i...
			cin >> inpt1;
			while (cin.fail() || inpt1 >= vert || inpt1 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "i: ";
				cin >> inpt1;
			}

			cout << "Initiating depth-first search starting at specified head node..." << endl; //Tells the user what they're doing.

			try //Unless there's an error...
			{
				int* searchOrder = giraffe.depthSearch(inpt1); //This performs a depth search on the given vertex...

				cout << "Searched in the following order: ";
				for (int i = 0; i < 10; i++) { //And displays the order in which they were searched.
					if (searchOrder[i] == NULL) break; //Once a NULL is hit, there are no more vertices that were searched, so end the loop.

					cout << searchOrder[i] << " ";
				}
				cout << endl;
			}
			catch (string err) { //However, if an error DID occur, throw it into the output for the user.
				cout << err << endl; //This usually occurs if the search was attempted on an empty node.
			}

			break;
		}
		case 7:
		{
			cout << "i: "; //Enter a valid i...
			cin >> inpt1;
			while (cin.fail() || inpt1 >= vert || inpt1 < 0) {
				cout << "Enter a valid response.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "i: ";
				cin >> inpt1;
			}

			cout << "Initiating breadth-first search starting at specified head node..." << endl; //Tells the user what they're doing.

			try //Unless there's an error...
			{
				int* searchOrder = giraffe.breadthSearch(inpt1); //This performs a breadth search on the given vertex...

				cout << "Searched in the following order: ";
				for (int i = 0; i < 10; i++) { //And displays the order in which they were searched.
					if (searchOrder[i] == NULL) break; //Once a NULL is hit, there are no more vertices that were searched, so end the loop.

					cout << searchOrder[i] << " ";
				}
				cout << endl;
			}
			catch (string err) { //However, if an error DID occur, throw it into the output for the user.
				cout << err << endl; //This usually occurs if the search was attempted on an empty node.
			}

			break;
		}
		case 8:
			giraffe.printStuff(); //Prints the graph out to the user in a readable format.
			break;
		case 9:
			cout << "Thanks for using this program.\n"; //Tells the user the program is about to end. Actually ends at the beginning of the next iteration.
			break;
		}

	}
	return 0;
}