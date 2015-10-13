/**
 * Minimum spanning tree using Prim's algorithm.
 * Approach greedy
 * Calculate the weight of minimum spanning tree(sum of weight of edges of MST)
 * and print the edges which makes MST.
 * Input format:
 * ROW 1 :: V - number of vertices, E - number of Edges.
 * Next E lines give details of each edge in format x y w.
 * where x is start of edge, y is end of edge and w is weight of xy edge
 * After that, S - Index of the starting point of finding the MST.
 * all the input is not 0 indexed.
 */



#include <iostream>
#include <limits>

const int MIN = std::numeric_limits<int>::min();
const int MAX = std::numeric_limits<int>::max();


/**
 * Print the Minimum spanning tree
 */
void printMST( int ** graph, int * MST, int V ) {
	std::cout << " Edge    Weight \n";
	for ( int v = 0; v < V; ++v ) {
		if (MST[v] != -1 && graph[v][MST[v]] != -1 ) {
			std::cout << v+1 << "<-->" << MST[v]+1 << "   " << graph[v][MST[v]] << std::endl;
		}
	}
}


/**
 * minKey
 * returns the index of the vertex which is not yet part of MST
 * and has minimum key.
 */

int minKey( int * keys, bool * inMST, int V ) {
	int min = MAX, minIndex;
	for ( int v = 0; v < V; ++v ) {
		if ( inMST[v] == false && min > keys[v] ) {
			minIndex = v;
			min = keys[v];
		}
	}
	return minIndex;
}


/**
 * primsMSTWeight
 * returns the weight of the minimum spanning tree of the graph
 * Args:
 * graph: adjacency matrix of the graph
 * V :    Total number of vertices in the graph
 * S :	  Starting index of MST
 */
int primsMSTWeight( int ** graph, int V, int S, int * MST)
{
	int * key = new int[V];
	bool * inMST = new bool[V];

	for ( int v = 0; v < V; ++v ) {
		inMST[v] = false;
		key[v] = MAX;
	}

	key[S] = 0;
	for ( int count = 0; count < V-1; ++count ) {
		int u = minKey(key, inMST, V);
		inMST[u] = true;
		for ( int v = 0; v < V; ++v ) {
			if ( (graph[u][v] != -1) && (inMST[v] == false) && (key[v] > graph[u][v]) ) {
				key[v] = graph[u][v];
				MST[v] = u;
			}
		}
	}

	int sum = 0;
	for ( int v = 0 ;v < V; ++v ) {
		if ( MST[V] != -1  && graph[v][MST[v]] != -1 ) {
			sum += graph[v][MST[v]];
		}
	}
	delete[] key;
	delete[] inMST;
	return sum;
}


int main()
{
	int V, E, x, y, w, S;
	/**
	 * V -- number of vertices
	 * E -- number of edges
	 * xy-- edge with endpoints x and y
	 * w -- weight of edge
	 * S -- Starting index
	 */

	std::cin >> V >> E;
	int ** graph = new int*[V];
	for ( int v = 0; v < V; ++v ) {
		graph[v] = new int[V];
		for ( int w = 0; w < V; ++w ) {
			graph[v][w] = -1;
		}
	}

	for ( int i = 0; i < E; ++i ) {
		std::cin >> x >> y >> w;
		if ( graph[x-1][y-1] == -1 ||
			 ( (graph[x-1][y-1] > 0) && (graph[x-1][y-1] > w ))) {
			graph[x-1][y-1] = w;
			graph[y-1][x-1] = w;
		}
	}

	std::cin >> S;
	int * MST = new int[V];
	MST[S-1] = -1;
	std::cout << "Min Spanning tree weight " << primsMSTWeight(graph, V, S-1, MST) << std::endl;
	std::cout << "Min Spanning tree:\n";
	printMST(graph, MST, V);
	return 0;
}
