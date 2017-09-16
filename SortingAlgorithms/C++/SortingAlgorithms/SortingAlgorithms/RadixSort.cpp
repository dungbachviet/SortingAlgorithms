#include <iostream>
#include <fstream>

using namespace std;

int maximum(int *unsortedArray, int size);
void countingSort(int *unsortedArray, int size, int divisionUnit);
void radixSort(int *unsortedArray, int size);
void printArray(int *displayedArray, int size);


int main() {
	fstream dataInput;

	// create a stream to read file
	dataInput.open("radixSort.txt", ios::in);
	
	// size of the array
	int size; 
	dataInput >> size;
	int *unsortedArray = new int[size];

	// after read size, it's neccessary to ignore the rest of that line to jump to next line
	dataInput.ignore(1000, '\n');

	// contain the entire line
	char takenString[200] = { '\0' };
	dataInput.getline(takenString, 200, '\n');
	
	// default, don't care because it is not  meaningful
	char* context = NULL;
	char * token; // retain each element (token) that extracted from the taken string

	// get the first element delimited by space character (" ")
	token = strtok_s(takenString, " ", &context); 
	for (int index = 0; index < size; index++) {
		unsortedArray[index] = atof(token);
		token = strtok_s(NULL, " ", &context); // continue to get next element delimited by space character (' ')
	}

	/*
	// Way 2 : It is an simple way to read data from the file (not general)
	dataInput >> size;
	int *unsortedArray = new int[size];
	for (int index = 0; index < size; index++) {
	dataInput >> unsortedArray[index];
	}
	*/
	dataInput.close();
	
	// display the original array and the sorted array
	cout << "Original Array : " << endl;
	printArray(unsortedArray, size);
	cout << "\n\nSorted Array (accending) : " << endl;
	radixSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}

int maximum(int *unsortedArray, int size) {
	int maximumValue = unsortedArray[0];
	for (int index = 1; index < size; index++) {
		if (maximumValue < unsortedArray[index])
			maximumValue = unsortedArray[index];
	}

	return maximumValue;
}

void countingSort(int *unsortedArray, int size, int divisionUnit) {
	int countingKeysArray[10] = { 0 };
	int *sortedArray = new int[size];
	int key;

	// Count the number of occurence of each key
	for (int index = 0; index < size; index++) {
		key = (unsortedArray[index] / divisionUnit) % 10;
		++countingKeysArray[key];
	}

	// Determine actual positions of all elements in the array
	for (int key = 1; key < 10; key++) {
		countingKeysArray[key] += countingKeysArray[key - 1];
	}
	
	// Create an new sorted array from the above array
	// Must go down from size - 1 to 0 because it helps to maintain
	//relative stability of the sorted array at the previous times
	for (int index = size - 1; index >= 0; index--) {
		key = (unsortedArray[index] / divisionUnit) % 10;
		sortedArray[countingKeysArray[key] - 1] = unsortedArray[index];
		--countingKeysArray[key];
	}

	// Save these sorted sequences to the original array 
	for (int index = 0; index < size; index++) {
		unsortedArray[index] = sortedArray[index];
	}
	delete [] sortedArray;
}
void radixSort(int *unsortedArray, int size) {
	// Find the maximum value in the unsorted array
	int maximumValue = maximum(unsortedArray, size);

	// Devoke the countingSort function for each division unit (1, 10, 100, 1000 ... | divisionUnit < maximumValue)
	for (int divisionUnit = 1; divisionUnit <= maximumValue; divisionUnit *= 10) {
		countingSort(unsortedArray, size, divisionUnit);
	}
}



// display array to screen
void printArray(int *displayedArray, int size) {
	for (int index = 0; index < size; index++) {
		cout << displayedArray[index] << " ";
	}
}
