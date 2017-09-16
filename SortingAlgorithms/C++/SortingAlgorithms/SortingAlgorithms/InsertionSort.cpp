#include <iostream>
#include <fstream>

using namespace std;

void insertionSort(double *unsortedArray, int size);
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
	insertionSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}

// algorithm for Selection Sort
void insertionSort(double *unsortedArray, int size) {
	for (int turn = 1; turn < size; turn++) {
		double rememberedValue = unsortedArray[turn];
		int insertionIndex = turn;

		while (insertionIndex >= 1 && unsortedArray[insertionIndex - 1] > rememberedValue) {
			unsortedArray[insertionIndex] = unsortedArray[insertionIndex - 1];
			insertionIndex--;
		}
		unsortedArray[insertionIndex] = rememberedValue;

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
