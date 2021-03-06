// Lab09.cpp : Defines the entry point for the console application.
//

#include "stdafx.h""
#include "BST.h"
#include <iostream>
#include "word.h"
#include <string>
#include <fstream>
#include <vector> 
using namespace std;

int main()
{

	ifstream textFile;
	string file;
	BST<word> wordTree;
	cout << "Enter filename: " << endl;
	cin >> file;
	cout << endl;
	textFile.open(file, ios::in | ios::out);

	//ifstream read(textFile.c_str());
	if (!textFile)
	{
		cout << "Error, can't open file" << endl;
		exit(1);
	}
	else
	{
		textFile.clear();
		textFile.seekg(0, textFile.beg);
		vector<string> stringArray;
		string curr;
		int c = 0;
		string newStr;
		while (textFile >> newStr) 
		{
			stringArray.push_back(newStr);
			c++;
			
		}
		for (int i = 0; i < c; i++)
		{
			
			word newWord;
			newWord.words = stringArray[i];
			newWord.count = 1;//word(stringArray[i], 1);
			Node<word> * checkedNode = wordTree.find(newWord);
			if (checkedNode == nullptr)
			{
				wordTree.insert(newWord);
			}
			else
			{
				
				checkedNode->data.count = checkedNode->data.count + 1;
			}
			

		}
	}
	
	string ans = "";
	cout << "do you want to search for a word?(Y/N): ";
	cin >> ans;
	if (ans.compare("Y") == 0)
	{
		string findWord = "";
		cout << "input word to search";
		cin >> findWord;
		word fn;
		fn.words = findWord;
		Node<word> * checkedNode = wordTree.find(fn);
		if (checkedNode == nullptr)
		{
			cout << "could not find " << findWord << " in the tree" << endl;
		}
		else
		{
			cout << findWord << " showes up " << checkedNode->data.count << " times" << endl;
		}
		//Node<word> * checkedNode = wordTree.find(newWord);
	}
	cout << endl;
	Node<word> * accend = wordTree.getAllAscending();
	for (int a = 0; a< wordTree.getSize(); a++)
	{
		word newOut = (accend[a].data);
		//newOut->words = accend[a];
		string outWord = newOut.words;
		int outCount = newOut.count;
		cout << outWord << ": " << outCount << endl;
	}
	cout << endl;
	Node<word> * decend = wordTree.getAllDescending();
	for (int a = 0; a < wordTree.getSize(); a++)
	{
		word newOut1 = (decend[a].data);
		//newOut->words = accend[a];
		string outWord1 = newOut1.words;
		int outCount1 = newOut1.count;
		cout << outWord1 << ": " << outCount1 << endl;
	}
	return 0;
}

