## Data Structure and Algorithms Problems

<center>

![alt tag](https://raw.githubusercontent.com/mandliya/algorithms_and_ds_playground/master/image.jpg)

| Current Status|     Stats     |
| :------------: | :----------: |
| Total Problems | 161 |

</center>

### LinkedList Problems
| Problem | Solution |
| :------------ | :----------: |
| Find the nth node of linked list from last. |[nthToLastNode.cpp](linked_list_problems/nthToLastNode.cpp) |
| Add numbers where each digit of the number is represented by node of a linkedlist.  Give output as a linked list. | [add_two_numbers_lists.cpp](linked_list_problems/add_two_numbers_lists.cpp) |
| Swap nodes of a linkedlist without swapping data. |[swapNodesWithoutSwappingData.cpp](linked_list_problems/swapNodesWithoutSwappingData.cpp)|
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
| Using Floyd's cycle finding algorithm, detect if a linkedlist contain cycle, if it does contain cycle, remove the loop | [floyedCycleDetection.cpp](linked_list_problems/floyedCycleDetection.cpp) |
| Sort a linked list using merge sort | [merge_sort.cpp](linked_list_problems/merge_sort.cpp) |
| Given a singly linked list L<sub>0</sub> -> L<sub>1</sub> -> … -> L<sub>n-1</sub> -> L<sub>n</sub>. Rearrange the nodes in the list (in place) so that the new formed list is : L<sub>0</sub> -> L<sub>n</sub> -> L<sub>1</sub> -> L<sub>n-1</sub> -> L<sub>2</sub> -> L<sub>n-2<sub> .... |[rearrange_list.cpp](linked_list_problems/rearrange_list.cpp ) | 

### Include
Include contains single header implementation of data structures and some algorithms.

| Data Structure/Algorithm |     Implementation   |
| :------------: | :----------: |
| Generic Macros and Algorithms like swap, random number generation | [generic.h](include/generic.h) |
| Generic Stack Implementation | [stack.h](include/stack.h) |
| Generic Queue Implementation | [queue.h](include/queue.h) |
| Generic List Implementation  | [list.h](include/list.h)  |
| Binary Search Tree Implementation | [binarySearchTree.h](include/binarySearchTree.h) |
| Quick Sort Implementation | [quickSort.h](include/quickSort.h) |
| Merge Sort Implementation | [mergeSort.h](include/bubbleSort.h)|
| Selection Sort Implementation | [selectionSort.h](include/selectionSort.h) |
| Bubble Sort Implementation | [bubbleSort.h](include/bubbleSort.h) |
| Linux Kernel Double LinkedList Implementation | [double_linked_list.h](include/double_linked_list.h) |
| Generic Graph Implementation (Adjacency List) | [graph.h](include/graph.h) |
| Heap Sort Implementation | [heap_sort.h](include/heap_sort.h)|
| My own string library implementation | [pstring.h](include/pstring.h) [pstring.cpp](include/pstring.cpp)|

### Bit Manipulation Problems

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
| Add two numbers without using any arithmetic operators | [addition_without_operators.cpp](bit_manipulation/addition_without_operators.cpp)|
|Louise and Richard play a game. They have a counter set to N. Louise gets the first turn and the turns alternate thereafter. In the game, they perform the following operations: <ul><li>If N is not a power of 2, reduce the counter by the largest power of 2 less than N.</li></ul><ul><li>If N is a power of 2, reduce the counter by half of N.</li></ul> The resultant value is the new N which is again used for subsequent operations.The game ends when the counter reduces to 1, i.e., N == 1, and the last person to make a valid move wins. <ul><li> Given N, your task is to find the winner of the game. If they set counter to 1, Richard wins, because its Louise' turn and she cannot make a move.</li></ul><ul><li>Input Format : -The first line contains an integer T, the number of testcases. T lines follow. Each line contains N, the initial number set in the counter.</ul></li> |[counter_game.cpp](bit_manipulation/counter_game.cpp)|
|Determine if two integers are of opposite signs.|[check_opposite_signs.cpp](bit_manipulation/check_opposite_signs.cpp)|
|Swap two bits at position p and q of a given integer.| [swapBits.cpp](bit_manipulation/swapBits.cpp)|
|Check if a number is power of 4. | [check_if_power_of_4.cpp](bit_manipulation/check_if_power_of_4.cpp)|


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

### Dynamic Programming Problems
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
|Given values of two nodes in a Binary Search Tree, find the Lowest Common Ancestor (LCA). Assume that both the values exist in the tree.| [lowest-common-ancestor.cpp]
(tree_problems/lowest-common-ancestor.cpp)|
|Given a binary tree (unlike binary search tree), find the Lowest Common Ancestor (LCA).|[lowest-common-ancestor-binary-tree.cpp](tree_problems/lowest-common-ancestor-binary-tree.cpp)|
|Given a binary tree, print out all of its root-to-leaf paths one per line.| [printAllRootToLeafPath.cpp](tree_problems/printAllRootToLeafPath.cpp)
|Determine if a tree is sum tree. A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.| [sumTree.cpp](tree_problems/sumTree.cpp)|
|Convert a tree to sumTree, such that each node is sum of left and right subtree of the original tree.| [convert_to_sum_tree.cpp](tree_problems/convert_to_sum_tree.cpp)|
| Convert a sorted array to balanced binary search tree.| [sortedArrayToBST.cpp](tree_problems/sortedArrayToBST.cpp)|
| Given a binary tree, generate sum of each vertical column.|[verticalSum.cpp](tree_problems/verticalSum.cpp)|
| Given a binary tree and key, node with key exists in tree. Find all the ancestors of the node with key, ancestor here are the nodes which are in straight path from node to root.| [node_ancestors_in_root_path.cpp](tree_problems/node_ancestors_in_root_path.cpp)|
| Given a binary tree and key, return the level of the node with key. Root is at level 1, and if node with key does not exists in tree, return 0| [level_of_node.cpp](tree_problems/level_of_node.cpp)|
| Given a binary tree, find all the paths from root to nodes, whose sum is k. | [k_sum_paths.cpp](tree_problems/k_sum_paths.cpp)|
| Given a binary tree, print its nodes level by level in reverse order. i.e. all nodes present at last level should be printed first followed by nodes of second-last level and so on.. All nodes for any level should be printed from left to right. | [reverseLevelOrderTraversal.cpp](tree_problems/reverseLevelOrderTraversal.cpp) |
| Invert a binary tree, recursively and iteratively.| [invert_a_tree.cpp](tree_problems/invert_a_tree.cpp) |
| Given a Binary Search Tree, find ceil and floor of a given key in it. If the given key lie in the BST, then both floor and ceil is equal to that key, else ceil is equal to next greater key (if any) in the BST and floor is equal to previous greater key (if any) in the BST | [floor_ceil_bst.cpp](tree_problems/floor_ceil_bst.cpp) |

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
| Print the contents of matrix in a spiral order | [matrix_spiral_print.cpp](common_ds_algo_problems/matrix_spiral_print.cpp)
| Given a M x N matrix, rotate it by R rotations anticlockwise, and show the resulting matrix. | [rotate_matrix.cpp](common_ds_algo_problems/rotate_matrix.cpp)|
| Rotate an array by r elements ( left or right ) | [array_rotation.cpp](common_ds_algo_problems/array_rotation.cpp)
| Given an array of repeating/non-repeating intergeres, determine the first non-repeating int in this array | [first_non_repeating_int.cpp](common_ds_algo_problems/first_non_repeating_int.cpp)|
| In Quantumland, there are n cities numbered from 1 to n. Here, c<sub>i</sub> denotes the i<sup>th</sup> city. There are n−1 roads in Quantumland. Here, c<sub>i</sub> and c<sub>i+1</sub> have a bidirectional road between them for each i < n.There is a rumor that Flatland is going to attack Quantumland, and the queen wants to keep her land safe. The road between c<sub>i</sub> and c<sub>i+1</sub> is safe if there is a guard in c<sub>i</sub> or c<sub>i+1</sub>. The queen has already placed a few guards in some of the cities, but she is not sure if they are enough to keep the roads safe. She wants to know the minimum number of new guards she needs to hire. See comments in solution for input/output details. | [save_quantamland.cpp](common_ds_algo_problems/save_quantumland.cpp)|
| You are given an integer N. Find the digits in this number that exactly divide N (division that leaves 0 as remainder) and display their count. For N=24, there are 2 digits (2 & 4). Both of these digits exactly divide 24. So our answer is 2. See more details in header comment of the solution file. | [findDigits.cpp](common_ds_algo_problems/findDigits.cpp)|
| Encrypt and then decrypts a text using Caeser Cipher. | [caeser_cipher.cpp](common_ds_algo_problems/caeser_cipher.cpp)|
| Encrypt and then decrypts a text using Vigenère cipher. | [vigenere_cipher.cpp](common_ds_algo_problems/vigenere_cipher.cpp)|
| Generate binary numbers between 1 to N efficiently. |[n_binary.cpp](common_ds_algo_problems/n_binary.cpp)|
| Implement power function | [power_function.cpp](common_ds_algo_problems/power_function.cpp)|

### Math Problems
| Problem | Solution |
| :------------ | :----------: |
|  Print all the permutations of a string. Example: Permutations of ABC are ABC, ACB, BCA, BAC, CAB, CBA | [string_permutations.cpp](math_problems/string_permutations.cpp) |
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
| Find the first repeating element in an array of integers. Given an array of integers, find the first repeating element in it. We need to find the element that occurs more than once and whose index of first occurrence is smallest.| [firstRepeatingElement.cpp](sort_search_problems/firstRepeatingElement.cpp)|
| Given a list of unsorted integers, A={a<sub>1</sub>,a<sub>2</sub>,…,a<sub>N</sub>}, Find the pair of elements that have the smallest absolute difference between them? If there are multiple pairs, find them all.| [closest_numbers.cpp](sort_search_problems/closest_numbers.cpp)|
| Given a sorted array, determine index of fixed point in this array. If array does not have a fixed point return -1. An array has a fixed point when index of the element is same as index i.e. i == arr[i], Expected time complexity O(logn)| [fixedPoint.cpp](sort_search_problems/fixedPoint.cpp)|
| Find the maximum element in an array which is first increasing and then decreasing. Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}, output : 500. Array may be strictly increasing or decreasing as well. ExpectedTime complexity is O(logn).| [findMaximum.cpp](sort_search_problems/findMaximum.cpp)|
| Given an array of positive and/or negative integers, find a pair in the array whose sum is closest to 0.| [findClosestPairToZero.cpp](sort_search_problems/findClosestPairToZero.cpp)|
| Numeros, the Artist, had two lists A and B, such that B was a permutation of A. Numeros was very proud of these lists. Unfortunately, while transporting them from one exhibition to another, some numbers were left out of A. Can you find the missing numbers? Notes: <ul><li>If a number occurs multiple times in the lists, you must ensure that the frequency of that number in both lists is the same. If that is not the case, then it is also a missing number.</li></ul><ul><li>You have to print all the missing numbers in ascending order.</li></ul><ul><li>Print each missing number once, even if it is missing multiple times.</li></ul><ul><li>The difference between maximum and minimum number in B is less than or equal to 100.</li></ul>. <ul><li> There will be four lines of input: n - the size of the first list, This is followed by n space-separated integers that make up the first list. m - the size of the second list. This is followed by m space-separated integers that make up the second list. Output the missing numbers in ascending order.| [missingNumbers.cpp](sort_search_problems/missingNumbers.cpp)|
| Find the closest pair from two sorted arrays. Given two sorted arrays and a number x, find the pair whose sum is closest to x and the pair has an element from each array. We are given two arrays ar1[0…m-1] and ar2[0..n-1] and a number x, we need to find the pair ar1[i] + ar2[j] such that absolute value of (ar1[i] + ar2[j] – x) is minimum.| [closestPairSorted.cpp](sort_search_problems/closestPairSorted.cpp)|
| Given an array A of n elements, find three indices i, j and k such that A[i]^2 + A[j]^2 = A[K]^2. O(n2) time complexity and O(1) space complexity | [squareSum.cpp](sort_search_problems/squareSum.cpp)|
| Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted. |[minLengthUnsortedArray.cpp](sort_search_problems/minLengthUnsortedArray.cpp)|
| Find the missing number in Arithmetic Progression | [missingNumber2.cpp](sort_search_problems/missingNumber2.cpp) |
| Find the common elements in 3 sorted vectors | [commonIn3Arrays.cpp](sort_search_problems/commonIn3Arrays.cpp) |
| Find all the pairs with a given sum in an unsorted array/vector | [find_pairs_with_sum.cpp](sort_search_problems/find_pairs_with_sum.cpp) |
| Given an array, find peak element in it. A peak element is an element that is greater than its neighbors.| [peak_element.cpp](sort_search_problems/peak_element.cpp) |
| Given a sorted array of distinct non-negative integers, find smallest missing element in it.| [smallest_missing.cpp](sort_search_problems/smallest_missing.cpp)|
| Move all zeros in the vector to the end | [move_zeros.cpp](sort_search_problems/move_zeros.cpp)|


### Graph Problems
| Problem | Solution |
| :------------ | :----------: |
| Depth First Traversal of a Graph | [dfsDemo.cpp](graph_problems/dfsDemo.cpp) |
| Breadth First Traversal of a Graph | [bfsDemo.cpp](graph_problems/bfsDemo.cpp) |
| calculate the shortest distance from the start position (Node S) to all of the other nodes in the graph using Dijkstra algorithm. | [dijkstra-shortest-reach.cpp](graph_problems/dijkstra-shortest-reach.cpp)|
| Calculate total weight of Minimum Spanning Tree of a given graph ( sum of weights of edges which forms MST) using Prim's algorithm | [primsMST.cpp](graph_problems/primsMST.cpp)|
| Print Minimum Spanning Tree( MST ) of a given graph using Kruskal's algorithm.| [kruskalMST.cpp](graph_problems/kruskalMST.cpp)|
| Create a program to generate a Huffman encoding for each character as a table.|[huffman_encoding.cpp] (greedy_problems/huffman_encoding.cpp)|

### Greedy Problems
| Problem | Solution |
| :------------ | :----------: |
| Given two integer arrays, A and B, each containing N integers. You are free to permute the order of the elements in the arrays. Is there an permutation A', B' possible of A and B, such that, A'<sub>i</sub>+B'<sub>i</sub> ≥ K for all i, where A'<sub>i</sub> denotes the i<sup>th</sup> element in the array A' and B'<sub>i</sub> denotes i<sup>th</sup> element in the array B'.| [two_arrays.cpp](greedy_problems/two_arrays.cpp)|
|John is taking orders. The i<sup>th</sup> order is placed by the i<sup>th</sup> customer at t<sub>i</sub> time and it takes d<sub>i</sub> time to procees. What is the order in which the customers will get their orders? (see more details in solutions's comments)|[orders_order.cpp](greedy_problems/orders_order.cpp)|


### Leet code Problems
| Problem | Solution |
| :------------ | :----------: |
| Given a sorted integer array without duplicates, return the summary of its ranges. For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].| [summary_ranges.cpp](leet_code_problems/summary_ranges.cpp)|
| Given a 2D matrix, with following properties <ul><li>Integers in each row are sorted in ascending from left to right.</li></ul><ul><li>Integers in each column are sorted in ascending from top to bottom.</ul></li>|[search2DII.cpp](leet_code_problems/search2DII.cpp)|
| Given an unsorted integer array, find the first missing positive integer.Example: [1,2,0] should return 3 and [3,4,-1,1] should return 2. Expected time complexity O(n) and solution should use constant space| [firstMissingPositiveNum.cpp](leet_code_problems/firstMissingPositiveNum.cpp)|
|Given an unsorted array of integers, find the length of the longest consecutive elements sequence. For example: Given [100, 4, 200, 1, 3, 2]. The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. Algorithm should run in O(n) complexity.| [longestConsecutiveSeq.cpp](leet_code_problems/longestConsecutiveSeq.cpp)|
|Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.| [mergeArrays.cpp](leet_code_problems/mergeArrays.cpp)
|Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index. For example: <ul><li>A = [2,3,1,1,4], return true.</li></ul><ul><li>A = [3,2,1,0,4], return false.</li></ul>| [jumpGame.cpp](leet_code_problems/jumpGame.cpp)|
|Given a positive integer, return its corresponding column title as appear in an Excel sheet. For example 1 -> A, 2 -> B,...26 -> Z, 27 -> AA, 28 -> AB, ...705 -> AAC | [excelColSheetTitle.cpp](leet_code_problems/excelColSheetTitle.cpp)|
|Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].| [moveZeroes.cpp](leet_code_problems/moveZeroes.cpp)|
|Given an array of integers, find if the array contains any duplicates. Function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.| [containsDuplicate.cpp](leet_code_problems/containsDuplicate.cpp)|
| Given a list, rotate the list to the right by k places, where k is non-negative. For example: <ul><li>Given 1->2->3->4->5->NULL and k = 2, return 4->5->1->2->3->NULL</li></ul>| [rotateList.cpp](leet_code_problems/rotateList.cpp)|
| Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.). You have the following 3 operations permitted on a word:<ul><li>Insert a character</li></ul><ul><li>Delete a character.</li></ul><ul><li>Replace a character</li></ul>.|[editDistance.cpp](leet_code_problems/editDistance.cpp)|
|Given a binary tree, Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL. Initially, all next pointers are set to NULL.You may only use constant extra space.You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).| [connectNextPointers.cpp](leet_code_problems/connectNextPointers.cpp)|
|Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. For example, given n = 3, a solution set is *"((()))", "(()())", "(())()", "()(())", "()()()"*| [generate_parenthesis.cpp](leet_code_problems/generate_parenthesis.cpp)|
|Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.For example, Given nums = [0, 1, 3] return 2.| [missing_number.cpp](leet_code_problems/missing_number.cpp)|
|Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). Find the minimum element. You may assume no duplicate exists in the array.| [find_min_rotated.cpp](leet_code_problems/find_min_rotated.cpp)|
|Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.| [threeSumClosest.cpp](leet_code_problems/threeSumClosest.cpp)|
|Given n non-negative integers a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, where each represents a point at coordinate (i, a<sub>i</sub>). n vertical lines are drawn such that the two endpoints of line i is at (i, a<sub>i</sub>) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. Note: You may not slant the container.| [maxArea.cpp](leet_code_problems/maxArea.cpp)|
| Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number. An example is the root-to-leaf path 1->2->3 which represents the number 123. Find the total sum of all root-to-leaf numbers. Example in solution comments | [sumRootToLeafNumbers.cpp](leet_code_problems/sumRootToLeafNumbers.cpp)|
| Say you have an array for which the ith element is the price of a given stock on day i. If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.| [maxProfitStock.cpp](leet_code_problems/maxProfitStock.cpp) |
| Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path. Note: You can only move either down or right at any point in time.| [minPath.cpp](leet_code_problems/minPath.cpp)|
| Count the number of prime numbers less than a non-negative number, n.| [countPrimes.cpp](leet_code_problems/countPrimes.cpp)|
| Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers. Ensure that numbers within the set are sorted in ascending order. Example : for k = 3, n = 9 result would be [[1,2,6], [1,3,5], [2,3,4]], similarly for k = 3, n = 7, result would be [[1,2,4]]. | [combinationSum3.cpp](leet_code_problems/combinationSum3.cpp) |
| Given a non-negative integer num, repeatedly add all its digits until the result has only one digit. For example: Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it. Follow up: Could you do it without any loop/recursion in O(1) runtime?| [addDigits.cpp](leet_code_problems/addDigits.cpp) |
| Given a matrix with cell values 0 or 1. Find the length of the shortest path from (a1, b1) to (a2, b2), such that path can only be constructed through cells which have value 1 and you can only travel in 4 possible directions, i.e. left, right, up and down.|[shortest_path_maze.cpp](leet_code_problems/shortest_path_maze.cpp) |
| The Hamming distance between two integers is the number of positions at which the corresponding bits are different. Given two integers x and y, calculate the Hamming distance.| [hamming_distance.cpp](leet_code_problems/hamming_distance.cpp)|
| Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.| [merge_trees.cpp](leet_code_problems/merge_trees.cpp)|
| Write a function that takes a string as input and reverse only the vowels of a string.|[reverse_vowels.cpp](leet_code_problems/reverse_vowels.cpp)|
| Given a string, sort it in decreasing order based on the frequency of characters.For example: <ul><li>Input: cccbbbbaa Output: bbbcccaa</li></ul>| [sortCharByFrequency.cpp](leet_code_problems/sortCharByFrequency.cpp)|


