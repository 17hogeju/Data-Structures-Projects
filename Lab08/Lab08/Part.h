#pragma once 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Part {
	public:
		
		Part(int pN, string d, double p, string uOM, int qOH = 0, int lT = 0);
		string getPartInfo() const;
		double getPrice();
		bool inStock();
		bool available();
		//overloaded functions for <, >, == that compare the part Number of two part Instances
		bool operator < (Part& a);
		bool operator > (Part& a);
		bool operator == (Part& a);
		friend ostream& operator<<(ostream& os,const Part& pt)  {
			os << std::fixed;
			os << std::setprecision(2);
			os << pt.partNumber << ": " << pt.quantityOnHand << " " << pt.unitOfMeasure << " $" << pt.price << " each";
			return os;
		}
		//geters
		

	private:
		int partNumber;
		string description;
		double price;
		string unitOfMeasure;
		int quantityOnHand;
		int leadTime;
		int month;
		int day;
		int year;
};