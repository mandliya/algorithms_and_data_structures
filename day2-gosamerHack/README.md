##Problem:Given an array of size n, how do you find all the possible subsets of the array of size k?

###Solution reference:http://read.seas.harvard.edu/cs207/2012/ 

###Approach:
This problem could be approached in multiple ways however, I am going to go with bitwise manipulations, using this cool bit manipulation trick called Gosper hack.
The the problem could be rephrased as we want to generate all n-bit numbers who have exactly k-bits set,and thus O(n 2^n) complexity.Basically, each bit string will represent a subset
The possible members of a set are listed in a linear array, and a subset is represented by a word or sequence of words in which bit i is on if member i is in the subset. Before jumping to those indecipherable Gosper hack code lines, let us start from scratch and learn bit-wise manipulations real quick.



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

Thus, x + ~x is always the largest representable integer of x\`s type. Add 1 to that number and you get 0: the addition in the ones place causes a carry that wipes out all the higher 1s!

           6 =  0 0 0 0 0 1 1 0
        + ~6 =  1 1 1 1 1 0 0 1
        -------------------------
                1 1 1 1 1 1 1 1
	+  1 =  0 0 0 0 0 0 0 1
        -------------------------
	    (1)	0 0 0 0 0 0 0 0	

The above representation of negative number i. e. (-2 represented as 18446744073709551614 in a 64-bit machine ) is called *Two\`s complement arithmatic* and is used in almost all the machines we use.

Thus thing worth remembering is
	
	-x = ~x + 1

###How do we get lowest set bit?

We can get lowest set bit in a number using the **x & -x** or to say  ** x & (~x + 1) **. Let us see some examples.
	
	    1 == 0 0 0 0 0 0 0 1
	&  -1 == 1 1 1 1 1 1 1 1
	-------------------------
	    1 == 0 0 0 0 0 0 0 1

	    6 == 0 0 0 0 0 1 1 0
	&  -6 == 1 1 1 1 1 0 1 0
	------------------------
	    2 == 0 0 0 0 0 0 1 0


	   23 == 0 0 0 1 0 1 1 1
	& -23 == 1 1 1 0 1 0 0 1
	-------------------------
	    1 == 0 0 0 0 0 0 0 1

Clearly, **x & -x** will always give you lowest set bit in number.



###Gosper's hack

To get the next higher number with the same number of 1 bits i.e is to get the next subset from our current subset value:

	unsigned nexthi_same_count_ones(unsigned a) {
		 /* works for any word length */
  		unsigned c = (a & -a);
  		unsigned r = a+c;
		return (((r ^ a) >> 2) / c) | r);
	}


Let us try understanding it line by line. 

	First Step: unsigned c = (a & -a);

From above discussion we clearly know c in binary represent the lowest set 1 bit in a;
 
	Next Step : unsigned r = a + c;

It is basically doing r = a + (a & ~a).Since a & -a is the least significant one bit of a, we know that the addition will flip that bit back to 0. 
For example, take a == 6 and 22
	
		 	6 == 0 0 0 0 1 1 0
	 	 + 6 & -6 == 0 0 0 0 0 1 0
	     -----------------------------
	     6 + (6 & -6) == 0 0 0 1 0 0 0	

	 	       22 == 0 0 0 1 0 1 1 0
	     + (22 & -22) == 0 0 0 0 0 0 1 0
	     -------------------------------
         	       24 == 0 0 0 1 1 0 0 0
	
The single added bit ripples up through a series of 1 bits via carries. The ripple stops when the carry process reaches a 0 bit, which it flips to 1

	Next step : r ^ a

Now, in this step we are discarding all higher order bits. Let us try this on 22

	    22 + (22 & -22) == 0 0 0 1 1 0 0 0

	 ^  22              == 0 0 0 1 0 1 1 0
	---------------------------------------	
		r^a	    == 0 0 0 0 1 1 1 0

Next step is to left shift by two
  
	Next step : (r ^ a)>>2

Shifting by 2 might actually shift off one or two of the 1 bits
	
	(r^a)>>2 = 0 0 0 0 0 0 1 1

Next step is divide, and we are dividing by c (a & -a) which we know is a power of 2. continuing our example of 22. Here actually this division right adjusts the 1s and make them equal to previously set bits.

	((r^a)>>2)/c = 0 0 0 0 0 0 0 1

Now, we will or it with r
	((r^a)>>2)/c = 0 0 0 0 0 0 0 1
	|          r = 0 0 0 1 1 0 0 0
 	------------------------------
	NEXT Subset  = 0 0 0 1 1 0 0 1


The CPP file executes and return a vector, each containing a number which represent a subset of size k ( ie a number with k bits set) for size n.
For an array = {1,2,3,4,5} it generates all possible subsets of size 3

	Printing all combinations of size 3 of {1,2,3,4,5}:
	1 2 3
	1 2 4
	1 3 4
	2 3 4
	1 2 5
	1 3 5
	2 3 5
	1 4 5
	2 4 5
	3 4 5

	 
