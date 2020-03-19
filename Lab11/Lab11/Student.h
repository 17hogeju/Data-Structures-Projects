#pragma once
#include <string>

using namespace std;
class Student {
private:
	string firstName;
	string lastName;
	string id;
public:
	Student() {
		firstName = "";
		lastName = "";
		id = "";
	}
	Student(string n1, string n2, string i) {
		firstName = n1;
		lastName = n2;
		id = i;

	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	string getID()
	{
		return id;
	}
	void setFirstName(string n)
	{
		firstName = n;
	}
	void setLastName(string n)
	{
		lastName = n;
	}
	void printStudent()
	{
		cout << "first Name: " << firstName << " last name: " << lastName << endl << "id: " << id << endl;
	}
	void setID(string i)
	{
		id = i;
	}
	operator string() {
		//string ID = to_string(this->id);
		return this->id;
	}
	bool operator==(Student rh) {
		if (firstName == rh.firstName && id == rh.id && lastName == rh.lastName) {
			return true;
		}
		else {
			return false;
		}
	}



	bool operator!=(Student rh) {
		if (firstName == rh.firstName && id == rh.id && lastName == rh.lastName) {
			return false;
		}
		else {
			return true;
		}
	}

	friend ostream& operator<<(ostream& out, Student s) {
		out << "Name: " << s.firstName << " " << s.lastName << " ID: " << s.id;
		return out;
	}

};