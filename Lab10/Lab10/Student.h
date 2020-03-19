#pragma once
#include <string>

using namespace std;
class Student {
private:
	string name;
	string id;
public:
	Student() {
		name = "Mary";
		id = "M12345678";
	}
	Student(string n, string i) {
		name = n;
		id = i;

	}
	string getName() 
	{
		return name;
	}
	string getID()
	{
		return id;
	}
	void setName(string n) 
	{
		name = n;
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
		if (name == rh.name && id == rh.id) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(Student rh) {
		if (name == rh.name && id == rh.id) {
			return false;
		}
		else {
			return true;
		}
	}

	friend ostream& operator<<(ostream& out, Student s) {
		out << "Name: " << s.name << " ID: " << s.id;
		return out;
	}

};