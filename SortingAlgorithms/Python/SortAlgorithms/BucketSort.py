import sys
import functools


# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack

def insertionSort(unsortedList) :
    size = len(unsortedList)
    for turn in range(1, size) :
        rememberedValue = unsortedList[turn]
        insertionIndex = turn

        while ((insertionIndex >= 1) and (unsortedList[insertionIndex - 1] > rememberedValue)) :
            unsortedList[insertionIndex] = unsortedList[insertionIndex - 1]
            insertionIndex -= 1
        unsortedList[insertionIndex] = rememberedValue


def bucketSort(unsortedList) :
    size = len(unsortedList)
    buckets = [[] for index in range(0, size)]

    for index in range(0, size) :
        bucketIndex = int(size * unsortedList[index])
        buckets[bucketIndex].append(unsortedList[index])

    for bucketIndex in range(0, size) :
        insertionSort(buckets[bucketIndex])

    originalListIndex = 0
    for bucketIndex in range(0, size) :
        sizeOfEachBucket = len(buckets[bucketIndex])
        for insideBucketIndex in range(0, sizeOfEachBucket) :
            unsortedList[originalListIndex] = buckets[bucketIndex][insideBucketIndex]
            originalListIndex += 1



# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [0.123, 0.25, 0.36, 0.789, 0.0254, 0.568, 0.225, 0.689, 0.999, 0.756]
printList(unsortedList)
bucketSort(unsortedList)
printList(unsortedList)