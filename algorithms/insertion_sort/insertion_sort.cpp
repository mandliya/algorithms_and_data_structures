//
// Created by radligna on 05.10.17.
//


// C++ program for insertion sort

//needed to print the sorted array
#include <iostream>

/* Function to sort an array using insertion sort */
void insertionSort( int tab[], int arraySize ) {
    int temp, iter2;
    for( int iter1 = 1; iter1 < arraySize; iter1++ ) {
        temp = tab[iter1];
        for( iter2 = iter1 - 1; iter2 >= 0 and tab[iter2] > temp; iter2-- )
            tab[ iter2 + 1 ] = tab[ iter2 ];
        tab[ iter2 + 1 ] = temp;
    }
}
// method to print array
void printArray(int arr[], int arraySize) {
    for (int  i=0; i < arraySize; i++)
        std::cout<<arr[i]<<" ";
}
/* To test insertion sort function */
int main() {
    int arr[] = {10, 29, 1, 9, 37, 24, 6, 3, 11};
    int arraySize = (sizeof(arr)/sizeof(*arr));
    insertionSort(arr, arraySize);
    printArray(arr, arraySize);
    return 0;
}