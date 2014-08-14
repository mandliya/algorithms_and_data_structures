**Day 6 - August 14 2014**

##Depth First Search

Depth First Search(DFS) is an algorithm for traversing a graph or tree from a source node ( root in case of tree and any random node in graph). When we start at source, we explore as far as possible before backtracking. Unlike Breadth First Search, instead of traversing through all neighbouring nodes first, we explore the nodes depth wise. We finish exploring the first neighbouring node and its depth and then move to next one. So Basically DFS is uninformed search which progresses by exploring the first child node (or neighbouring node in a graph) that appears and thus going deeper and deeper until goal node is found or until it hits a node that has no unvisited neighbours(or no children in a tree). Then search backtracks, returning to most recent node it has not yet finished exploring. This can be implemented recursively or it could be implemented iteratively using a stack.

##Complexity

**Space Complexity** In the worst case, The space compleixity would be same as BFS, it depends on the implementation of the graph. For an adjacency list implementation it should be **O(|V|+|E|)** space, and similarly for an adjacency matrix implementation it would be **O(|V|<sup>2</sup>)** . 

**Time Complexity** In the worst case, time complexity would be **O(|V|+|E|)**, as we may have to explore every single vertex and edge before we reach our destination.

##Applications

Since BFS and DFS have same time complexities, the choice of which of these two algorithms to use depends less on their complexity and more on the different properties of the vertex orderings the two algorithms produce. Example, If you already have knowledge that node you are searching for is not far from the source, A breadth first search would be a better idea, similarly if you know the source you are looking for may be one of the leaf( or at deeper level) DFS would be better choice. However often it is not known beforehand.

Major applications of DFS include:

1. Detecting a cycle in a graph (We will do it later)
2. Path Finding ( Does a path exist from a source to a destination)
3. Generate Minimum spanning tree, and all pair shortest path tree
4. Topological Sorting (we will do it later)
5. To test if graph is bipartite
6. Finding strongly connected components of a graph (We will do it later)

##Reference
http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
