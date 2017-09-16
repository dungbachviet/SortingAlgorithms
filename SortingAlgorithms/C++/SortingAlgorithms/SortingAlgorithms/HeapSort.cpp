#include <iostream>
#include <fstream>

using namespace std;

void updateHeapAt(double *heapedArray, int size, int updatedPosition);
void heapSort(double *unsortedArray, int size);
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
	heapSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}


void updateHeapAt(double *heapedArray, int size, int updatedPosition) {
	int largestIndex = updatedPosition; // index of the largest element
	int leftChildIndex = largestIndex * 2 + 1;
	int rightChildIndex = largestIndex * 2 + 2;
	// Check if the value of any one of its two children has larger than the largest value saved in the parent variable largestIndex 
	if (leftChildIndex < size && heapedArray[leftChildIndex] > heapedArray[largestIndex])
		largestIndex = leftChildIndex;
		
	if (rightChildIndex < size && heapedArray[rightChildIndex] > heapedArray[largestIndex])
		largestIndex = rightChildIndex;

	// if having no change in variable largestIndex, it stops and doesn't call the recursive function
	if (largestIndex != updatedPosition) {
		// when the largest value is at one of its two children, carry out the swap and update the heap at a lower level
		swap(&heapedArray[updatedPosition], &heapedArray[largestIndex]);
		updateHeapAt(heapedArray, size, largestIndex);
	}
}

void heapSort(double *unsortedArray, int size) {
	// build the new max heap from an unsorted array
	for (int buildHeapIndex = (size / 2) - 1; buildHeapIndex >= 0; buildHeapIndex--) {
		updateHeapAt(unsortedArray, size, buildHeapIndex);
	}

	// After creating the maximum heap, it is the high time for converting from the max heap to ascending sorted array
	for (int sizeOfUpdatedHeap = size - 1; sizeOfUpdatedHeap >= 1; sizeOfUpdatedHeap--) {
		// Swap between the first element and the last element in the heap to move gradually the largest element to the end of the array
		swap(&unsortedArray[0], &unsortedArray[sizeOfUpdatedHeap]);
		// After swapping the two elements above, it is necessary to update the remaining heap
		updateHeapAt(unsortedArray, sizeOfUpdatedHeap, 0);
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
