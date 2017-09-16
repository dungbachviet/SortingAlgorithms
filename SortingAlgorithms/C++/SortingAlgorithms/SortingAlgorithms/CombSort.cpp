#include <iostream>
#include <fstream>


using namespace std;

void combSort(double *unsortedArray, int size);
int getNextGap(int gap);
void swap(double *num1, double *num2);
void printArray(double *array, int size);


int main() {

	int size = 5;
	double unsortedArray[] = { 12, 58.45, 12.5, 7.89, 66.6 };
	
	// display the original array and the sorted array
	cout << "Original Array : " << endl;
	printArray(unsortedArray, size);
	cout << "\n\nSorted Array (accending) : " << endl;
	combSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}


void combSort(double *unsortedArray, int size) {
	int startingPointOfGap = size; // means first point of sequences is compared
	bool hasSwapped = true; // keep track of an array until it is sorted ascendingly (means have not any swapping in the array comparison process)
	// when 2 conditions occur simultaneously : 
	//not have any swapping ( means the arrays has been sorted successfully) 
	// and startingPointOfGap == 1 (this condition can not ignore, when this variable equals to 1, it will waits hasSwapped variable until that variable equals to false to stop while loop)
	while (startingPointOfGap != 1 || hasSwapped == true) {
		startingPointOfGap = getNextGap(startingPointOfGap); // shrink gradually the gap
		hasSwapped = false;
		for (int comparingIndex = startingPointOfGap; comparingIndex < size; comparingIndex++) {
			if (unsortedArray[comparingIndex] < unsortedArray[comparingIndex - startingPointOfGap]) {
				swap(&unsortedArray[comparingIndex], &unsortedArray[comparingIndex - startingPointOfGap]);
				hasSwapped = true;
			}
		}

	}

}

int getNextGap(int gap) {
	// The gap will be shinked by the following formular (based on practical experience)
	gap = (gap * 10) / 13;
	if (gap < 1)
		return 1;
	return gap;
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
