// Lab11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define ARRSIZE 10
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include <chrono>
#include <map>
#include <string> 
#include <iostream>
#include "Student.h"
#include "LL.h"

typedef chrono::high_resolution_clock Clock;

using namespace std;



Student randomStudent();
int max(int x, int y);
using namespace std;
template <class T>
void bubbleSort(T arr[], int arrSize);
template <class T>
void insertionSort(T arr[], int arrSize);
void merge(int myarray[], int left, int middle, int right);
void mergeSort(int myarray[], int size);
void mergerec(int myarray[], int left, int right);
template <class T>
void quickrec(T myarray[], int size, int left, int right);
template <class T>
void quickSort(T myarray[], int size);
template <class T>
void heapSort(T arr[]);
template <class T>
void heapify(T arr[], int size, int index);
template <class T>
void countingSort(T arr[]);
template <class T>
void radixSort(T arr[]);
template <class T>
int getMax(T arr[]);

int main()
{
	srand(time(NULL));
	int testArray[ARRSIZE];
	int testArray2[ARRSIZE];
	int testArray3[ARRSIZE];
	int testArray4[ARRSIZE];
	int testArray5[ARRSIZE];
	int testArray6[ARRSIZE];
	int testArray7[ARRSIZE];
	int one = 0;
	long two= 0;
	long three= 0;
	int four= 0;
	int five= 0;
	int six= 0;
	int seven= 0;
	
	//cout << endl;

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < ARRSIZE; i++) {
			testArray[i] = rand() % (2 * ARRSIZE);
			testArray2[i] = testArray[i];
			testArray3[i] = testArray[i];
			testArray4[i] = testArray[i];
			testArray5[i] = testArray[i];
			testArray6[i] = testArray[i];
			testArray7[i] = testArray[i];
			//cout << testArray[i] << endl;
		}

		auto t1 = Clock::now();
		bubbleSort(testArray, ARRSIZE);
		auto t2 = Clock::now();
		insertionSort(testArray2, ARRSIZE);
		auto t3 = Clock::now();
		mergeSort(testArray3, ARRSIZE);
		auto t4 = Clock::now();
		quickSort(testArray4,ARRSIZE);
		auto t5 = Clock::now();
		heapSort(testArray5);
		auto t6 = Clock::now();
		countingSort(testArray6);
		auto t7 = Clock::now();
		radixSort(testArray7);
		auto t8 = Clock::now();

		//cout << "bubbleSort:    " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
		one += chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
		//cout << "insertionSort: " << chrono::duration_cast<chrono::nanoseconds>(t3 - t2).count() << " nanoseconds" << std::endl;
		two += chrono::duration_cast<chrono::nanoseconds>(t3 - t2).count();
		//cout << "mergeSort:     " << chrono::duration_cast<chrono::nanoseconds>(t4 - t3).count() << " nanoseconds" << std::endl;
		three += chrono::duration_cast<chrono::nanoseconds>(t4 - t3).count();
		//cout << "quickSort:     " << chrono::duration_cast<chrono::nanoseconds>(t5 - t4).count() << " nanoseconds" << std::endl;
		four += chrono::duration_cast<chrono::nanoseconds>(t5 - t4).count();
		//cout << "heapSort:      " << chrono::duration_cast<chrono::nanoseconds>(t6 - t5).count() << " nanoseconds" << std::endl;
		five += chrono::duration_cast<chrono::nanoseconds>(t6 - t5).count();
		//cout << "countingSort:  " << chrono::duration_cast<chrono::nanoseconds>(t7 - t6).count() << " nanoseconds" << std::endl;
		six += chrono::duration_cast<chrono::nanoseconds>(t7 - t6).count();
		//cout << "radixSort:     " << chrono::duration_cast<chrono::nanoseconds>(t8 - t7).count() << " nanoseconds" << std::endl;
		seven += chrono::duration_cast<chrono::nanoseconds>(t8 - t7).count();
		//cout << endl;

	}
	long temp = two / 10;
	cout << "BubbleSort Avg: " << one / 10 << endl;
	cout << "InsertionSort Avg: " << temp << endl;
	cout << "MergeSort Avg: " << three / 10 << endl;
	cout << "QuickSort Avg: " << four / 10 << endl;
	cout << "HeapSort Avg: " << five / 10 << endl;
	cout << "CountingSort Avg: " << six / 10 << endl;
	cout << "RadixSort Avg: " << seven / 10 << endl;
	
	
	bool goAgain = true;
	while (goAgain) {
		LL<Student> sLL;//student linked list
		string sArr[50];//string array
		//while statement creating random students
		int x = 0;
		Student toInset[50];
		while (x < 50)
		{
			toInset[x] = randomStudent();
			toInset[x].printStudent();
			//LL<Student> temp = LL<Student>(toInset.getFirstName(), toInset.getLastName(), toInset.getID());
			sLL.addItem(&toInset[x]);
			x++;
		}
		//sLL.printList();
		int sortBy;
		int sorttype;
		int order;
		//string sortingArr[50];
		cout << "would you like to sort by " << endl << "(1) first Name" << endl << "(2) last name" << endl << "(3) M number?" << endl;
		cin >> sortBy;
		//switch statement
		cout << "would you like to sort using" << endl << "(1) bubble sort" << endl << "(2) quick sort" << endl << "(3) insertion sort" << endl;
		cin >> sorttype;
		cout << "select sorting type(1: ascending, 2: descending): ";
		cin >> order;
		//switch statement
		switch (sortBy)
		{
		case 1:
			for (int i = 0; i < 50; i++)
			{
				sArr[i] = sLL.seeAt(i)->getFirstName();
				//cout << "sarr: " << sArr[i] << endl;
			}
			if (sorttype == 1)
			{
				bubbleSort(sArr, 50);
			}
			else if (sorttype == 2)
			{

				quickSort(sArr,50);
			}
			else
			{
				insertionSort(sArr, 50);
			}
			break;
		case 2:
			for (int i = 0; i < 50; i++)
			{
				sArr[i] = sLL.seeAt(i)->getLastName();
			}
			if (sorttype == 1)
			{
				bubbleSort(sArr, 50);
			}
			else if (sorttype == 2)
			{
				quickSort(sArr, 50);
			}
			else
			{
				insertionSort(sArr, 50);
			}
			break;
		case 3:
			for (int i = 0; i < 50; i++)
			{
				sArr[i] = sLL.seeAt(i)->getID();
			}
			if (sorttype == 1)
			{
				bubbleSort(sArr, 50);
			}
			else if (sorttype == 2)
			{
				quickSort(sArr,50);
			}
			else
			{
				insertionSort(sArr, 50);
			}
			break;
		default:
			break;
		}
		if (order == 1) {
			for (int i = 0; i < 50; i++) {
				cout << sArr[i] << endl;
			}
		}
		else {
			for (int i = 49; i >= 0; i--) {
				cout << sArr[i] << endl;
			}
		}
		
		int again = 0;
		cout << "want to run program again?" << endl << "(1) yes, (2) no" << endl;
		cin >> again;
		if (again == 1)
		{
			goAgain = true;
		}
		else
		{
			goAgain = false;
		}


	}
	system("PAUSE");

	return 0;
}

template <class T>
void heapSort(T arr[]){

	for (int i = ARRSIZE / 2 - 1; i >= 0; i--) {
		heapify(arr, ARRSIZE, i);
	}
	for (int i = ARRSIZE - 1; i >= 0; i--) {
		T temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		heapify(arr, i, 0);

	}
	
}


template <class T>
void heapify(T arr[], int size, int index) {
	int largest = index;
	int l = 2 * index + 1;
	int r = 2 * index + 2;

	if (l < size && arr[l] > arr[largest]) {
		largest = l;
	}
	if (r < size && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != index) {
		T temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;

		heapify(arr, size, largest);
	}
}

template <class T>
void countingSort(T arr[]) {
	int max = getMax(arr) + 1;
	int* numOccurrences = new int[max] {0};
	int* runningSum = new int[max] {0};
	T newArray[ARRSIZE];
	int sum = 0;
	for (int i = 0; i < ARRSIZE; i++) {
		++numOccurrences[arr[i]];
	}
	for (int i = 0; i < max; i++) {
		sum = sum + numOccurrences[i];
		runningSum[i] = sum;
	}
	for (int i = ARRSIZE - 1; i >= 0;i--) {
		runningSum[arr[i]] -= 1;
		newArray[runningSum[arr[i]]] = arr[i];
	}
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = newArray[i];
	}
	
	delete [] numOccurrences;
	delete [] runningSum;
}

template <class T>
int getMax(T arr[])
{
	int mx = arr[0];
	for (int i = 1; i < ARRSIZE; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

template <class T>
void radixSort(T arr[]) {
	T newArr[ARRSIZE];
	int max = getMax(arr) + 1; // find out how big of an array is needed to accomadate numbers up to max
	int sum = 0;
	int n = (to_string(getMax(arr))).length(); // get number of digits for number of iterations
	int index = 0;
	
	for (int k = 1; k < pow(10,n); k*=10) { 
		int* numOccurrences = new int[max] {0}; // Must be reinstantiated/ cleared out after each pass
		int* runningSum = new int[max] {0};

		for (int i = 0; i < ARRSIZE; i++) {
			index = (arr[i] / k) % 10;
			++numOccurrences[index];
		}

		for (int i = 0; i < max; i++) {
			sum = sum + numOccurrences[i];
			runningSum[i] = sum;
		
		}
		for (int i = ARRSIZE - 1; i >= 0; i--) {
			
			index = (arr[i] / k) % 10;
			runningSum[index] -= 1;
			newArr[runningSum[index]] = arr[i];
		}
		for (int i = 0; i < ARRSIZE; i++) {
			arr[i] = newArr[i]; 
		}
		delete[] numOccurrences;
		delete[] runningSum;
		sum = 0;
	}
	
}

template <class T>
void bubbleSort(T arr[], int arrSize)
{
	T temp;
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < (arrSize - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	/*cout << "bubble sort" << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << arr[i] << endl;
	}*/
	
}

template <class T>
void insertionSort(T arr[], int arrSize)
{
	T temp;
	for (int i = 0; i < arrSize; i++) {
		int j = i;

		while (j > 0 && arr[j] < arr[j - 1]) {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
	/*cout << "insertion sort" << endl;
	for (int i = 0; i < 50; i++)
	{
		cout <<"test: "<< arr[i] << endl;
	}*/
	
}

//MERGE SORT STARTS
void merge(int myarray[], int left, int middle, int right) {

	if (left >= right) {
		return;
	}

	int* leftarray = new int[middle - left + 1]; //Create array of left values

	for (int i = 0; i < middle - left + 1; i++) { //Copy values over
		leftarray[i] = myarray[left + i];
	}

	int* rightarray = new int[right - (middle)]; //Create array of right values

	for (int i = 0; i < right - middle; i++) { //Copy values over
		rightarray[i] = myarray[middle + 1 + i];
	}

	int leftpos = 0;
	int rightpos = 0;
	int myarraypos = left;

	while (leftpos < middle - left + 1 && rightpos < right - middle) { //While neither is finished
		if (leftarray[leftpos] < rightarray[rightpos]) {
			myarray[myarraypos] = leftarray[leftpos];
			leftpos++;
			myarraypos++;
		}
		else {
			myarray[myarraypos] = rightarray[rightpos];
			rightpos++;
			myarraypos++;
		}
	}

	if (leftpos < middle - left + 1) { //If right ended first
		while (leftpos < middle - left + 1) {
			myarray[myarraypos] = leftarray[leftpos];
			leftpos++;
			myarraypos++;
		}
	}
	if (rightpos < right - middle) { //If left ended first
		while (rightpos < right - middle) {
			myarray[myarraypos] = rightarray[rightpos];
			rightpos++;
			myarraypos++;
		}
	}

	return;
}

void mergerec(int myarray[], int left, int right) {
	if (left >= right) {
		return;
	}
	int pos = left + ((right - left) / 2); //pos acts as the middle of the array
	mergerec(myarray, left, pos);
	mergerec(myarray, pos + 1, right);

	merge(myarray, left, pos, right);
}

void mergeSort(int myarray[], int size) {
	mergerec(myarray, 0, size - 1); //Calls recursion
}
//MERGE SORT ENDS
int max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

//QUICK SORT STARTS
template <class T>
void quickrec(T myarray[], int size, int left, int right) {

	if (left >= right || right < 0 || left < 0) { //Condition to end recursion
		return;
	}

	int pivotpos = right; //Always pivots from right most value
	int wall = left - 1;

	for (int i = left; i < right; i++) { //Puts values that are less than pivot on the left of the "wall"
		if (myarray[i] < myarray[pivotpos]) {
			T temp = myarray[i];
			myarray[i] = myarray[wall + 1];
			myarray[wall + 1] = temp;
			wall++;
		}
	}

	T temp = myarray[pivotpos];
	myarray[pivotpos] = myarray[wall + 1];
	myarray[wall + 1] = temp;
	wall++; //Wall is now the pivot

	quickrec(myarray, size, left, wall - 1); //Sorts the left of the wall
	quickrec(myarray, size, wall + 1, right); //Sorts the right of the wall

}

template <class T>
void quickSort(T myarray[], int size) {
	quickrec(myarray, size, 0, size - 1);
}
//QUICK SORT ENDS

Student randomStudent()
{
	Student rando;// = new Student();
	static const char alphanum[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	static const char nums[] = "0123456789";
	int lenOfID[8];
	//string* IDs;
	//v2 = rand() % 100 + 1;
	int lenOfFirstNames[5];
	int lenOfLastNames[10];
	//string* names;
	string newFirstName = "";
	string newLastName = "";
	string newID = "M";
	for (int x = 0; x < 8; x++)
	{
		lenOfID[x] = nums[rand() % (sizeof(nums) - 1)];
		newID += lenOfID[x];
	}
	for (int k = 0; k < 5; k++)
	{
		lenOfFirstNames[k] = alphanum[rand() % (sizeof(alphanum) - 1)];
		newFirstName += lenOfFirstNames[k];
	}
	for (int k = 0; k < 10; k++)
	{
		lenOfLastNames[k] = alphanum[rand() % (sizeof(alphanum) - 1)];
		newLastName += lenOfLastNames[k];
	}
	rando.setID(newID);
	rando.setFirstName(newFirstName);
	rando.setLastName(newLastName);
	newID = "M";
	newFirstName = "";
	newLastName = "";
	//}
	return rando;
}


