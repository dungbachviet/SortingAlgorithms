import sys
import functools


# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack


def shellSort(unsortedList) :
    size = len(unsortedList)
    interval = 1

    while(interval <= (size / 3)) :
        interval = interval * 3 + 1

    while(interval > 0) :
        for comparingIndex in range(interval, size) :
            comparingValue = unsortedList[comparingIndex]
            currentIndex = comparingIndex
            while((currentIndex >= interval) and (unsortedList[currentIndex - interval] > comparingValue)) :
                unsortedList[currentIndex] = unsortedList[currentIndex - interval]
                currentIndex -= interval

            unsortedList[currentIndex] = comparingValue
        interval = int((interval - 1) / 3)



# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%f " % list[index])
    print("\n")

 # Demo the algorithm
unsortedList = [12, 58.5, 49, 78, 12.8]
printList(unsortedList)
shellSort(unsortedList)
printList(unsortedList)