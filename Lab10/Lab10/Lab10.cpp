// Lab10.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "HashTable.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include "ChainedHashtableh.h"

using namespace std;


void testFile(string names[]);
int main()
{
	srand(time(NULL));
	ifstream myfile("names.txt");
	int numLines = 0;
	string line;
	string * nameArray;
	if (!myfile) {
		cout << "Error reading file" << endl;
		system("pause");
		return -1;
	}
	while (getline(myfile, line)) {
		numLines++;
		//getline(myfile, line1[a], '\n');
	}
	myfile.clear();
	myfile.seekg(0, ios::beg);
	nameArray = new string[numLines];
	int count = 0;
	while (getline(myfile, nameArray[count], '\n')) {
		count++;
	}

	int index;
	long mnumber;
	string name;
	Student students[50];
	for (int i = 0; i< 50; i++)
	{
		index = rand() % numLines;
		mnumber = 10000000 + rand() % ((99999999 + 1) - 10000000);
		cout << "Mnumber " << mnumber << endl;
		name = nameArray[index];
		students[i].setName(name);
	}


	HashTable<Student> h(5);

	Student a("Mary", "M12345678");
	Student b("Bob", "M12345612");
	Student c("Jane", "M12345613");
	Student d("Kyle", "M12345614");
	Student e("Anna", "M12345615");
	Student f("Robert", "M12345633");
	h.addItem(&a);

	h.addItem(&b);

	h.addItem(&c);

	h.addItem(&d);

	h.addItem(&e);
	h.print();
	cout << endl;
	cout << "take out Anna from hash table" << endl;
	cout << *h.removeItem(e) << endl;
	cout << endl;
	cout << "new hash table" << endl;
	h.print();
	cout << endl;
	cout << "size: " << h.getLength() << endl;
	cout << endl;
	cout << "chained Hash Table stuff" << endl;
	ChainedHashtable<Student> ch;
	//ch.print();
	ch.addStuff(&f);
	ch.addStuff(&a);
	ch.addStuff(&b);
	ch.addStuff(&c);
	ch.addStuff(&d);
	ch.printList();
	ch.reverseList();
	ch.printList();

	system("PAUSE");
	delete[] nameArray;
	return 0;
}

void testFile(string names[])
{
	
	
}

