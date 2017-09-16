#include <iostream>
#include <fstream>
#include <cstring>
#define RANGE 256
using namespace std;

void countingSort(char *unsortedString);

int main() {
	
	char unsortedString[] = "tuoihoctro";
	// display the original array and the sorted array
	cout << "Original String : " << unsortedString << endl;
	countingSort(unsortedString);
	cout << "Sorted String (accending) : " << unsortedString << endl;

	getchar();
	return 0;
}

void countingSort(char *unsortedString) {
	int lenOfString = strlen(unsortedString);
	// create a new array for couting the number of occurences of a character
	int countingArray[RANGE];
	char *temporaryString = new char[lenOfString + 1]; // plus 1 to contain a NULL character at the end of string
	memset(temporaryString, '\0', lenOfString);
	memset(countingArray, 0, sizeof(countingArray)); // same as :  int countingArray[RANGE] = { 0 };
	
	// count the number of occurences of a character
	for (int charIndex = 0; charIndex < lenOfString; charIndex++) {
		++countingArray[unsortedString[charIndex]];
	}

	// modify the array above : each value of an element contains its actual position in the sorted string
	for (int index = 1; index < RANGE; index++) {
		countingArray[index] += countingArray[index - 1];
	}
	// From the above array, create a new string arranged in alphabetical order
	char currentChar;
	for (int charIndex = 0; charIndex < lenOfString; charIndex++) {
		currentChar = unsortedString[charIndex];
		temporaryString[countingArray[currentChar] - 1] = currentChar;
		--countingArray[currentChar];
	}
	temporaryString[lenOfString] = '\0';
	// copy all of the characters from the temporary string to the original string
	//strcpy_s(unsortedString, strlen(temporaryString), temporaryString); // ? don't work???

	for (int charIndex = 0; charIndex < lenOfString; charIndex++) {
		unsortedString[charIndex] = temporaryString[charIndex];
	}
	unsortedString[lenOfString] = '\0';
}



// display array to screen
void printArray(int *array, int size) {
	for (int index = 0; index < size; index++) {
		cout << array[index] << " ";
	}
}
