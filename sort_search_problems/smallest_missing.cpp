/*
 * Given a sorted array of distinct non-negative integers, find smallest missing element in it.
 * For example,

 * Input: A[] = [0, 1, 2, 6, 9, 11, 15]
 * Output: The smallest missing element is 3
 
 * Input: A[] = [1, 2, 3, 4, 6, 9, 11, 15]
 * Output: The smallest missing element is 0
 
 * Input: A[] = [0, 1, 2, 3, 4, 5, 6]
 * Output: The smallest missing element is 7
 */

#include <iostream>
#include <vector>

int missingElement(const std::vector<int>& arr, int low, int high)
{
    if (low > high)
    {
        return low;
    }

    int mid = low + (high - low)/2;

    // if mid index matches the with the mid element, then smallest
    // missing element lies on the right of the mid.
    if (arr[mid] == mid)
    {
        return missingElement(arr, mid + 1, high);
    }
    else
    {
        return missingElement(arr, low, mid - 1);
    }
}


void print(const std::vector<int>& arr)
{
    std::cout << "Contents of array:" << std::endl;
    for (auto i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr{0, 1, 2, 3, 4, 6, 7};
    print(arr);
    int low = 0;
    int high = arr.size() -1;
    std::cout << "Smallest missing element in array is :" << missingElement(arr, low, high)
        << std::endl;
    return 0;
}
