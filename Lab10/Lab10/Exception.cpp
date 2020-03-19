#include "stdafx.h"
#include "Exception.h"


Exception::Exception(const string& msg) {
	message = msg;
}

string Exception::getMessage() {
	return message;
}