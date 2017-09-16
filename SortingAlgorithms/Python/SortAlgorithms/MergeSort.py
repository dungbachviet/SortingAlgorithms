import sys
import functools

# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack


def mergeSort(unsortedList, left, right) :
    if(left < right) :
        middle = int((left + right) / 2)
        mergeSort(unsortedList, left, middle)
        mergeSort(unsortedList, middle + 1, right)
        merge(unsortedList, left, middle, right) # should cast to right type before passing parameters (because default type is float)

 # Merge two sorted arrays into an root array
def merge(unsortedList, left, middle, right) :
    leftListSize = int(middle - left + 1)
    rightListSize = int(right - middle)

    leftList = leftListSize * [0]
    rightList = rightListSize * [0]

    for index in range(0, leftListSize) :
        leftList[index] = unsortedList[left + index]

    for index in range(0, rightListSize) :
        rightList[index] = unsortedList[middle + 1 + index]

    leftListIndex = 0
    rightListIndex = 0
    mainListIndex = left
    while ((leftListIndex < leftListSize) and (rightListIndex < rightListSize)) :
        if(leftList[leftListIndex] < rightList[rightListIndex]) :
            unsortedList[mainListIndex] = leftList[leftListIndex]
            leftListIndex += 1
        else :
            unsortedList[mainListIndex] = rightList[rightListIndex]
            rightListIndex += 1
        mainListIndex += 1

    if(leftListIndex < leftListSize) :
        for index in range(leftListIndex, leftListSize) :
            unsortedList[mainListIndex] = leftList[index]
            mainListIndex += 1

    if(rightListIndex < rightListSize) :
        for index in range(rightListIndex, rightListSize) :
            unsortedList[mainListIndex] = rightList[index]
            mainListIndex += 1

    del leftList[:]
    del rightList[:]


# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [-12.3, 6.5, 27.8, -10, 30.85]
printList(unsortedList)
mergeSort(unsortedList, 0, len(unsortedList) - 1)
printList(unsortedList)