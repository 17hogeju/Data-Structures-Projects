#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Homework4/Buckets.h"
#include "../Homework4/LinearProbe.h"
#include "../Homework4/Buckets.cpp"
#include "../Homework4/LinearProbe.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		LinearProbe l;
		int numOperations = 0;
		TEST_METHOD(LPInsert)
		{
			// Case 1: insert into a blank spot
			numOperations = l.insert(1);
			Assert::AreEqual(numOperations, 1);

			// Case 2: insert into a filled spot
			numOperations = l.insert(1);
			Assert::AreEqual(numOperations, 2);
		}
		TEST_METHOD(LPFind) 
		{
			// Case 1: find a number in the list
			l.insert(1);
			numOperations = l.find(1);
			Assert::AreEqual(numOperations, 1);

			// Case 2: find a number not in the list
			numOperations = l.find(10);
			Assert::AreEqual(numOperations, 500);

		}
		TEST_METHOD(LPRemove)
		{
			// Case 1: remove a number that exists
			l.insert(1);
			numOperations = l.remove(1);
			Assert::AreEqual(numOperations, 1);

			// Case 2: remove a number that does not exist
			numOperations = l.remove(10);
			Assert::AreEqual(numOperations, 500);
		}

	};
}