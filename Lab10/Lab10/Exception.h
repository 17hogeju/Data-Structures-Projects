#pragma once
#pragma once
#include <string>

using namespace std;
class Exception {
public:
	Exception(const string& msg);
	string getMessage();
private:
	string message;
};