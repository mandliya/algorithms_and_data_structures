##Problem:Given an array of size n, how do you find all the possible subsets of the array of size k?

###Approach:
This problem could be approached in multiple ways however, I am going to go with bitwise manipulations, using this cool bit manipulation trick called Gosper hack.
The the problem could be rephrased as we want to generate all n-bit numbers who have exactly k-bits set,and thus O(n 2^n) complexity. Before jumping to those indecipherable 
Gosper hack code lines, let us start from scratch and learn bit-wise manipulations real quick.

###Bitwise Operators.

* **Bitwise OR**: It is represented with **|**. 

