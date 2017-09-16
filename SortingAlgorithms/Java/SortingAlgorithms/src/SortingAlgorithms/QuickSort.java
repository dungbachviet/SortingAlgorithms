package SortingAlgorithms;



public class QuickSort {
    
    public static void swap(double[] unsortedArray, int index1, int index2) {
        double intermediate = unsortedArray[index1];
        unsortedArray[index1] = unsortedArray[index2];
        unsortedArray[index2] = intermediate;
    }
    
    
    // Partition with the first element as the pivot
    public static int firstPivotPartition(double[] unsortedArray, int left, int right) {
        int lastOfFirstPartitionIndex = left;
        int firstOfSecondPartitionIndex = right + 1;
        double pivot = unsortedArray[left];
        
        while(lastOfFirstPartitionIndex < firstOfSecondPartitionIndex) {
            ++lastOfFirstPartitionIndex;
            while((lastOfFirstPartitionIndex <= right) && (unsortedArray[lastOfFirstPartitionIndex] <= pivot))
                lastOfFirstPartitionIndex++;
            
            --firstOfSecondPartitionIndex;
            while((firstOfSecondPartitionIndex > left) && (unsortedArray[firstOfSecondPartitionIndex] > pivot)) 
                firstOfSecondPartitionIndex--;
            
            if(lastOfFirstPartitionIndex <= right) // avoid arising the exception ArrayIndexOutOfBoundsException when lastOfFirstPartitionIndex > right
                swap(unsortedArray, lastOfFirstPartitionIndex, firstOfSecondPartitionIndex);
        }
        if(lastOfFirstPartitionIndex <= right) // avoid arising the exception ArrayIndexOutOfBoundsException when lastOfFirstPartitionIndex > right
            swap(unsortedArray, lastOfFirstPartitionIndex, firstOfSecondPartitionIndex);
        swap(unsortedArray, firstOfSecondPartitionIndex, left);
        
        return firstOfSecondPartitionIndex;
    }
    
    
    // Partition with the middle element as the pivot
    public static int middlePivotPartition(double[] unsortedArray, int left, int right) {
        int middle = (left + right) / 2;
        swap(unsortedArray, middle, left);
        double pivot = unsortedArray[left];
        int lastOfFirstPartitionIndex = left + 1;
        int firstOfSecondPartitionIndex = right;
  
        while(lastOfFirstPartitionIndex <= firstOfSecondPartitionIndex) { // must have sign '=' when sorting an array that contains 2 elements
            
            while((lastOfFirstPartitionIndex <= firstOfSecondPartitionIndex) && (unsortedArray[lastOfFirstPartitionIndex] <= pivot))
                lastOfFirstPartitionIndex++;
            
            while(unsortedArray[firstOfSecondPartitionIndex] > pivot) 
                firstOfSecondPartitionIndex--;
                 
            if(lastOfFirstPartitionIndex <= firstOfSecondPartitionIndex) {
                swap(unsortedArray, lastOfFirstPartitionIndex, firstOfSecondPartitionIndex);
                ++lastOfFirstPartitionIndex;
                --firstOfSecondPartitionIndex;
            }
        }
        swap(unsortedArray, left, firstOfSecondPartitionIndex);

        return firstOfSecondPartitionIndex;
    }
    
    
    // partition with the last element as the pivot
    public static int lastPivotPartition(double[] unsortedArray, int left, int right) {
        double pivot = unsortedArray[right];
        int lastOfFirstPartition = left - 1;
        
        for(int lastOfSecondPartition = left; lastOfSecondPartition <= right - 1; lastOfSecondPartition++ ) {
            if(unsortedArray[lastOfSecondPartition] <= pivot) {
                lastOfFirstPartition++;
                swap(unsortedArray, lastOfFirstPartition, lastOfSecondPartition);
            }
        }
        swap(unsortedArray, lastOfFirstPartition + 1, right);
        
        return lastOfFirstPartition + 1;
    }
    
    // Quick Sort algorithm using the first element as the pivot
    public static void firstQuickSort(double[] unsortedArray, int left, int right) {
        if(left < right) {
            int pointOfPartition = firstPivotPartition(unsortedArray, left, right);
            firstQuickSort(unsortedArray, left, pointOfPartition - 1);
            firstQuickSort(unsortedArray, pointOfPartition + 1, right);
        }
    }    

     // Quick Sort algorithm using the middle element as the pivot
    public static void middleQuickSort(double[] unsortedArray, int left, int right) {
        if(left < right) {
            int pointOfPartition = middlePivotPartition(unsortedArray, left, right);
            middleQuickSort(unsortedArray, left, pointOfPartition - 1);
            middleQuickSort(unsortedArray, pointOfPartition + 1, right);
        }
    }
    
    // Quick Sort algorithm using the last element as the pivot
    public static void lastQuickSort(double[] unsortedArray, int left, int right) {
        if(left < right) {
            int pointOfPartition = lastPivotPartition(unsortedArray, left, right);
            lastQuickSort(unsortedArray, left, pointOfPartition - 1);
            lastQuickSort(unsortedArray, pointOfPartition + 1, right);
        }
    }
    
    // Display the array on the screen
    public static void printArray(double[] unsortedArray) {
        int size = unsortedArray.length;
        for(int index = 0; index < size; index++) {
            System.out.print(unsortedArray[index] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
//        double[] unsortedArray = {12.5, -110, 97, 12, 11, -55, 68.75, 12.27};
        double[] unsortedArray = {12, 10, 30, 11};
        
        System.out.println("The unsorted array : \n");
        printArray(unsortedArray);
        
//        lastQuickSort(unsortedArray, 0, unsortedArray.length - 1);
//        System.out.println("The sorted array using Quick Sort(pivot is the last element) : \n");
//        printArray(unsortedArray);
//        
//        firstQuickSort(unsortedArray, 0, unsortedArray.length - 1);
//        System.out.println("The sorted array using Quick Sort(pivot is the first element) : \n");
//        printArray(unsortedArray);
        
        middleQuickSort(unsortedArray, 0, unsortedArray.length - 1);
        System.out.println("The sorted array using Quick Sort(pivot is the middle element) : \n");
        printArray(unsortedArray);
        
    }
}
