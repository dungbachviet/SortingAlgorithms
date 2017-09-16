import sys
import functools

# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")

def insertionSort(unsortedList) :
    size = len(unsortedList)
    for turn in range(1, size) :
        rememberedValue = unsortedList[turn]
        insertionIndex = turn

        while ((insertionIndex >= 1) and (unsortedList[insertionIndex - 1] > rememberedValue)) :
            unsortedList[insertionIndex] = unsortedList[insertionIndex - 1]
            insertionIndex -= 1
        unsortedList[insertionIndex] = rememberedValue


# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [-12.3, 6.5, 27.8, -10, 30.85]
printList(unsortedList)
insertionSort(unsortedList)
printList(unsortedList)