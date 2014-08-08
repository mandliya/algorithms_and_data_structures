**Day 3 - August 8 2014**

##Traveling Salesman Problem

Traveling Salesman Problem is one of the most well studied problem in combination optimization and operational research. It is an NP-hard problem.

###Problem Statement
Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?


###Naive Solution Approach
One naive way to approach this problem is to generate all (n-1)! permutations of the cities (except the origin city) and then calculate cost for every permutation and keep track of
minimum cost permutation. Our solution would be the permutation with the minimum cost.However the runtime of this approach would be ![alt text](http://www.sciweavers.org/download/Tex2Img_1407505770.jpg "omega")(n!)

###Dynamic Programming Approach
Let **s** be our source node. For every other node **i** , we find the minimum cost path with **s** as the starting point and **i** as ending point and all vertices appearing exactly once. Let the cost of this path be cost(i).The cost of corresponding Cycle would be cost(i) + dist(i, s) where dist(i, s) is the distance from i to s. Finally, we return the minimum of all [cost(i) + dist(i, s)] values.Now, how do we calculate **cost(i)**.

We will calculate cost(i) using dynamic programming approach. Let us define our terms and then recursive sub-problem.

* **s**-Source node
* **i**-All nodes other than source
* **cost(i)**-Minimum cost path with **s** as the starting point and **i** as ending point and all vertices appearing exactly once.
* **dist(i,s)**-The provided distance from i to s.
* Cost of cycle - cost(i) + dist(i,s)
* Our solution would be minimum of \{ cost(i) + dist(i,s) \} 
* Let **C(Set,i)** be the *cost of minimum cost path visiting each vertex in Set exactly once, starting at s and ending at i.*
* We start with all subsets of size 2 and calculate C(Set, i) for all subsets where S is the subset, then we calculate C(Set, i) for all subsets Set of size 3 and so on. Note that **s** must be present in every subset.

	If size of Set is 2, then Set must be {s, i},
 	C(Set, i) = dist(s, i) 
	Else if size of Set is greater than 2.
 	C(Set, i) = min { C(Set-{i}, j) + dis(j, i)} where j belongs to S, j != i and j != s

* For a set of size n, we consider n-2 subsets each of size n-1 such all subsets does not have n<sup>th</sup> in them.
* There will be atmost O(n2<sup>n</sup>) subproblems and each will take linear time to solve.
* There for run time complexity will be O(n<sup>2</sup>2<sup>n</sup>).
* The time complexity is much less than O(n!), but still exponential. Space required is also exponential. So this approach is also infeasible even for slightly higher number of vertices.
* Better approach is to use approximate algorithm.

### References 
http://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
