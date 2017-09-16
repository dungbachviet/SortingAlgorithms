#include <iostream>
#include <fstream>

using namespace std;

void selectionSort(double *unsortedArray, int size);
void swap(double *num1, double *num2);
void printArray(double *array, int size);


int main() {

	fstream dataInput; // create a stream to read file
	dataInput.open("unsortedFile.txt", ios::in);
	int size; // size of the array
	dataInput >> size;
	dataInput.ignore(1000, '\n'); // after read size, it's neccessary to ignore the rest of that line to jump into next line
	double *unsortedArray = new double[size];

	char takenString[255]; // contain the entire line
	dataInput.getline(takenString, 1000, '\n');
	char* context = NULL; // default, don't care because it is not so much meaningful
	char * token; // retain each element (token) that extracted from the taken string
	token = strtok_s(takenString, " ", &context); // get the first element delimited by space character (' ')
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

	cout << "Original Array : " << endl;
	printArray(unsortedArray, size);
	cout << "\n\nSorted Array (accending) : " << endl;
	selectionSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}

// algorithm for Selection Sort
void selectionSort(double *unsortedArray, int size) {
	for (int index = 0; index < size - 1; index++) {
		int minIndex = index;
		for (int findMinIndex = index + 1; findMinIndex < size; findMinIndex++) {
			if (unsortedArray[findMinIndex] < unsortedArray[minIndex])
				minIndex = findMinIndex;
		}	
		swap(&unsortedArray[minIndex], &unsortedArray[index]);
	}
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
