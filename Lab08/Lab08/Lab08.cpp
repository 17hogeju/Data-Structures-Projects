// Lab08.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LL.h"
#include "Node.h"
#include "Part.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void welcome();
int outputChoices();
void callAdd(LL<Part> &l);
void callGet(LL<Part> &l);
void callIsInList(LL<Part> &l);
void callSeeAt(LL<Part> &l);





int main()
{
	LL<Part> list;
	bool quit = false;
	int choice;

	welcome();
	while (quit == false) {
		choice = outputChoices();
		switch (choice) {
		case 1: { //addItem
			callAdd(list);
			break;
		}
		case 2: { //getitem
			callGet(list);
			break;
		}
		case 3: { //is in list
			callIsInList(list);
			break;
		}
		case 4: { // Is empty
			if (list.isEmpty()) {
				cout << "List is empty." << endl;
			}
			else {
				cout << "List is not empty." << endl;
			}
			break;
			
		}
		case 5: { // size
			cout << "Size of list: " << list.size() << endl;
			break;
		}
		case 6: { // See next
			try {
				cout << *list.seeNext() << endl;
			}
			catch (Exception& ex) {
				cout << "You threw an exception: " << ex.getMessage() << endl;
			}
			break;

		}
		case 7: { // See at
			try {
				callSeeAt(list);
			}
			catch (Exception& ex) {
				cout << "You threw an exception: " << ex.getMessage() << endl;
			}
			break;

		}
		case 8: { //reset
			cout << "Location reset to 0" << endl;
			list.reset();
			break;
		}
		case 9: { //quit
			try {
				list.printList();
			}
			catch (Exception& ex) {
				cout << "You threw an exception: " << ex.getMessage() << endl;
			}
			break;
		}
		case 10: { //quit
			cout << "Thanks for using this program" << endl;
			quit = true;
			break;
		}
		case 11: {
			list.reverseList();
			break;
		}
		}
		cout << endl;
	}

    return 0;
}

void welcome() {
	cout << " _     _       _            _     __  _     _     _   " << endl;
	cout << "| |   (_)_ __ | | _____  __| |    \\ \\| |   (_)___| |_ " << endl;
	cout << "| |   | | '_ \\| |/ / _ \\/ _` |_____\\ \\ |   | / __| __|" << endl;
	cout << "| |___| | | | |   <  __/ (_| |_____/ / |___| \\__ \\ |_ " << endl;
	cout << "|_____|_|_| |_|_|\\_\\___|\\__,_|    /_/|_____|_|___/\\__|" << endl;
	cout << endl;
}

int outputChoices() {
	int choice;
	
	cout << "AddItem  (1)" << endl;
	cout << "GetItem  (2)" << endl;
	cout << "IsInList (3)" << endl;
	cout << "IsEmpty  (4)" << endl;
	cout << "Size     (5)" << endl;
	cout << "SeeNext  (6)" << endl;
	cout << "SeeAt    (7)" << endl;
	cout << "Reset    (8)" << endl;
	cout << "Print    (9)" << endl;
	cout << "Quit     (10)" << endl;
	cout << "Reverse  (11)" << endl;
	cout << "Choose which operation you would like to perform: ";
	while (!(cin >> choice) || choice > 11 || choice < 1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "bad input, try again" << endl;

	}
	return choice;

}

void callAdd(LL<Part> &l) {
	int partNum;
	string name;
	double price;
	string units;
	int qoh;
	char yn;
	cout << "Enter the part number: ";
	while (!(cin >> partNum)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "bad input, try again" << endl;
	}
	cout << "Enter the name of the part: ";
	cin.ignore(1000, '\n');
	getline(cin, name);
	cout << "Enter the price of the part: ";
	while (!(cin >> price)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "bad input, try again" << endl;
	}
	cout << "Enter the units of the part: ";
	while (!(cin >> units)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "bad input, try again" << endl;
	}
	cout << "Would you like to enter the quantity on hand(y/n): ";
	cin >> yn;
	while ((toupper(yn) != 'Y' && toupper(yn) != 'N')) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "bad input, try again" << endl;
		cin >> yn;
	}
	if (toupper(yn) == 'Y') {
		cout << "Enter the quantity on hand: ";
			while (!(cin >> qoh)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "bad input, try again" << endl;
			}

			Part p(partNum, name, price, units, qoh);
			Part* a = new Part(p);
			l.addItem(a);
	}
	else {
		Part p(partNum, name, price, units);
		Part* a = new Part(p);
		l.addItem(a);
	}
}

void callGet(LL<Part> &l) {
	int pn;
	
	cout << "Enter the part number of the item you wish to get: ";
	while (!(cin >> pn)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "bad input, try again" << endl;
	}
	Part t(pn, "", 0.0, "");
	Part * temp = new Part(t);
	if (l.isInList(temp)) {
		cout << *l.getItem(temp) << endl;
	}
	else {
		cout << "Item does not exist" << endl;
	} 


}

void callIsInList(LL<Part> &l) {
	int pn;

	cout << "Enter the part number of the item you wish to find: ";
	while (!(cin >> pn)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "bad input, try again" << endl;
	}
	Part t(pn, "", 0.0, "");
	Part * temp = new Part(t);
	if (l.isInList(temp)) {
		cout << "Part: " << pn << " is in the list." << endl;
	}
	else {
		cout << "Part: " << pn << " is not in the list." << endl;
	}
}

void callSeeAt(LL<Part> &l) {
	int locationNum;
	if (l.isEmpty()) {
		throw Exception("Empty List");
	}
	cout << "Enter the location number 0-" << (l.size()-1) << " : " ;
	while (!(cin >> locationNum)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "bad input, try again" << endl;
	}

	cout << *l.seeAt(locationNum) << endl;
}


