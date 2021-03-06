// Homework1.cpp

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Book
{
	string title; //this is the var for the title of the book (:
	string author;  //this is the var for the author
	string firstName; // this holds the first name of the author
	string lastName;// this holds the last name of the author
	int wordCount;//this is the int for the word count
	int letterFreq[26]; //this is the int array counting the letter frequencies
	int lineCount; //this is the int that count the lines
};

// Functions
string getLineFromFile(ifstream&);
string readTitle(ifstream&);
string readAuthor(ifstream&);
string getFirst(string);
string getLast(string);
int readWordCount(ifstream&);
int readLineCount(ifstream&);
//int countLetterFreq(ifstream&);

int main()
{
	ifstream fileIn; //this is the name of the file we are reading
	string fileInName; // this is what the user inputs as the file name
	Book newBook;
	string letterFreqChoice;
	string anotherBook;
	bool quit = false;
	ofstream cardCatolog;//this is the file that holds all of the information from the different books we are reading

	while (quit == false) {


		do{
			cout << "Enter file name with the format: name.txt" << endl;
			cin >> fileInName;
			fileIn.open(fileInName, ios::in | ios::out);

			if (fileIn.fail()) {
				cout << "Error: File does not exist" << endl;
			}
		} while (fileIn.fail());
			
		
		newBook.title = readTitle(fileIn);
		newBook.author = readAuthor(fileIn);
		newBook.firstName = getFirst(newBook.author);
		newBook.lastName = getLast(newBook.author);
		newBook.wordCount = readWordCount(fileIn);
		newBook.lineCount = readLineCount(fileIn);
		//newBook.letterFreq = countLetterFreq(fileIn);

		fstream cardCatalog("CardCatalog.txt", ios::out | ios::app);
		cardCatalog << "Title: " << newBook.title << endl;
		cardCatalog << "Full Author : " << newBook.author << endl;
		cardCatalog << "Author First Name : " << newBook.firstName << endl;
		cardCatalog << "Author Last Name : " << newBook.lastName << endl;
		cardCatalog << "Word Count : " << newBook.wordCount << endl;
		cardCatalog << "Line Count : " << newBook.lineCount << endl;
		cardCatalog << endl;

		cout << "Would you like to see the letter frequency ? (y / n)" << endl;
		cin >> letterFreqChoice;
		while (letterFreqChoice != "y" && letterFreqChoice != "n") {
			cout << "Enter a valid option(y / n)" << endl;
			cin >> letterFreqChoice;
		}
		if (letterFreqChoice.compare("y") == 0) {
			for (int i = 0; i <= 25; i++) {
				cout << static_cast<char>(97 + i) << ": " << 1 << "%" << endl;
				//cout << static_cast<char>(97 + i) << ": " << newBook.letterFreq[i] / findTotal(newBook.letterFreq) << " % " << endl;
			}
		}

		cout << "Would you like to process another book? (y / n)" << endl;
		cin >> anotherBook;
		while (anotherBook != "y" && anotherBook != "n") {
			cout << "Enter a valid option(y / n)" << endl;
			cin >> anotherBook;
		}
		if (anotherBook.compare("n") == 0) {
			cout << "Have a good day :)" << endl;
			quit = true;
		}
		fileIn.close();
	}
    return 0;
}

///////////////////////////////////////////////////////////////////////
// The purpose of this function is to count the amount of lines in   //
// a file. it used a while loop to do this. it receives a read only  //
// file. it will output a an integer                                 //
///////////////////////////////////////////////////////////////////////
int readLineCount(ifstream& file) //IN THEORY, THIS SHOULD WORK…:D//Emma
{
	string liney; //this string holds the contents of the line
	file.clear(); // this clears the curser position
	file.seekg(0, ios::beg); //this brings the curser to the beiging
							 // we did this to ensure we would not get lost in the file
							 //this way we know we are counting the corect amout of lines
	int lineCount = 0; //this is the integer that olds the amount of lines
	while (!file.eof()) {  // this while loop it askes as long as it is not the end of the file
		getline(file, liney, '\n'); // get the file just to move the cursur to the next line
		lineCount++;//add one to the current line count
	}
	return lineCount;//the out put is the line count the total of lines in the file
}

///////////////////////////////////////////////////////////////////////
// The purpose of this function is to stream line the process of     //
// accesing the line of a file and turn the line into a string. This //
// function is to be used in other functions not the main. the input //
// is a read only file. the output is a string                       //
///////////////////////////////////////////////////////////////////////
string getLineFromFile(ifstream& file)//Emma: I (Tom) made the adjustment of getting rid of the \n. getline doesnt need it.
{
	string liney; //this is a temp variablbe to hold the line info
	string gimmeLineFromFile;// the var to be permanetly hold the line info
	getline(file, liney);// gets the infor from a line and turns it into a string
	gimmeLineFromFile = liney;// give the line string to the permanent string
	return gimmeLineFromFile; // output the sting of the line from the file
}

string readTitle(ifstream& file) //Tom: returns string with the title
{
	// goes back to the start (Coldplay - The Scientist)
	file.clear();
	file.seekg(0, ios::beg);
	// create our string to hold title
	string line;
	//put the line in 'line'
	getline(file, line);
	//Check if there is a character here
	if (isalnum(line.at(1))) {
		//returns the string
		return line;
	}
}

string readAuthor(ifstream& file) //Tom: returns string with the author
{
	// goes back to the start (Coldplay - The Scientist)
	file.clear();
	file.seekg(0, ios::beg);

	// author is always on line 2. therefore, we use 'liney' to hold the title (line 1), while 'line' contains the author
	string liney;
	string line;

	// gets the first line (title) and saves it to 'liney'. No clue why this one works...

	getline(file, liney, '\n');
	//Check if there is a character here
	if (isalnum(liney.at(1))) {
		//takes the second line (author) and saves it to 'line'
		getline(file, line);
		// returns the string with author
		return line;
	}
}

string getFirst(string fName) // Julia Hoge
{
	int i = 0;
	for (i; i < fName.length(); i++) {
		if (isspace(fName[i])) {
			break;
		}
	}
	return fName.substr(0,i);
}

string getLast(string lName)
{
	int i = 0;
	for (i; i < lName.length(); i++) {
		if (isspace(lName[i])) {
			break;
		}
	}
	return lName.substr(i+1);
}

int readWordCount(ifstream& file) //Tom: goes through each line and retrieves the word count for each line.
{
	// goes back to the start (Coldplay - The Scientist)
	file.clear();
	file.seekg(0, ios::beg);
	//create our word count int and current string we read from
	int count = 0;
	string curr;
	//while loop depending on if we reach the end of the file
	while (!file.eof()) {
		//uses getLineFromFile to grab the next line from the file
		curr = getLineFromFile(file);
		// for loop going through the line
		for (int i = 0; i < curr.length(); i++) {   //if length doesn’t work try .size()
													// tests if there is a number or letter here
			if (isalnum(curr.at(i))) {
				//move on to the next character
			}
			else if (isspace(curr.at(i)) && !isspace(curr.at(i - 1))) {
				//if there is a space and the previous character was a number or letter, the word count increases
				count++;
			}
		}
	}
	return count;
}





