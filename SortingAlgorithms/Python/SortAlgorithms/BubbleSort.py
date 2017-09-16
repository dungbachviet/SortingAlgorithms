import sys
import functools

# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")

def bubbleSort(unsortedList) :
    size = len(unsortedList)
    for turn in range(0, size - 1) : # means [0, size - 2]
        for bubbleIndex in range(0, size - 1 - turn) :
            if(unsortedList[bubbleIndex] > unsortedList[bubbleIndex + 1]) :
                unsortedList[bubbleIndex], unsortedList[bubbleIndex + 1] = unsortedList[bubbleIndex + 1], unsortedList[bubbleIndex]


# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [-12.3, 6.5, 27.8, -10, 30.85]
printList(unsortedList)
bubbleSort(unsortedList)
printList(unsortedList)