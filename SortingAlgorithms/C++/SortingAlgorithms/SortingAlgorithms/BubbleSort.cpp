#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(double *unsortedArray, int size);
void swap(double *num1, double *num2);
void printArray(double *array, int size);


int main() {
	// Create a stream to read file
	fstream dataInput;
	dataInput.open("unsortedFile.txt", ios::in);
	
	// Size of the array
	int size; 
	dataInput >> size;
	double *unsortedArray = new double[size];
	
	// after read size, it's neccessary to ignore the rest of that line to jump into next line
	dataInput.ignore(1000, '\n'); 
	
	// Contain the entire line
	char takenString[255];
	dataInput.getline(takenString, 1000, '\n');
	
	// default, don't care because it is not so much meaningful
	char* context = NULL; 
	char * token; // retain each element (token) that extracted from the taken string
	
	// get the first element delimited by space character (' ')
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

	cout << "Original Array : " << endl;
	printArray(unsortedArray, size);
	cout << "\n\nSorted Array (accending) : " << endl;
	bubbleSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}



// algorithm for Selection Sort
void bubbleSort(double *unsortedArray, int size) {
	for (int turn = 0; turn < size - 1; turn++) {
		for (int bubbleindex = 0; bubbleindex < size - 1 - turn; bubbleindex++) {
			if (unsortedArray[bubbleindex] > unsortedArray[bubbleindex + 1])
				swap(&unsortedArray[bubbleindex], &unsortedArray[bubbleindex + 1]);
		}
	}

	/*
	// may traverse the array as the following way
	for (int turn = size-1; turn > 0; turn--) {
		for (int bubbleIndex = 0; bubbleIndex < turn; bubbleIndex++) {
			if (unsortedArray[bubbleIndex] > unsortedArray[bubbleIndex + 1])
				swap(&unsortedArray[bubbleIndex], &unsortedArray[bubbleIndex + 1]);
		}
	}*/

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
