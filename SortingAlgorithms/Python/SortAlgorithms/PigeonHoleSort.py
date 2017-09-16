import sys
import functools


# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack




def pigeonHoleSort(unsortedList) :
    size = len(unsortedList)
    maxValue, minValue = unsortedList[0], unsortedList[0]
    for index in range(1, size) :
        if (maxValue < unsortedList[index]) :
            maxValue = unsortedList[index]
        if (minValue > unsortedList[index]) :
            minValue = unsortedList[index]

    distanceMinMax = maxValue - minValue + 1
    holes = [[] for index in range(0, distanceMinMax)]

    for pigeonIndex in range(0, size) :
        pigeonValue = unsortedList[pigeonIndex]
        holes[pigeonValue - minValue].append(pigeonValue)

    originalArrayIndex = 0
    for holeIndex in range(0, distanceMinMax) :
        sizeOfAHole = len(holes[holeIndex])
        for insideAHoleIndex in range(0, sizeOfAHole) :
            unsortedList[originalArrayIndex] = holes[holeIndex][insideAHoleIndex]
            originalArrayIndex += 1

    del holes


# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%d " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [25, 49, 17, 24, 8 , 30, 5, 6, 15, 100, 1000, 30, 27, 24]
printList(unsortedList)
pigeonHoleSort(unsortedList)
printList(unsortedList)