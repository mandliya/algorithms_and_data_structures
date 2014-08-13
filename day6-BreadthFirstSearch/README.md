**Day 6 - August 13 2014**

##Breadth First Search

Breadth First Search (BFS) is one of the strategies for searching a graph. The basic approach contains two steps:

* Visit and inspect the node.
* Now visit the unvisited neighbouring nodes of the current node
* Repeat the above steps, till we have visited all nodes.

###Basic Approach

We use a queue data structure to store nodes as we traverse the graph

* Enqueue the current node.
* Dequeue the node and examine it
  * If this is the node we have been searching, quit and return
  * Other enqueue any unvisited neighbour nodes to this node.
* If the queue is empty, every node has been examined quit the search and return "not found"
* If queue is not empty, go to step 2

###Complexity

**Space Complexity:** Space requirement may vary depending on how we store our graph. In our adjacency list implementation we use **O(|V| + |E|)** space, however in adjacency matrix representation it would be **O(|V|<sup>2</sup>)**.

**Time Complexity:** The time complexity would be **O(|V|+|E|)** as we will explore each vertex and edge at least once in worst case. 

###Reference
http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
