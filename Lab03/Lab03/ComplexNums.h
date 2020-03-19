#pragma once
// Class header for ComplexNums class
#include <iostream>
using namespace std;

class ComplexNums {
public:
	ComplexNums();
	ComplexNums(double x, double a, bool c); // For form x + ai ** y + bi
	double getAVal();						 // Or form x<a ** y<b
	void setAVal(double a);
	void printVal(int n, bool c, bool isEqual, ComplexNums n1, ComplexNums m1);
	bool getIsCart();
	double getXVal();
	void setXVal(double x);
	void setIsCart(bool c);
	double getPhi();
	double getR();


	ComplexNums operator +(ComplexNums& l);
	ComplexNums operator -(ComplexNums& l);
	ComplexNums operator *(ComplexNums& l);
	ComplexNums operator /(ComplexNums& l);
	bool operator ==(ComplexNums& l);

	


private:
	double aVal;
	double xVal;
	bool isCart;

};