import sys
import functools

# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack

# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%d " % list[index])
    print("\n")


def maximum(unsortedList) :
    size = len(unsortedList)
    maximumValue = unsortedList[0]
    for index in range(1, size) :
        if(maximumValue < unsortedList[index]) :
            maximumValue = unsortedList[index]

    return maximumValue


def countingSort(unsortedList, divisionUnit) :
    size = len(unsortedList)
    countingKeysList = [0] * 10
    sortedList = [0] * size

    for index in range(0, size) :
        key = int(unsortedList[index] / divisionUnit) % 10
        countingKeysList[key] += 1

    for key in range(1, 10) :
        countingKeysList[key] += countingKeysList[key - 1]

    for index in range(size - 1, -1, -1) :
        key = int(unsortedList[index] / divisionUnit) % 10
        sortedList[countingKeysList[key] - 1] = unsortedList[index]
        countingKeysList[key] -= 1

    for index in range(0, size) :
        unsortedList[index] = sortedList[index]
    print("\nTest : ", sortedList)
    del sortedList # free memory


def radixSort(unsortedList) :
    maximumValue = maximum(unsortedList)
    divisionUnit = 1
    while(divisionUnit <= maximumValue) :
        countingSort(unsortedList, divisionUnit)
        divisionUnit *= 10

 # Demo the algorithm
unsortedString = [10, 1000, 20, 5, 6]
printList(unsortedString)
radixSort(unsortedString)
printList(unsortedString)

