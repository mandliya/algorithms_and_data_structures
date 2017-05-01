/*
 * Given an array, find peak element in it. A peak element is an element that is greater than its neighbors.
 * For example,
 *
 * Input : [8, 9, 10, 2, 5, 6]
 * Output: The peak element is 10
 * Input : [8, 9, 10, 12, 15]
 * Output: The peak element is 15
 * Input : [10, 8, 6, 5, 3, 2]
 * Output: The peak element is 10
 */

#include <iostream>

int findPeak(int arr[], int n, int low, int high)
{
    // mid point
    //
    int mid = (low + high) / 2;
    
    // check if mid element is peak
    //
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
        (mid == n-1 || arr[mid+1] <= arr[mid]))
    {
        return mid;
    }

    // if left neighbour of mid is greater than mid element
    // then peak would be in left array.
    if (mid - 1 >= 0 && arr[mid-1] > arr[mid])
    {
        return findPeak(arr, n, low, mid-1);
    }

    // search the right side otherwise.
    //
    return findPeak(arr, n, mid+1, high);
}

int main()
{
    int arr[] = {10, 20, 30, 25, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeak(arr, n, 0, n-1);
    std::cout << "The peak element of the array is:" << arr[peakIndex]
        << std::endl;
    return 0;
}