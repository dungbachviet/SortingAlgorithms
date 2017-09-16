#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void shellSort(double *unsortedArray, int size);
void printArray(double *array, int size);


int main() {

	int size = 5;
	double unsortedArray[] = { 12, 58.45, 12.5, 7.89, 66.6 };
	
	// display the original array and the sorted array
	cout << "Original Array : " << endl;
	printArray(unsortedArray, size);
	cout << "\n\nSorted Array (accending) : " << endl;
	shellSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}


void shellSort(double *unsortedArray, int size) {
	int interval = 1;
	int comparingIndex, currentIndex;
	double comparingValue;

	// Using Knuth's Formular to calculate the interval ( is initialized by 1)
	while (interval <= (size / 3)) {
		interval = interval * 3 + 1;
	}

	// 'Interval' specifies the distance in comparison. This algorithm's idea is similar to Insertion Algorithm, but with a specified distance for comparing
	while (interval > 0) {
		for (comparingIndex = interval; comparingIndex < size; comparingIndex++) {
			comparingValue = unsortedArray[comparingIndex];
			for (currentIndex = comparingIndex; currentIndex >= interval && unsortedArray[currentIndex - interval] > comparingValue; currentIndex -= interval) {
				unsortedArray[currentIndex] = unsortedArray[currentIndex - interval];
			}
			unsortedArray[currentIndex] = comparingValue;
		}
		// reduce the comparing distance until it equals to zero 
		interval = (interval - 1) / 3;
	}
}


// display array to screen
void printArray(double *array, int size) {
	for (int index = 0; index < size; index++) {
		cout << array[index] << " ";
	}
}
