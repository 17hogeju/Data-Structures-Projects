// Lab03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComplexNums.h"
#include <stdio.h>
#include <limits>
#include <sstream>
#include <iostream>
#include <string>
#include <math.h>

ComplexNums::ComplexNums(double x, double a, bool c) {
	xVal = x;
	aVal = a;
	isCart = c;
}
ComplexNums::ComplexNums() {
	xVal = 0;
	aVal = 0;
	isCart = 0;
}

double ComplexNums::getAVal() { return aVal; }
bool ComplexNums::getIsCart() { return isCart; }
double ComplexNums::getXVal() { return xVal; }

void ComplexNums::setAVal(double a) { aVal = a; }
void ComplexNums::setIsCart(bool c) { isCart = c;}
void ComplexNums::setXVal(double x) { xVal = x;}


double enterValues(string n);
bool enterBool();
int enterOperation();
ComplexNums doOperation(int o, ComplexNums n, ComplexNums m, bool& isEqual);


int main()
{
	double x;
	double y;
	bool isCartesian;
	double a;
	double b;
	int o;
	bool isEqual;
	bool KeepPlaying = 1;
	while (KeepPlaying) {
		// User input
		isCartesian = enterBool(); // Prompts user for cartesian or polar type
		cout << endl;
		if (isCartesian == 1) {
			x = enterValues("real");
			a = enterValues("imaginary");
		}
		else {
			x = enterValues("R");
			cout << "(Rad) ";
			a = enterValues("Phi");
		}
		cout << endl;
		o = enterOperation();
		cout << endl;
		if (isCartesian == 1) {
			y = enterValues("real");
			b = enterValues("imaginary");
			while (y == 0 && o == 4 && b == 0) {
				cout << "divide by zero error" << endl;
				y = enterValues("R");
			}
		}
		else {
			y = enterValues("R");
			cout << "(Rad) ";
			b = enterValues("Phi");
			while (y == 0 && o == 4 && b == 0) {
				cout << "divide by zero error" << endl;
				y = enterValues("R");
			}
		}

		// Calculations
		ComplexNums n(x, a, isCartesian);
		ComplexNums m(y, b, isCartesian);
		n.setXVal(x);
		n.setAVal(a);
		m.setXVal(y);
		m.setAVal(b);


		ComplexNums answer = doOperation(o, n, m, isEqual);

		answer.printVal(o, isCartesian, isEqual, n, m);

		cout << "Would you like to continue?(1 = yes | 0 = no): ";
		cin >> KeepPlaying;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Incorrect type. Please try again." << endl;
			cout << "Would you like to continue?(1 = yes | 0 = no): ";
			cin >> KeepPlaying;
		}
	}
	

    return 0;
}

ComplexNums ComplexNums::operator +(ComplexNums& l) {
	ComplexNums answer;
	double x1, x2, a1, a2;
	if (isCart) { // If in Cartesian form
		answer.setXVal(this->xVal + l.getXVal());
		answer.setAVal(this->aVal + l.getAVal());
	}
	else { // If in Polar form
		x1 = this->xVal*(cos(aVal)); // gets real component
		a1 = this->xVal*(sin(aVal)); // gets imaginary compnent
		x2 = l.getXVal()*(cos(l.getAVal()));
		a2 = l.getXVal()*(sin(l.getAVal()));
		answer.setXVal(x1 + x2);
		answer.setAVal(a1 + a2);
	}

	return answer;
}
ComplexNums ComplexNums::operator -(ComplexNums& l) {
	ComplexNums answer;
	double x1, x2, a1, a2;
	if (isCart) { // If in Cartesian form
		answer.setXVal(this->xVal - l.getXVal());
		answer.setAVal(this->aVal - l.getAVal());
	}
	else { // If in Polar form
		x1 = this->xVal*(cos(aVal)); // gets real component
		a1 = this->xVal*(sin(aVal)); // gets imaginary compnent
		x2 = l.getXVal()*(cos(l.getAVal()));
		a2 = l.getXVal()*(sin(l.getAVal()));
		answer.setXVal(x1 - x2);
		answer.setAVal(a1 - a2);
	}
	return answer;

}
ComplexNums ComplexNums::operator *(ComplexNums& l) {
	ComplexNums answer;
	double a1, r1, a2, r2, angle, radius;
	
	if (isCart) {// If in Cartesian form
		r1 = this->getR();
		a1 = this->getPhi();
		r2 = l.getR();
		a2 = l.getPhi();

		angle = a1 + a2;
		radius = r1 * r2;
		
		answer.setXVal(radius*cos(angle));
		answer.setAVal(radius*sin(angle));

	}
	else {// If in Polar form
		r1 = this->xVal;
		a1 = this->aVal;
		r2 = l.getXVal();
		a2 = l.getAVal();

		angle = a1 + a2;
		radius = r1 * r2;
		answer.setXVal(radius);
		answer.setAVal(angle);

	}


	return answer;

}
ComplexNums ComplexNums::operator /(ComplexNums& l) {
	ComplexNums answer;
	double a1, r1, a2, r2, angle, radius;

	if (isCart) {// If in Cartesian form
		r1 = this->getR();
		a1 = this->getPhi();
		r2 = l.getR();
		a2 = l.getPhi();

		angle = a1 - a2;
		radius = r1 / r2;

		answer.setXVal(radius*cos(angle));
		answer.setAVal(radius*sin(angle));

	}
	else {// If in Polar form
		r1 = this->xVal;
		a1 = this->aVal;
		r2 = l.getXVal();
		a2 = l.getAVal();

		angle = a1 - a2;
		radius = r1 / r2;
		answer.setXVal(radius);
		answer.setAVal(angle);

	}
	return answer;

}
bool ComplexNums::operator ==(ComplexNums& l) {
	if ((l.getXVal() == this->xVal) && (l.getAVal() == this->aVal)) {
		return true;
	}
	else {
		return false;
	}
}
void ComplexNums::printVal(int n, bool c, bool isEqual, ComplexNums n1, ComplexNums m1)
{
	if (c == true && n != 5) {
		switch (n) {
		case 1: // Addition
			cout << "(" << n1.getXVal() << " + " << n1.getAVal() << "i) + (" << m1.getXVal() << " + " << m1.getAVal() << "i) = " << xVal << " + " << aVal << "i" << endl;
			break;
		case 2: // Subtraction
			cout << "(" << n1.getXVal() << " + " << n1.getAVal() << "i) - (" << m1.getXVal() << " + " << m1.getAVal() << "i) = " << xVal << " + " << aVal << "i" << endl;
			break;
		case 3: // Multiplication
			cout << "(" << n1.getXVal() << " + " << n1.getAVal() << "i) * (" << m1.getXVal() << " + " << m1.getAVal() << "i) = " << xVal << " + " << aVal << "i" << endl;
			break;
		case 4: // Division
			cout << "(" << n1.getXVal() << " + " << n1.getAVal() << "i) / (" << m1.getXVal() << " + " << m1.getAVal() << "i) = " << xVal << " + " << aVal << "i" << endl;
			break;
		}

	}
	else if (c == false && n != 5) {
		switch (n) {
		case 1: // Addition
			cout << n1.getXVal() << "(cos(" << n1.getAVal() << ") + isin(" << n1.getAVal() << ")) + " << m1.getXVal() << "(cos(" << m1.getAVal() << ") + isin(" << m1.getAVal() << ")) = " << xVal << "(cos(" << aVal << ") + isin(" << aVal << "))" << endl;
			break;
		case 2: // Subtraction
			cout << n1.getXVal() << "(cos(" << n1.getAVal() << ") + isin(" << n1.getAVal() << ")) - " << m1.getXVal() << "(cos(" << m1.getAVal() << ") + isin(" << m1.getAVal() << ")) = " << xVal << "(cos(" << aVal << ") + isin(" << aVal << "))" << endl;
			break;
		case 3: // Multiplication
			cout << n1.getXVal() << "(cos(" << n1.getAVal() << ") + isin(" << n1.getAVal() << ")) * " << m1.getXVal() << "(cos(" << m1.getAVal() << ") + isin(" << m1.getAVal() << ")) = " << xVal << "(cos(" << aVal << ") + isin(" << aVal << "))" << endl;
			break;
		case 4: // Division
			cout << n1.getXVal() << "(cos(" << n1.getAVal() << ") + isin(" << n1.getAVal() << ")) / " << m1.getXVal() << "(cos(" << m1.getAVal() << ") + isin(" << m1.getAVal() << ")) = " << xVal << "(cos(" << aVal << ") + isin(" << aVal << "))" << endl;
			break;
		}

	}
	else {
		if (isEqual) {
			cout << "The values are equivalent." << endl;
		}
		else {
			cout << "The values are not equivalent." << endl;
		}
	}
}
double ComplexNums::getPhi() {
	return atan(aVal/xVal);
}
double ComplexNums::getR() {
	return sqrt(pow(xVal, 2) + pow(aVal, 2));
}

bool enterBool() {
	string s;
	bool b;
	cout << "Enter a c or p for cartesian or polar: ";
	cin >> s;
	while (cin.fail() || (s.compare("c") != 0 && s.compare("p") != 0)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Incorrect. Please try again." << endl;
		cout << "Enter a c or p for cartesian or polar: ";
		cin >> s;
	}
	if (s.compare("c") == 0) {
		return true;
	}
	else
		return false;
}
double enterValues(string n) {
	double val;
	if (n.compare("imaginary") == 0) {
		cout << "Enter a " << n << " value (excluding i): ";
	}
	else {
		cout << "Enter a " << n << " value: ";
	}
	cin >> val;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Incorrect type. Please try again." << endl;
		cout << "Enter a " << n << " value: ";
		cin >> val;
	}
	return val;
}
int enterOperation() {
	int val;
	cout << "1: +" << endl;
	cout << "2: -" << endl;
	cout << "3: *" << endl;
	cout << "4: /" << endl;
	cout << "5: ==" << endl;
	cout << "Enter a number for the operation you would like: ";
	cin >> val;
	while (cin.fail() || val > 5 || val < 1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Incorrect. Please try again." << endl;
		cout << "1: +" << endl;
		cout << "2: -" << endl;
		cout << "3: *" << endl;
		cout << "4: /" << endl;
		cout << "5: ==" << endl;
		cout << "Enter a number for the operation you would like: ";
		cin >> val;
	}
	return val;

}
ComplexNums doOperation(int o, ComplexNums n, ComplexNums m, bool& isEqual) {
	ComplexNums ans;
	switch (o) {
	case 1: // Addition
		ans = n + m;
		return ans;
		break;
	case 2: // Subtraction
		ans = n - m;
		return ans;
		break;
	case 3: // Multiplication
		ans = n * m;
		return ans;
		break;
	case 4: // Division
		ans = n / m;
		return ans;
		break;
	case 5: // Equals sign
		if (n == m) {
			isEqual = true;
		}
		else{
			isEqual = false;
		}

		return	n;
		break;
	}
}



