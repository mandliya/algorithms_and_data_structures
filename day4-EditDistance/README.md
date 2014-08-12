**Day 1 - August 11 2014**

###Problem Statement
Given two strings of size m and n (say S1 and S2) and set of operations Replace(R), Insert(I) and delete(D) all with individual cost. Find the minimum number of edit operations (R, I or D)  required to convert one string to another.

This is often used in **text editing**.

###Approach
This is a perfect dynamic programming approach question. Let us identify the subproblems.
Let us consider edit distance for a part of problem. Let us say suppose we have two strings S1 (of size m) and S2 (of size n). Let us consider two prefix of these. P1[1..i] and P2[1..j], where 1 < i < m and 1 < j < n. This is just solving smaller instance of our final problem, let us denote the edit cost with E(i,j). Our goal is finding E(m,n) and minimizing thecost.

Let us change 'SUNDAY' to 'SATURDAY' with minimum edit distance i.e. with minimum edit cost.Let us pick i=2 and j=4. Therefore, prefix strings would be SU and SATU (assume string index start at 1). The rightmost characters can be aligned in 3 different ways.

* *Case 1:* Align characters U and U, They are same, no edit required. Now we will solve smaller problem of i = 1, and j = 3. E(i-1, j-1)

* *Case 2:* Align right from the first string, and no character from the second string. i.e. 'U' and '-' (Here '-' represents no character). Therefore we need a delete(D) operation. Now we need to solve problem of i=1 and j = 4. E(i-1, j)

* *Case 3:* Aligh right character from the second string, and no character from the first string. We will need a insert(I) operation, and we will be left with the sub-problem of i = 2, j= 3. E(i, j-1)

Combining all subproblems, we can say, minimum cost of aligning prefix strings ending at i and j given by

	E(i,j) = min( {E(i-1,j)+D}, {E(i, j-1)+I}, {E(i-1,j-1) + R if i,j characters are not same} )

**Base case:**
*E(0, 0) = 0 
*E(i, 0) = i
*E(0, j) = j

###Complexity
Without dynamic programming approach this would be exponential complexity, as we will be solving same sub-problems again and again for successive subsitution. Using **recursive + memoization** i.e. dynamic programming approach, we will store the results of a sub-problem and will use its result instead of solving it again.

A two dimensional array formed by the strings can keep track of the minimum cost till the current character comparison. The time complexity of dynamic programming method is O(mn) as we need to construct the table fully. The space complexity is also O(mn)

###References
http://www.csse.monash.edu.au/~lloyd/tildeAlgDS/Dynamic/Edit/ 

