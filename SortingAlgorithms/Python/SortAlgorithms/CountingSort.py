import sys
import functools
RANGE = 256

# Modify the build-in function print (remove character a default new line
# at the end of a string)
print = functools.partial(print, end="")
sys.setrecursionlimit(1500)# allocate more memory for stack


def countingSort(unsortedString) :
    lenOfString = len(unsortedString)
    countingList = RANGE * [0]
    temporaryString = [None] * lenOfString # must have None inside the brackets

    for charIndex in range(0, lenOfString) :
        countingList[ord(unsortedString[charIndex])] += 1

    for index  in range(1, RANGE) :
        countingList[index] += countingList[index - 1]

    for charIndex in range(0, lenOfString) :
        currentChar = unsortedString[charIndex]
        temporaryString[countingList[ord(currentChar)] - 1] = currentChar
        countingList[ord(currentChar)] -= 1

    for charIndex in range(0, lenOfString) :
        unsortedString[charIndex] = temporaryString[charIndex]



# Display the list on the screen
def printList(list) :
    size = len(list)
    for index in range(0, size) :
        print("%s" % list[index])
    print("\n")

 # Demo the algorithm
unsortedString = ['d', 'c', 'b', 'a']
printList(unsortedString)
countingSort(unsortedString)
printList(unsortedString)