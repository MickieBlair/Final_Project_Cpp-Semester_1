// Mickie Blair
// CIST 2361 - CRN 63227
// Summer 2019 Final Project
// Part 2 - Selection Sort 
// A. String Selection Sort

#include <iostream>
#include <string>

using namespace std;

void selectionSort(string[], int);
void swap(string& a, string& b);
void displaySortedList(string[], int size);

int main()
{
	const int NUM_NAMES = 20;
	string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
								"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
								"Taylor, Terri", "Johnson, Jill",
								"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
								"James, Jean", "Weaver, Jim", "Pore, Bob",
								"Rutherford, Greg", "Javens, Renee",
								"Harrison, Rose", "Setzer, Cathy",
								"Pike, Gordon", "Holland, Beth" };


	//sort the list
	selectionSort(names, NUM_NAMES);

	//display the sorted list
	displaySortedList(names, NUM_NAMES);


	return 0;
}

//selection sort function

void selectionSort(string namesArray[], int size)
{
	int startScan;
	int minIndex;
	string minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = namesArray[startScan];

		for (int index = startScan + 1; index < size; index++)
		{
			if (namesArray[index] < minValue)
			{
				minValue = namesArray[index];
				minIndex = index;
			}
		}

		swap(namesArray[minIndex], namesArray[startScan]);
	}
}


//swap function
void swap(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

//display the sorted list
void displaySortedList(string namesArray[], int size)
{
	//display the sorted array
	cout << "\nSorted Names (Ascending Order)\n";

	//for loop for displaying
	for (int count = 0; count < size; count++)
	{
		cout << namesArray[count] << endl;
	}

	cout << endl;
}


