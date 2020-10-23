/*
* Program Name: SortDr
* Created Date: 5/10/2018
* Created By: Justin Fonseca
* Purpose: to display sorting algorithm complexity
* Acknowledgments: Code from C++ Data Structures (Dale)
*/

// This program is a sorting algorithm tester.

// Input are sorting algorithm names plus Refresh for resetting the
//   values to be sorted to their previous values and Reinitialize for
//   creating a new set of values.
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
const int SIZE = 100;
const int SIZE2 = 1000; 
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"

using namespace std;
typedef int ItemType;

// SIZE should be a multiple of 10.

void Print(ofstream&, int[],int);	// Prints array
void CopyValues(int[], int[], int);	// Makes a copy of random array
void InitValues2(ifstream&, int[], int); //load array from file
//void InitValues3(int[]);
void Swap(ItemType& item1, ItemType& item2);

int main()
{
	//variable for holding
	int numHolder; 
	//input output files
	ifstream inFile;
	ifstream inFile2;// file containing operations
	ofstream outFile; // file containing output
	ofstream outFile2;
	    
	ItemType values[SIZE];
	ItemType values2[SIZE2];
	ItemType copyValues[SIZE];
	ItemType copyValues2[SIZE2];
	//create sorting objects
	SSort<int> mySSort; 
	Qsort<int> myQsort; 
	MSort<int> myMsort; 
	InsertSort<int> myISort; 
	HSort<int> myHsort;
	BSort<int> myBsort;
	 
	//open files for output input
	outFile.open("output3.txt");
	outFile2.open("output4.txt");
	inFile.open("input100.txt");

			
//1 0 0 INTEGER SECTION
			outFile << "100 Integers Sorting" << endl; 
			InitValues2(inFile, values, SIZE);
			CopyValues(values, copyValues, SIZE);
			
			//SELECTION SORT
			mySSort.ResetCounters();//reset counters
			mySSort.SelectionSort(values, SIZE - 1); //send items for sorting
			//output sorted items to file
			outFile2 << "Results from SelectionSort: " << endl;
			Print(outFile2, values,SIZE);
			outFile2 << endl;
			//output results of sort to main output file
			outFile << "Results from SelectionSort: ";
			numHolder = mySSort.SwapCounterP();
			outFile << "\n Swaps: " << numHolder << endl; 
			numHolder = mySSort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues, values, SIZE); //restore unsorted state
			
			//BubbleSort
			myBsort.ResetCounters();
	        myBsort.BubbleSort(values, SIZE - 1);
			//output sorted items to 2nd output file
			outFile2 << "Results from BubbleSort: " << endl;
			Print(outFile2, values,SIZE); //TEST LINE
			outFile2 << endl;
			//output sorting results to main file
			outFile << "Results from BubbleSort: " << endl;
			numHolder = myBsort.SwapCounterP();
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myBsort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues, values, SIZE);
			
			//Merge Sort
			myMsort.ResetCounters(); //reset counters
			myMsort.MergeSort(values, 0, SIZE - 1);//send item for sorting
			//output sorted items to second output file
			outFile2 << "Results from MergeSort: " << endl; 
			Print(outFile2, values,SIZE); 
			outFile2 << endl;
			//output sorting results to main output file
			outFile << "Results from MergeSort: " << endl;
			numHolder = myMsort.SwapCounterP();
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myMsort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues, values, SIZE); //restore unsorted state
		
			//QuickSort
			myQsort.ResetCounters(); //reset counters
			myQsort.QuickSort(values, 0, SIZE - 1); //send items to sort 
			//output sorted items to second output file
			outFile2 << "Results from QuickSort: " << endl;
			Print(outFile2, values,SIZE); //TEST LINE
			outFile2 << endl;
			//output sorting results to main output file
			outFile << "Results from QuickSort: " << endl;
			numHolder = myQsort.SwapCounterP(); //return # of swaps
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myQsort.CompCounterP(); //return # of comparison
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues, values, SIZE); //restore unsorted state
		
			//InsertionSort
			myISort.ResetCounters(); //reset counters
			myISort.InsertionSort(values, SIZE - 1); // send items to sort
			//output sorted items to second file
			outFile2 << "Results from InsertionSort: " << endl;
			Print(outFile2, values,SIZE); // 
			outFile2 << endl;
			//output sorting results to main output file
			outFile << "Results from InsertionSort: " << endl; 
			numHolder = myISort.SwapCounterP(); //return # of swaps
			outFile << "Swaps: " << numHolder << endl; //
			numHolder = myISort.CompCounterP(); //return #of comparisons
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues, values, SIZE); //restore to unsorted state
		
			//HeapSort
			myHsort.ResetCounters(); //reset counters
			myHsort.HeapSort(values, SIZE);//send items for sorting
			//output sorted items to second file
			outFile2 << "Results from HeapSort: " << endl;
			Print(outFile2, values,SIZE); //TEST LINE
			outFile2 << endl;
			//output sorting results to main output file
			outFile << "Results from HeapSort: " << endl;
			numHolder = myHsort.SwapCounterP(); //return swaps
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myHsort.CompCounterP(); //return comparisons
			outFile << "Comparisons: " << numHolder << endl; 
			CopyValues(copyValues, values, SIZE); //restore to unsorted state
			outFile << endl;
			outFile << endl;
		
			//outFile << endl << "Initial Values: " << endl; // testline
			//Print(outFile, values,SIZE); // testline
			inFile.close();
			
			
			
// 1 0 0 0 INTEGER SECTION
			//open second file
			inFile2.open("input1000.txt");
			//copy files to ItemType array
			InitValues2(inFile2, values2, SIZE2);
			//InitValues3(values2);
			CopyValues(values2, copyValues2, SIZE2);
			outFile << "1000 Integers Sorting" << endl;
			
			//SELECTION SORT  
			mySSort.ResetCounters(); //reset counters
			mySSort.SelectionSort(values2, SIZE2 - 1);
			//output sorted items to second output file
			outFile2 << "Results from SelectionSort: " << endl;
			Print(outFile2, values2, SIZE2);
			outFile2 << endl;
			//output sorting results to main file
			outFile << "Results from SelectionSort: " << endl;
			numHolder = mySSort.SwapCounterP();
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = mySSort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			//outFile << "Initial Values: " << endl; //TEST LINE
			CopyValues(copyValues2, values2, SIZE2);
			//TESTLINE Print(outFile, values2, SIZE2);
			
			//BUBBLE SORT //TESTED
			myBsort.ResetCounters();
			myBsort.BubbleSort(values2, SIZE2 - 1);
			outFile2 << "Results from BubbleSort: " << endl;
			Print(outFile2, values2, SIZE2); // TEST LINE
			outFile2 << endl; // TEST LINE
			//output sorting results to main file
			outFile << "Results from BubbleSort: " << endl;
			numHolder = myBsort.SwapCounterP();
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myBsort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			//outFile << "Initial Values: " << endl; //TEST LINE
			CopyValues(copyValues2, values2, SIZE2);
			//Print(outFile, values2, SIZE2); //TEST LINE
			
			
			//MERGE SORT //TESTED
			myMsort.ResetCounters();
			myMsort.MergeSort(values2, 0, SIZE2 - 1);
			//output sorted items to second output file
			outFile2 << "Results from MergeSort: \n"; 
			Print(outFile2, values2,SIZE2); //TEST LINE
			outFile2 << endl; // TEST LINE
			//output sorting results to main file
			outFile << "Results from MergeSort: \n";
			numHolder = myMsort.SwapCounterP();
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myMsort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues2, values2, SIZE*10);
			

			//QuickSort //TESTED
			myQsort.ResetCounters();
			myQsort.QuickSort(values2, 0, SIZE2 - 1);
			//output sorted items to second output file
			outFile2 << "Results from QuickSort: " << endl;
			Print(outFile2, values2, SIZE2); //TEST LINE
			outFile2 << endl; //TEST LINE
			//output sorting results to main output file
			outFile << "Results from QuickSort: " << endl;
			numHolder = myQsort.SwapCounterP();
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myQsort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues2, values2, SIZE*10); //restore to unsorted state
			
			//Insertion Sort
			//LAST ITEM IS NOT SORTED CORRECTLY
			myISort.ResetCounters();
			myISort.InsertionSort(values2, SIZE2 - 1);
			//output sorted items to second output file
			outFile2 << "Results from InsertionSort: " << endl;
			Print(outFile2, values2, SIZE*10); 
			outFile2 << endl;
			//output sorting results to main output file
			outFile << "Results from InsertionSort: " << endl;
			numHolder = myISort.SwapCounterP();
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myISort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues2, values2, SIZE*10);
			
			//HEAP SORT //TESTED
			myHsort.ResetCounters();
			myHsort.HeapSort(values2, SIZE2);
			//output sorted items to second output file
			outFile2 << "Results from HeapSort: " << endl;
			Print(outFile2, values2, SIZE*10); 
			outFile2 << endl;  
			//output sorting results to main output file
			outFile << "Results from HeapSort: " << endl;
			numHolder = myHsort.SwapCounterP();
			outFile << "Swaps: " << numHolder << endl; 
			numHolder = myHsort.CompCounterP();
			outFile << "Comparisons: " << numHolder << endl; 
			outFile << endl;
			CopyValues(copyValues2, values2, SIZE*10);
			

	

	
	inFile2.close();
	outFile.close();
	outFile2.close();
	return 0;
}

// functions 
/*
void InitValues3(int values[])
// initializes the values array with random integers from 0 to 99
{
	for (int index = 0; index < SIZE2; index++)
		values[index] = (std::rand() % 1000);
}
*/
void InitValues2(ifstream& inFile, int values[], int limit)
// initializes the values array with random integers
{ 
	while (inFile.good()) {
		for (int index = 0; index < limit; index++) {


			inFile >> values[index];

		}
	}
}

void Print(ofstream& outFile, int values[],int limit)
{
	using namespace std;
	for (int count = 0; count < limit; count = count + 10)
		outFile << values[count] << ", " << values[count + 1] << ", " << values[count + 2] << ", "
		<< values[count + 3] << ", " << values[count + 4] << ", " << values[count + 5] << ", "
		<< values[count + 6] << ", " << values[count + 7] << ", " << values[count + 8]
		<< ", " << values[count + 9] << endl << endl;

}


void Swap(ItemType& item1, ItemType& item2)
// Post: Contents of item1 and item2 have been swapped.
{
	ItemType tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}

void CopyValues(int inData[], int outData[], int limit)
{
	for (int count = 0; count < limit; count++)
		outData[count] = inData[count];
}
