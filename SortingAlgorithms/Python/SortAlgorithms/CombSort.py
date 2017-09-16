import sys
import functools


# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack


def combSort(unsortedArray) :
    size = len(unsortedArray)
    startingPointOfGap = size
    hasSwapped = True

    while ((startingPointOfGap != 1) or (hasSwapped == True)) :
        startingPointOfGap = getNextGap(startingPointOfGap)
        hasSwapped = False
        for comparingIndex in range(startingPointOfGap, size) :
            if(unsortedArray[comparingIndex] < unsortedArray[comparingIndex - startingPointOfGap]) :
                unsortedArray[comparingIndex], unsortedArray[comparingIndex - startingPointOfGap] = unsortedArray[comparingIndex - startingPointOfGap], unsortedArray[comparingIndex]
                hasSwapped = True



def getNextGap(gap) :
    gap = int((gap * 10) / 13)
    if(gap < 1) :
        return 1
    return gap

# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedArray = [12, 58.5, 49, 78, 12.8]
printList(unsortedArray)
combSort(unsortedArray)
printList(unsortedArray)