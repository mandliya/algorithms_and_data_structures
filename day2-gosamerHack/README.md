##Problem:Given an array of size n, how do you find all the possible subsets of the array of size k?

###Approach:
This problem could be approached in multiple ways however, I am going to go with bitwise manipulations, using this cool bit manipulation trick called Gosper hack.
The the problem could be rephrased as we want to generate all n-bit numbers who have exactly k-bits set,and thus O(n 2^n) complexity. Before jumping to those indecipherable 
Gosper hack code lines, let us start from scratch and learn bit-wise manipulations real quick.

###Bitwise Operators.

* **Bitwise OR** : It is represented with **|**. The result of a | b has a set bit at position *i* if and only if either *a* or *b* has a set bit at position *i*.
* **Bitwise AND**: It is represented with **&**. The result of a & b has a set bit at position *i* if and only if both *a* and *b* has set bit at position *i*
* **Bitwise exclusive or (xor)**: The result of a ^ b has a set bit at position *i* if and only if one of  *a* or *b* has set bit at position *i* and other doesn\`t. 
* **Bitwise left shift** The result of a << x is actually a * 2<sub>x</sub> 

