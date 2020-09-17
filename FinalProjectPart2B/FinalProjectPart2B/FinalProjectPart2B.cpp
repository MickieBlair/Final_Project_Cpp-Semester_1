// Mickie Blair
// CIST 2361 - CRN 63227
// Summer 2019 Final Project
// Part 2 - Selection Sort 
// B. Binary String Search

#include <iostream>
#include <string>

using namespace std;

void selectionSort(string[], int);
void swap(string& a, string& b);
void displaySortedList(string[], int size);
int binarySearch(string[], int, string);
string getUserSearchString();
void displaySearchResults(string, int);

int main()
{
	const int NUM_NAMES = 20;		//array size					
	string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
								"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
								"Taylor, Terri", "Johnson, Jill",
								"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
								"James, Jean", "Weaver, Jim", "Pore, Bob",
								"Rutherford, Greg", "Javens, Renee",
								"Harrison, Rose", "Setzer, Cathy",
								"Pike, Gordon", "Holland, Beth" }; //array of names
	
	int results;					//to hold the search results
	string searchString;			//to hold search value


	//sort the list
	selectionSort(names, NUM_NAMES);

	//display the sorted list
	displaySortedList(names, NUM_NAMES);

	//get user search value
	searchString = getUserSearchString();
	

	//search the array
	results = binarySearch(names, NUM_NAMES, searchString);


	//display the search result
	displaySearchResults(searchString, results);

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
		cout << (count + 1)<< ".  " << namesArray[count] << endl;
	}

	cout << endl;
}

string getUserSearchString()
{
	string input;
	cout << "Please enter the name you would like to search for:  ";
	getline(cin, input);

	return input;
}

int binarySearch(string namesArray[], int numElems, string value)
{
	int first = 0,                           // First array element
	    last = numElems - 1,                // Last array element
		middle,                              // Midpoint of search
		position = - 1;                       // Position of search value
	bool found = false;                      // Flag
	while (!found && first <= last)
	{
		middle = (first + last) / 2;         // Calculate midpoint
		if (namesArray[middle].compare(value)==0)     // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (namesArray[middle].compare(value) > 0)      // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;              // If value is in upper half
	}
	return position;
} 

//display search results
void displaySearchResults(string search, int searchResult)
{
	if (searchResult == -1)
		cout << search << " is not in list.\n";
	else
	{
		cout << endl;
		cout << search << " is number " << searchResult + 1 << " in the list\n";
		cout << "and is located in the array at element " << searchResult << ".\n";
	}
}


