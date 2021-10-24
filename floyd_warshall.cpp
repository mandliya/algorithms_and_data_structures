/*
 *Floyd Warshall Algorithm: - 

 *We initialize the solution matrix same as the input graph matrix
 as a first step. Then we update the solution matrix by considering 
 all vertices as an intermediate vertex. The idea is to one by one 
 pick all vertices and updates all shortest paths which include the 
 picked vertex as an intermediate vertex in the shortest path. When 
 we pick vertex number k as an intermediate vertex, we already have 
 considered vertices {0, 1, 2, .. k-1} as intermediate vertices. For 
 every pair (i, j) of the source and destination vertices respectively,
 there are two possible cases. 

 * 1) k is not an intermediate vertex in shortest path from i to j. We keep
   the value of dist[i][j] as it is. 
 * 2) k is an intermediate vertex in shortest path from i to j. We update the
   value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]

*/

#include<stdio.h>

#define V 4

#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall (int graph[][V])
{
	int dist[V][V], i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	/* 
	* Add all vertices one by one to the set of intermediate vertices.
	
	---> Before start of an iteration, we have shortest distances between all
	pairs of vertices such that the shortest
	distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.

	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set
	becomes {0, 1, 2, .. k} 

	*/
	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				/* If vertex k is on the shortest path from i to j, 
				 * then update the value of dist[i][j]*/
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

/* Let us create the following weighted graph
			10
	(0)------->(3)
     |	       /|\
	5|		    |
	 |		    | 1
	\|/		    |
	(1)------->(2)
			3		 
*/

int main()
{

	int graph[V][V] = { {0, 5, INF, 10},
						{INF, 0, 3, INF},
						{INF, INF, 0, 1},
						{INF, INF, INF, 0}
					};

	floydWarshall(graph);
	return 0;
}
