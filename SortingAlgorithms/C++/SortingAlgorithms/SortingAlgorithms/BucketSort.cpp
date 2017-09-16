#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(double *unsortedArray, int size);
void printArray(double *array, int size);


int main() {

	int size = 5;
	double unsortedArray[] = { 0.12, 0.58, 0.125, 0.789, 0.666 };
	
	// display the original array and the sorted array
	cout << "Original Array : " << endl;
	printArray(unsortedArray, size);
	cout << "\n\nSorted Array (accending) : " << endl;
	bucketSort(unsortedArray, size);
	printArray(unsortedArray, size);

	getchar();
	return 0;
}


void bucketSort(double *unsortedArray, int size) {
	vector<double> *buckets = new vector<double>[size];
	
	// put elements into proper buckets
	int bucketIndex;
	for (int index = 0; index < size; index++) {
		bucketIndex = size * unsortedArray[index];
		buckets[bucketIndex].push_back(unsortedArray[index]);
	}

	// using insertion algorithm to sort elements in each bucket ascendingly 
	for (int bucketIndex = 0; bucketIndex < size; bucketIndex++) {
		sort(buckets[bucketIndex].begin(), buckets[bucketIndex].end());
	}

	// Copy elements from buckets into the original array
	int originalArrayIndex = 0;
	int sizeOfEachBucket;
	for (int bucketIndex = 0; bucketIndex < size; bucketIndex++) {
		sizeOfEachBucket = buckets[bucketIndex].size();
		for (int insideBucketIndex = 0; insideBucketIndex < sizeOfEachBucket; insideBucketIndex++) {
			unsortedArray[originalArrayIndex] = buckets[bucketIndex][insideBucketIndex];
			++originalArrayIndex;
		}
	}

}


// display array to screen
void printArray(double *array, int size) {
	for (int index = 0; index < size; index++) {
		cout << array[index] << " ";
	}
}
