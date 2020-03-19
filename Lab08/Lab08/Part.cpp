#include "stdafx.h"
#include "Part.h"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

/*Part::Part()
{
	partNumber = 0;
	description = "";
	price = 0.0;
	unitOfMeasure = "";
	quantityOnHand = 0;
	leadTime = 0;
	month = 1;
	day = 1;
	year = 2000;
}*/



Part::Part(int pN, string d, double p, string uOM, int qOH, int lT)
{
	partNumber = pN;
	description = d;
	price = p;
	unitOfMeasure = uOM;
	quantityOnHand = qOH;
	leadTime = lT;
}



string Part::getPartInfo() const
{
	string out = to_string(partNumber) + ": " + description;
	return out;
}
double Part::getPrice()
{
	return price;
}
bool Part::inStock()
{
	return quantityOnHand > 0;
}
bool Part::available()
{
	
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int m1 = 1 + newtime.tm_mon;
	int d1 = newtime.tm_mday;
	int y1 = newtime.tm_year + 1900;

	cout << "M: " << m1 << "d: " << d1 << "y: " << y1 << endl;


	if (quantityOnHand > 0)
	{
		return true;
	}
	else
	{
		switch (m1)
		{
		case 1:
			if (month == 1 && (day + leadTime) > 31)
			{
				month++;
				day = 31 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 2:
			if (month == 2 && (day + leadTime) > 28)
			{
				month++;
				day = 28 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 3:
			if (month == 3 && (day + leadTime) > 31)
			{
				month++;
				day = 31 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 4:
			if (month == 4 && (day + leadTime) > 30)
			{
				month++;
				day = 30 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 5:
			if (month == 5 && (day + leadTime) > 31)
			{
				month++;
				day = 31 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 6:
			if (month == 6 && (day + leadTime) > 30)
			{
				month++;
				day = 30 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 7:
			if (month == 7 && (day + leadTime) > 31)
			{
				month++;
				day = 31 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 8:
			if (month == 8 && (day + leadTime) > 31)
			{
				month++;
				day = 31 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 9:
			if (month == 9 && (day + leadTime) > 30)
			{
				month++;
				day = 30 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 10:
			if (month == 10 && (day + leadTime) > 31)
			{
				month++;
				day = 31 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 11:
			if (month == 11 && (day + leadTime) > 30)
			{
				month++;
				day = 30 - (day + leadTime);
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1)
			{
				return true;
			}
			else
			{
				return false;
			}
		case 12:
			if (month == 12 && (day + leadTime) > 31)
			{
				month = 0;
				day = 31 - (day + leadTime);
				year++;
			}
			else
			{
				day = (day + leadTime);
			}
			if (year <= y1)
			{
				return true;
			}
			else if(month == m1 && day < d1)
			{
				return true;
			}
			else if(month < m1 && year <= y1)
			{

				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
//overloaded functions for <, >, == that compare the part Number of two part Instances
bool Part::operator < (Part& a)
{
	if (a.partNumber > this->partNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Part::operator > (Part& a)
{
	if (a.partNumber < this->partNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Part::operator == (Part& a)
{
	if (a.partNumber == this->partNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
