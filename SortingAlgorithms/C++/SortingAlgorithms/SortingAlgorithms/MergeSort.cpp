#include <iostream>
#include <fstream>

using namespace std;

void mergeSort(double *unsortedArray, int left, int right);
void merge(double *sortedArray, int left, int middle, int right);
void swap(double *num1, double *num2);
void printArray(double *array, int size);


int main() {
	fstream dataInput;

	// create a stream to read file
	dataInput.open("unsortedFile.txt", ios::in);
	
	// size of the array
	int size; 
	dataInput >> size;
	double *unsortedArray = new double[size];

	// after read size, it's neccessary to ignore the rest of that line to jump into next line
	dataInput.ignore(1000, '\n');

	// contain the entire line
	char takenString[255]; 
	dataInput.getline(takenString, 1000, '\n');
	
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
	double *unsortedArray = new double[size];
	for (int index = 0; index < size; index++) {
	dataInput >> unsortedArray[index];
	}
	*/
	dataInput.close();
	
	// display the original array and the sorted array
	cout << "Original Array : " << endl;
	printArray(unsortedArray, size);
	cout << "\n\nSorted Array (accending) : " << endl;
	mergeSort(unsortedArray, 0, size - 1);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}

// Recursive algorithm for Merge Sort
void mergeSort(double *unsortedArray, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		mergeSort(unsortedArray, left, middle);
		mergeSort(unsortedArray, middle + 1, right);
		merge(unsortedArray, left, middle, right);
	}
}

// Merge two sorted arrays into an root array
void merge(double *sortedArray, int left, int middle, int right) {
	int leftArraySize = middle - left + 1;
	int rightArraySize = right - middle;

	// dynamic memory allocation for two new arrays supporting merging progress
	double *leftArray = new double[leftArraySize];
	double *rightArray = new double[rightArraySize];
	
	for (int index = 0; index < leftArraySize; index++) {
		leftArray[index] = sortedArray[left + index];
	}

	for (int index = 0; index < rightArraySize; index++) {
		rightArray[index] = sortedArray[middle + 1 + index];
	}
	// after comparing each pair of elements, choose a smaller element and place it into proper position in the main array
	int leftArrayIndex = 0;
	int rightArrayIndex = 0;
	int mainArrayIndex = left;
	while ( (leftArrayIndex < leftArraySize) && (rightArrayIndex < rightArraySize) ) {
		if (leftArray[leftArrayIndex] < rightArray[rightArrayIndex]) {
			sortedArray[mainArrayIndex] = leftArray[leftArrayIndex];
			leftArrayIndex++;
		}
		else {
			sortedArray[mainArrayIndex] = rightArray[rightArrayIndex];
			rightArrayIndex++;
		}
		mainArrayIndex++;
	}
	// add remaining elements into the main array
	if (leftArrayIndex < leftArraySize) {
		for (int index = leftArrayIndex; index < leftArraySize; index++) {
			sortedArray[mainArrayIndex] = leftArray[index];
			mainArrayIndex++;
		}
	}

	if (rightArrayIndex < rightArraySize) {
		for (int index = rightArrayIndex; index < rightArraySize; index++) {
			sortedArray[mainArrayIndex] = rightArray[index];
			mainArrayIndex++;
		}
	}
	// freeing up memory when no longer using them any more
	delete [] leftArray;
	delete [] rightArray;
}


// swap two values
void swap(double *num1, double *num2) {
	double intermediateValue = *num1;
	*num1 = *num2;
	*num2 = intermediateValue;
}

// display array to screen
void printArray(double *array, int size) {
	for (int index = 0; index < size; index++) {
		cout << array[index] << " ";
	}
}
