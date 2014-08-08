##Traveling Salesman Problem

Traveling Salesman Problem is one of the most well studied problem in combination optimization and operational research. It is an NP-hard problem.

###Problem Statement
Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?


###Solution Approach
One naive way to approach this problem is to generate all (n-1)! permutations of the cities (except the origin city) and then calculate cost for every permutation and keep track of
minimum cost permutation. Our solution would be the permutation with the minimum cost.However the runtime of this approach would be [id]:http://bit.ly/1B0hQFE (n!)


