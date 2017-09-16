import sys
import functools

# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack


def quickSort(unsortedList, left, right) :
    if(left < right) :
        pointOfPartition = partition(unsortedList, int(left), int(right))
        quickSort(unsortedList, left, pointOfPartition - 1)
        quickSort(unsortedList, pointOfPartition + 1, right)


def partition(unsortedList, left, right) :
    pivot = unsortedList[right]
    lastOfFirstPartition = left - 1

    for lastOfSecondPartition in range(left, right) : #means [left, right - 1]
        if(unsortedList[lastOfSecondPartition] < pivot) :
            lastOfFirstPartition += 1
            unsortedList[lastOfFirstPartition], unsortedList[lastOfSecondPartition] = unsortedList[lastOfSecondPartition], unsortedList[lastOfFirstPartition]
    unsortedList[lastOfFirstPartition + 1], unsortedList[right] = unsortedList[right], unsortedList[lastOfFirstPartition + 1]
    return lastOfFirstPartition + 1

# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [-12.3, 6.5, 27.8, -10, 30.85]
printList(unsortedList)
quickSort(unsortedList, 0, len(unsortedList) - 1)
printList(unsortedList)