import sys
import functools


# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack


def heapSort(unsortedList) :
    size = len(unsortedList)
    buildHeapIndex = int(size / 2) - 1
    while(buildHeapIndex >= 0) :
        updateHeapAt(unsortedList,size, buildHeapIndex)
        buildHeapIndex -= 1

    for sizeOfUpdateHeap in range(size - 1, 0, -1) :
        unsortedList[0], unsortedList[sizeOfUpdateHeap] = unsortedList[sizeOfUpdateHeap], unsortedList[0]
        updateHeapAt(unsortedList, sizeOfUpdateHeap, 0)



def updateHeapAt(heapedList, size, updatedPosition) :
    largestIndex = updatedPosition
    leftChildIndex = largestIndex * 2 + 1
    rightChildIndex = largestIndex * 2 + 2

    if((leftChildIndex < size) and (heapedList[leftChildIndex] > heapedList[largestIndex])) :
        largestIndex = leftChildIndex

    if((rightChildIndex < size) and (heapedList[rightChildIndex] > heapedList[largestIndex])) :
        largestIndex = rightChildIndex

    if(largestIndex != updatedPosition) :
        heapedList[updatedPosition], heapedList[largestIndex] = heapedList[largestIndex], heapedList[updatedPosition]
        updateHeapAt(heapedList, size, largestIndex)




# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [12, 58.5, 49, 78, 12.8]
printList(unsortedList)
heapSort(unsortedList)
printList(unsortedList)