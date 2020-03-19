#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class word {
public:
	
	word()
	{
		words = "";
		count = 0;
	}
	word(string s, int c)
	{
		words = s;
		count = c;
	}
	bool operator >(word wc)
	{
		string c1 = this->words;
		string c2 = wc.words;
		if (c1 > c2)
		{
			return true;
		}
		else {
			return false;
		}
	}

	bool operator <(word wc){
	
		
		string c1 = this->words;
		string c2 = wc.words;
		if (c1 < c2)
		{
			return true;
		}
		else {
			return false;
		}
		
	}

	bool operator <=(word wc) {

		string c1 = this->words;
		string c2 = wc.words;
	
		if (c1 <= c2)
		{
			return true;
		}
		else {
			return false;
		}
	}

	bool operator >=(word wc) {

		string c1 = this->words;
		string c2 = wc.words;

		if (c1 >= c2)
		{
			return true;
		}
		else {
			return false;
		}
	}

	bool operator ==(word wc)
	{
		string c1 = this->words;
		string c2 = wc.words;
		if (c1 == c2) {
			return true;
		}
		else {
			return false;
		}
	}

	int count;
	string words;

};

