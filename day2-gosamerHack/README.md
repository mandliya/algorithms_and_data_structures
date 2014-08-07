##Problem:Given an array of size n, how do you find all the possible subsets of the array of size k?

###Solution reference:http://read.seas.harvard.edu/cs207/2012/ 

###Approach:
This problem could be approached in multiple ways however, I am going to go with bitwise manipulations, using this cool bit manipulation trick called Gosper hack.
The the problem could be rephrased as we want to generate all n-bit numbers who have exactly k-bits set,and thus O(n 2^n) complexity. Before jumping to those indecipherable 
Gosper hack code lines, let us start from scratch and learn bit-wise manipulations real quick.



###Bitwise Operators.

* **Bitwise OR** : It is represented with **|**. The result of a | b has a set bit at position *i* if and only if either *a* or *b* has a set bit at position *i*.
* **Bitwise AND**: It is represented with **&**. The result of a & b has a set bit at position *i* if and only if both *a* and *b* has set bit at position *i*
* **Bitwise exclusive or (xor)**: It is represented with **^**. The result of a ^ b has a set bit at position *i* if and only if one of  *a* or *b* has set bit at position *i* and other doesn\`t. 
* **Bitwise right shift** It is represented with **>>**. The result of a >> x is actually a / 2<sup>x</sup>. The lower x bits are removed and 0 bits are shifted at higher order, it is usually faster to compute.
* **Bitwise left shift**: It is representeed with **<<**.  The result of a << x is actually a * 2<sup>x</sup>. 
* **Bitwise Complement**: It is represented with **~**. The result of **~a** contains 0 bit at every 1 bit position in a and 1 in every 0 bit position.

###Bitwise significance of -x ( negative x).
-x is unique y such that x + y = 0. If *x* is 64 bit, then y or -x here would be 2<sup>64</sup>-x, for then x + y = 2^64, which overflows and produce 0. Therefore for instance
-2 is 18446744073709551614 on a 64-bit machine, since

	2 + 18446744073709551614 == 18446744073709551616 == 2<sup>64</sup> == 0 
	
on a 64-bit machine.Another thing to notice is -x is same as (~x + 1). If we negate x by flipping all bits and then add 1. example.(for simplicity let us assume integers are stored in 1 byte ( 8 bits)

	6 =  0 0 0 0 0 1 1 0 

If we flip all bits  we get ~6 which is 249. 

	~6 = 1 1 1 1 1 0 0 1

If we add x + ~x, the result will always have all 1s.

	   6 =  0 0 0 0 0 1 1 0 
	+ ~6 =  1 1 1 1 1 0 0 1
	-------------------------
	        1 1 1 1 1 1 1 1  

###Gosper's hack

To get the next higher number with the same number of 1 bits:

	unsigned nexthi_same_count_ones(unsigned a) {
		 /* works for any word length */
  		unsigned c = (a & -a);
  		unsigned r = a+c;
		return (((r ^ a) >> 2) / c) | r);
	}



