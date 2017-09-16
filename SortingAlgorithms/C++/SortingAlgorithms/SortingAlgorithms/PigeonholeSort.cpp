#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

void pigeonHoleSort(int *unsortedArray, int size);
void printArray(int *array, int size);


int main() {

	int size = 5;
	int unsortedArray[] = { 20, 50, 30, 100, 80 };
	
	// display the original array and the sorted array
	cout << "Original Array : " << endl;
	printArray(unsortedArray, size);
	cout << "\n\nSorted Array (accending) : " << endl;
	pigeonHoleSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}


void pigeonHoleSort(int *unsortedArray, int size) {
	// Find the maximum and minimum in the original array
	int maxValue = unsortedArray[0], minValue = unsortedArray[0];
	for (int index = 0; index < size; index++) {
		if (maxValue < unsortedArray[index]) 
			maxValue = unsortedArray[index];		
		if (minValue > unsortedArray[index]) 
			minValue = unsortedArray[index];		
	}

	// Calculate the maximum range as following formular 
	int range = maxValue - minValue + 1;
	vector<int> *holes = new vector<int>[range]; // create new holes to put the birds there
	int pigeonValue;
	// put birds into proper cages
	for (int pigeonIndex = 0; pigeonIndex < size; pigeonIndex++) {
		pigeonValue = unsortedArray[pigeonIndex];
		holes[pigeonValue - minValue].push_back(pigeonValue);
	}
	// From the pigeon cages, put those pigeons into original array ascendingly 
	int originalArrayIndex = 0;
	for (int holeIndex = 0; holeIndex < range; holeIndex++) {
		vector<int>::iterator insideHolePointer;
		for (insideHolePointer = holes[holeIndex].begin(); insideHolePointer != holes[holeIndex].end(); ++insideHolePointer) {
			unsortedArray[originalArrayIndex] = *insideHolePointer;
			++originalArrayIndex;
		}
	}

	delete[] holes;

}


// display array to screen
void printArray(int *array, int size) {
	for (int index = 0; index < size; index++) {
		cout << array[index] << " ";
	}
}
