import sys
import functools

# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")

# Swapping beween two elements in list
def swap(unsortedList, index1, index2) :
    intermediateValue = unsortedList[index1]
    unsortedList[index1] = unsortedList[index2]
    unsortedList[index2] = intermediateValue

# Selection Sort Algorithm
def selectionSort(unsortedList) :
    size = len(unsortedList)
    for index in range(0, size) :
        minIndex = index
        for findMinIndex in range(index + 1, size) :
            if(unsortedList[findMinIndex] < unsortedList[minIndex]) :
                minIndex = findMinIndex
        swap(unsortedList, index, minIndex) # or using : unsortedList[index], unsortedList[minIndex] = unsortedList[minIndex], unsortedList[index]

# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [-12.3, 6.5, 27.8, -10, 30.85]
printList(unsortedList)
selectionSort(unsortedList)
printList(unsortedList)