## Data Structure and Algorithms Problems

<center>

![alt tag](https://raw.githubusercontent.com/mandliya/algorithms_and_ds_playground/master/image.jpg)

| Current Status|     Stats     |
| :------------: | :----------: |
| Total Problems | 92 |
| Current Streak | 63 days |
| Longest Streak | 63 ( August 17, 2015 - October 18, 2015 ) |

</center>

### LinkedList Problems 
| Problem | Solution |
| :------------ | :----------: |
| Find the nth node of linked list from last. | [nthToLastNode.cpp] (linked_list_problems/nthToLastNode.cpp) |
| Add numbers where each digit of the number is represented by node of a linkedlist.  Give output as a linked list. | [add_two_numbers_lists.cpp] (linked_list_problems/add_two_numbers_lists.cpp) |
| Swap nodes of a linkedlist without swapping data. | [swapNodesWithoutSwappingData.cpp] (linked_list_problems/swapNodesWithoutSwappingData.cpp) |
| Reverse a linked list, iteratively and recursively | [reverseLinkedListIterAndRecurse.cpp](linked_list_problems/reverseLinkedListIterAndRecurse.cpp)|
| Given a linked list, reverse alternate nodes and append at the end. | [reverseAlternateNodes.cpp](linked_list_problems/reverseAlternateNodes.cpp) |
| Only given a node pointer, delete the node from the linked list. | [deleteNode.cpp](linked_list_problems/deleteNode.cpp) |
| Delete the entire linkedlist. | [deleteLinkedlist.cpp](linked_list_problems/deleteLinkedlist.cpp)|
| Print middle node of linkedlist without iterating twice. | [printMiddleNode.cpp](linked_list_problems/printMiddleNode.cpp) | | Detecting and removing a cycle in linkedlist.| [floyedCycleDetection.cpp](linked_list_problems/floyedCycleDetection.cpp)|
| Determine if a linked list is a pallindrome. | [listPallindrome.cpp](linked_list_problems/listPallindrome.cpp) |
| Insert data in a sorted linked list.|[insertInASortedLinkedList.cpp](linked_list_problems/insertInASortedLinkedList.cpp) |
| Determine the intersection(merging) point of two given linked list.| [findIntersectionPointOfLists.cpp](linked_list_problems/findIntersectionPointOfLists.cpp)|
| Clone a linkedlist which has next and an random pointer, Space Complexity - O(1). | [cloneListWithRandomPtr.cpp](linked_list_problems/cloneListWithRandomPtr.cpp)|
| Given a sorted linked list with duplicates, remove duplicates in one iteration. | [removeDuplicatesFromSortedList.cpp](linked_list_problems/removeDuplicatesFromSortedList.cpp)| 
| Using Floyd's cycle finding algorithm, detect if a linkedlist contain cycle, if it does contain cycle, remove the loop | [floyedCycleDetection.cpp] (linked_list_problems/floyedCycleDetection.cpp) |
| Sort a linked list using merge sort | [merge_sort.cpp] (linked_list_problems/merge_sort.cpp) |
| Given a singly linked list L<sub>0</sub> -> L<sub>1</sub> -> … -> L<sub>n-1</sub> -> L<sub>n</sub>. Rearrange the nodes in the list (in place) so that the new formed list is : L<sub>0</sub> -> L<sub>n</sub> -> L<sub>1</sub> -> L<sub>n-1</sub> -> L<sub>2</sub> -> L<sub>n-2<sub> ....| [rearrange_list.cpp](linked_list_problems/rearrange_list.cpp)|

### Include 
Include contains single header implementation of data structures and some algorithms.

| DS/ALG |     Implementation   |
| :------------: | :----------: |
| Generic Macros and Algorithms like swap, random number generation | [generic.h](include/generic.h) |
| Generic Stack Implementation | [stack.h](include/stack.h) |
| Generic Queue Implementation | [queue.h](include/queue.h) |
| Generic List Implementation  | [list.h] (include/list.h) |
| Binary Search Tree Implementation | [binarySearchTree.h] (include/binarySearchTree.h)
| Quick Sort Implementation | [quickSort.h] (include/quickSort.h) |
| Merge Sort Implementation | [mergeSort.h] (include/bubbleSort.h)|
| Selection Sort Implementation | [selectionSort.h] (include/selectionSort.h) |
| Bubble Sort Implementation | [bubbleSort.h] (include/bubbleSort.h) |
| Linux Kernel Double LinkedList Implementation | [double_linked_list.h](include/double_linked_list.h) |
| Generic Graph Implementation (Adjacency List) | [graph.h](include/graph.h) |
| Heap Sort Implementation | [heap_sort.h](include/heap_sort.h)|
| My own string library implementation | [pstring.h](include/pstring.h) [pstring.cpp](include/pstring.cpp)|

###Bit Manipulation Problems
| Problem | Solution |
| :------------ | :----------: |
| Determine if a number is a power of 2. | [power_of_2.cpp](bit_manipulation/power_of_2.cpp) |
| Add two binary number represented as string. | [addBin.cpp](bit_manipulation/addBin.cpp) |
| Determine the next power of 2 for a given number. | [next_power_of_2.cpp](bit_manipulation/next_power_of_2.cpp) |
| Using bit manipulation determine if a number is multiple of 3. | [multiple_of_3.cpp](bit_manipulation/multiple_of_3.cpp) |
| Determine endianess of the machine, print a number in reverse Endianess. | [reverseEndianness.cpp](bit_manipulation/reverseEndianness.cpp) |
| Find the parity of given number. | [find_parity.cpp](bit_manipulation/find_parity.cpp) |
| Implement fast multiplication of a number to 7 using bit manipulation. | [multiply_by_7.cpp](bit_manipulation/multiply_by_7.cpp) |
| Reverse bits of unsigned integer (two methods - Reversing bit by bit & divide and conquer). | [reverseBitsOfAnInteger.cpp](bit_manipulation/reverseBitsOfAnInteger.cpp) |
| Small function to determine position of right most set bit in a given integer.| [right_most_set_bit.cpp](bit_manipulation/right_most_set_bit.cpp)| 
|Given a vector of numbers, only one number occurs odd number of times, find the number.| [find_odd_one_out.cpp](bit_manipulation/find_odd_one_out.cpp)|
| Given two integers, determine if their sum would be interger overflow.| [integerOverflow.cpp](bit_manipulation/integerOverflow.cpp)|
| How many bit flip operation would require to convert number A to B. | [countNumberOfBitFlips.cpp](bit_manipulation/countNumberOfBitFlips.cpp)|
| Given a number x and two positions (from right side) in binary representation of x, write a function that swaps n right bits at given two positions and returns the result. It is also given that the two sets of bits do not overlap.|[swapSetOfBits.cpp](bit_manipulation/swapSetOfBits.cpp)|
| Add two numbers without using any arithmetic operators | [addition_without_operators.cpp](bit_manipulation/addition_without_operators.cpp)
| Louise and Richard play a game. They have a counter set to N. Louise gets the first turn and the turns alternate thereafter. In the game, they perform the following operations: <ul><li>If N is not a power of 2, reduce the counter by the largest power of 2 less than N.</li></ul><ul><li>If N is a power of 2, reduce the counter by half of N.</li></ul> The resultant value is the new N which is again used for subsequent operations.The game ends when the counter reduces to 1, i.e., N == 1, and the last person to make a valid move wins. <ul><li> Given N, your task is to find the winner of the game. If they set counter to 1, Richard wins, because its Louise' turn and she cannot make a move.</li></ul><ul><li>Input Format : -The first line contains an integer T, the number of testcases. T lines follow. Each line contains N, the initial number set in the counter.|[counter_game.cpp](bit_manipulation/counter_game.cpp)| 

### Cracking the coding interview problems
| Problem | Solution |
| :------------ | :----------: |
| Problem 1-1 : Edition 6: Write an algorithm to determine whether a string has unique characters or not. Can we do it without using addtional data structures? | [1-1-hasUniqueChars.cpp](cracking_the_coding_interview_problems/1-1-hasUniqueChars.cpp)|
| Problem 1-2 : Edition 5: Reverse a string when you are a pass a null terminated C string.|[1-2-edi5-reverseString.cpp ](cracking_the_coding_interview_problems/1-2-edi5-reverseString.cpp)|
| Problem 1-2 : Edition 6: Given two strings, determine if one is permutation of other.|[1-2-perm-strings.cpp](cracking_the_coding_interview_problems/1-2-perm-strings.cpp)|
| Problem 1-3 : Edition 5: Write an algorithm to remove duplicate chars from a string.|[1-3-edi5-removeDuplicates.cpp](cracking_the_coding_interview_problems/1-3-edi5-removeDuplicates.cpp)|
| Problem 1-3 : Edition 6: URLify: Replace all the spaces in a string with '%20'. Preferebly Inplace |[1-3-URLify.cpp](cracking_the_coding_interview_problems/1-3-URLify.cpp)|
| Problem 1-4 : Edition 6: Given a string, write a function to check if it is a permutation of a pallindrome.|[1-4-pallindrome-permutations.cpp ](cracking_the_coding_interview_problems/1-4-pallindrome-permutations.cpp)|
| Problem 1-5 : Edition 6: There are three possible edits that can be performed on a string - Insert a char, Delete a char, Replace a char. Given two strings, determine if they are one or 0 edit away.|[1-5-one-edit-away.cpp ](cracking_the_coding_interview_problems/1-5-one-edit-away.cpp)|
| Problem 1-6: Implement a method to perform basic string compression. Example string **aabcccccaaa** should be compressed to **a2b1c5a3**, however if compressed string is bigger than original string, return original string| [1-6-string-compression.cpp](cracking_the_coding_interview_problems/1-6-string-compression.cpp)|
| Problem 1-7: Rotate the matrix clockwise( & anticlockwise) by 90 degrees| [1-7-matrix-rotation.cpp](cracking_the_coding_interview_problems/1-7-matrix-rotation.cpp)|
| Problem 1-8: Write an algorithm such that if an element of MxN matrix is 0, its entire row and column is set to 0. | [1-8-zero-matrix.cpp](cracking_the_coding_interview_problems/1-8-zero-matrix.cpp)|
| Problem 1-9: Given two strings s1 and s2, determine s2 is rotation of s1 using only one call to a function which checks whether one string is rotation of another.|[1-9-string-rotation.cpp](cracking_the_coding_interview_problems/1-9-string-rotation.cpp)|
| Problem 2-1: Remove duplicates from an *unsorted* linked list. What if no temporary buffer is allowed.|[2-1-remove-dups.cpp](cracking_the_coding_interview_problems/2-1-remove-dups.cpp)|
| Problem 2-2: Determine k<sup>th</sup> node from the last of a singly linked list. (Iterative and Recursive Approaches) | [2-2-kthToLast.cpp](cracking_the_coding_interview_problems/2-2-kthToLast.cpp)|
| Problem 2-3: Implement an algorithm to delete a node in the middle of a singly linked list | [2-3-delete-middle-node.cpp](cracking_the_coding_interview_problems/2-3-delete-middle-node.cpp)|
| Problem 2-4: Partition a linked list around a value x, all the nodes smaller than x come before all the nodes greater than equal to x | [2-4-partition.cpp](cracking_the_coding_interview_problems/2-4-partition.cpp)|
| Problem 2-5: You have two numberse represented by a linked list where each node contains a single digit. The digits are stored in reversed order, such that 1's digits are at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.Example:<ul><li>Input: ( 7 --> 1 --> 6 ) + ( 5 --> 9 --> 2 ) that is 617 + 295</li></ul><ul><li>Output: ( 2 --> 1 --> 9 ) i.e. 912.</li></ul><ul><li> FOLLOW UP : Suppose the lists are stored in forward order, Repeat the above problem.</ul></li><ul><li>Input: ( 6 --> 1 --> 7 ) + ( 2 --> 9 --> 5 ) i.e. 617 + 295</li></ul><ul><li> Output: ( 9 --> 1 --> 2 ) i.e. 912.</li></ul><ul><li>Implement it  recursively and iteratively.</li></ul> | [2-5-add-lists.cpp](cracking_the_coding_interview_problems/2-5-add-lists.cpp) |
| Problem 2-6: Determine if linked list is palindrome( 2 iterative and one recursive approach | [2-6-palindrome.cpp](cracking_the_coding_interview_problems/2-6-palindrome.cpp) |
| Problem 2-7: Determine if two singly linked list intersect, if yes, return the intersecting node. The intersection is defined based on reference not on values|[2-7-intersection.cpp](cracking_the_coding_interview_problems/2-7-intersection.cpp)|
| Problem 2-8: Detect if the linked list have a loop, Find the start node of the loop and remove the loop| [2-8-loop-detection.cpp](cracking_the_coding_interview_problems/2-8-loop-detection.cpp)

###Dynamic Programming Problems
| Problem | Solution |
| :------------ | :----------: |
| N<sup>th</sup> Fibonacci term using different memoization techniques | [fibonacci.cpp](dynamic_programming_problems/fibonacci.cpp)|
| Longest Common Subsequence Problem | [lcs.cpp](dynamic_programming_problems/lcs.cpp) |
| Maximum Value Contigous Subsequence Problem [wiki](https://en.wikipedia.org/wiki/Maximum_subarray_problem)| [max_subsequence.cpp](dynamic_programming_problems/max_subsequence.cpp)|
| Catalan number - Count the number of possible Binary Search Trees with n keys | [catalan_number.cpp](dynamic_programming_problems/catalan_number.cpp)|

### Tree Problems
| Problem | Solution |
| :------------ | :----------: |
|Iterative Level order traversal of Tree using queue |[levelOrderTraversalIterative.cpp](tree_problems/levelOrderTraversalIterative.cpp)|
|Recursive Level order traveral of Tree | [levelOrderTraversalRecursive.cpp](tree_problems/levelOrderTraversalRecursive.cpp)|
|ZigZag Traversal of Tree | [zigZagTraversal.cpp](tree_problems/zigZagTraversal.cpp)|
|Predecessor and Successor of a given node in Binary Search Tree | [predecessorSuccessor.cpp](tree_problems/predecessorSuccessor.cpp)|
|Given values of two nodes in a Binary Search Tree, find the Lowest Common Ancestor (LCA). Assume that both the values exist in the tree.| [lowest-common-ancestor.cpp](tree_problems/lowest-common-ancestor.cpp)|
|Given a binary tree, print out all of its root-to-leaf paths one per line.| [printAllRootToLeafPath.cpp](tree_problems/printAllRootToLeafPath.cpp)
|Determine if a tree is sum tree. A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.| [sumTree.cpp](tree_problems/sumTree.cpp)|
|Convert a tree to sumTree, such that each node is sum of left and right subtree of the original tree.| [convert_to_sum_tree.cpp](tree_problems/convert_to_sum_tree.cpp)|


### String Problems
| Problem | Solution |
| :------------ | :----------: |
| Implementation of Robin-Karp algorithm for string search | [robinKarpStringMatching.cpp](string_problmes/robinKarpStringMatching.cpp) |
| Find next permutation of a given string, ie. rearrange the given string sucht a way that is next lexicographically greater string than given string | [next_permutation.cpp](string_problems/next_permutation.cpp)|
| Implementation of Z algorithm for pattern matching | [z.cpp](string_problems/z.cpp)|
| Test cases for self created string library | [pstring_test.cpp](string_problems/pstring_test.cpp)|

### Common Data Structure and logic problems
| Problem | Solution |
| :------------ | :----------: |
| Print the contents of matrix in a spiral order | [matrix_spiral_print.cpp](common_ds_problems/matrix_spiral_print.cpp)
| Given a M x N matrix, rotate it by R rotations anticlockwise, and show the resulting matrix. | [rotate_matrix.cpp](common_ds_problems/rotate_matrix.cpp)|
| Rotate an array by r elements ( left or right ) | [array_rotation.cpp](common_ds_problems/array_rotation.cpp)
| Given an array of repeating/non-repeating intergeres, determine the first non-repeating int in this array | [first_non_repeating_int.cpp](common_ds_problems/first_non_repeating_int.cpp)|

### Math Problems
| Problem | Solution |
| :------------ | :----------: |
|  Print all the permutations of a string. Example: Permutations of ABC are ABC, ACB, BCA, BAC, CAB, CBA | [string_permutations.cpp] (math_problems/string_permutations.cpp) |
| Euclidean algorithm to find greatest common divisor of two numbers. (Iterative and recursive)|[gcd.cpp](math_problems/gcd.cpp)|
| Implement pow(x,y) using divide and conquer approach. Try implementing it in O(logn)| [pow.cpp](math_problems/pow.cpp)|
| Calculate factorial of large number, say 100 (it will have 158 digits) |[factorial_of_large_num.cpp](math_problems/factorial_of_large_num.cpp)|
| Generate all possible words from a number entered on a traditional mobile keypad | [phone_digits.cpp](math_problems/phone_digits.cpp)|

### Stack Problems
| Problem | Solution |
| :------------ | :----------: |
|  We have series of n daily price quotes for a stock. We need to calculate span of stock's price for all n days. Span for ith day is defined as maximum number of consecutive days, for which the price of the stock was less than or equal to ith day. For stock quotes {100, 60, 70, 65, 80, 85} span will be {1, 1, 2, 1, 4, 5}. Span for day 1 is always 1, now for day 2 stock is at 60, and there is no day befor it when stock was less than 60. So span remains 1. For day 3, the stock is priced at 70, so its span is 2, as previous day it was 60, and so on. | [stock_span_problem.cpp](stack_problems/stock_span_problem.cpp) |
| Given an infix expression, convert it to postfix expression, Example (A+B)\*C --> AB+C\* | [infix_to_postfix.cpp](stack_problems/infix_to_postfix.cpp) |

### Sort and Search Problems
| Problem | Solution |
| :------------ | :----------: |
| Given a sorted vector, return first index of the occurrence of a value in vector, if number does not exist, return -1 | [first_occurrence_binary_search.cpp](sort_search_problems/first_occurrence_binary_search.cpp) |
| Given a list of unsorted integers, A={a<sub>1</sub>,a<sub>2</sub>,…,a<sub>N</sub>}, Find the pair of elements that have the smallest absolute difference between them? If there are multiple pairs, find them all.| [closest_numbers.cpp](sort_search_problems/closest_numbers.cpp)|

### Graph Problems
| Problem | Solution |
| :------------ | :----------: |
| Depth First Traversal of a Graph | [dfsDemo.cpp](graph_problems/dfsDemo.cpp) |
| Breadth First Traversal of a Graph | [bfsDemo.cpp](graph_problems/bfsDemo.cpp) |
| calculate the shortest distance from the start position (Node S) to all of the other nodes in the graph using Dijkstra algorithm. | [dijkstra-shortest-reach.cpp](graph_problems/dijkstra-shortest-reach.cpp)|
| Calculate total weight of Minimum Spanning Tree of a given graph ( sum of weights of edges which forms MST) using Prim's algorithm | [primsMST.cpp](graph_problems/primsMST.cpp)|

###Greedy Problems
| Problem | Solution |
| :------------ | :----------: |
| Given two integer arrays, A and B, each containing N integers. You are free to permute the order of the elements in the arrays. Is there an permutation A', B' possible of A and B, such that, A'<sub>i</sub>+B'<sub>i</sub> ≥ K for all i, where A'<sub>i</sub> denotes the i<sup>th</sup> element in the array A' and B'<sub>i</sub> denotes i<sup>th</sup> element in the array B'.| [two_arrays.cpp](greedy_problems/two_arrays.cpp)|
|John is taking orders. The i<sup>th</sup> order is placed by the i<sup>th</sup> customer at t<sub>i</sub> time and it takes d<sub>i</sub> time to procees. What is the order in which the customers will get their orders? (see more details in solutions's comments)|[orders_order.cpp](greedy_problems/orders_order.cpp)|
