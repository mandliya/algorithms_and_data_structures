###Problem Statement
Search an element in a sorted array.

###Appraoch
Naive approach would be to iterate the array and check each element. The time complexity of this approach would O(n). We can use binary search. Since array is sorted we compare the element to be searched with the middle element, if the middle element is the element we require, we return the index. If middle element is smaller it means the element we are searching for is in the second half of array, similarly if middle element is bigger, it means the element we are looking for is in the first half of array.

Each time we are reducing the problem size by half. Therefore, we can conclude that time complexity of this algorithm would be **O(logn)**
