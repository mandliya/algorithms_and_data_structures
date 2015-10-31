/**
 * Given an undirected weighted connected graph, it is required to find the Really Special SubTree in it.
 * The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and
 * There is only one exclusive path from a node to every other node.
 * The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
 * While creating the Really Special SubTree, start of by picking the edge with smallest weight.
 * If there are edges of equal weight available at an instant, then the edge to be chosen first among them is the
 * one with minimum value of sum of the following expression :
 * u + wt + v , where u and v are the node numbers of the corresponding edge and wt is the weight.
 * Even then if there is a collision, choose any one of them.
 * While doing the above, ensure that no cycle is formed while picking up edges.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int x;
    int y;
    int r;
    Edge( int a, int b, int c) : x{ a-1 }, y{ b-1 }, r{ c } { }
};

bool sortComparer( Edge a, Edge b ) {
    if ( a.r < b.r ) {
        return true;
    } else if ( a.r > b.r ) {
        return false;
    }
    return ( a.x + a.y + a.r  <= b.x + b.y + b.r);
}

class Graph {
  public:
    Graph(int N, int M) : V{ N }, E{ M }, edges(E, Edge(0,0,0)) { }
    void getEdges();
    void sortEdges();
    int numberOfVertices() { return V; }
    int numberOfEdges() { return E; }
    std::vector<Edge>  kruskalMST();
  private:
    int V; //number of vertices
    int E; //number of Edges
    std::vector<Edge> edges;
};

void Graph::getEdges( ) {
    int x, y, r;
    for ( int i = 0; i < E; ++i ) {
        std::cin >> x >> y >> r;
        edges.push_back(Edge(x, y, r));
    }
}

void Graph::sortEdges() {
    std::sort(edges.begin(), edges.end(), sortComparer);
}

struct subset {
  int rank;
  int parent;
};

int find( std::vector<subset> & subsets, int i ) {
    if ( subsets[i].parent != i ) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void union_edges( std::vector<subset> & subsets, int a, int b) {
    int aroot = find(subsets, a);
    int broot = find(subsets, b);
    if ( subsets[aroot].rank < subsets[broot].rank ) {
        subsets[aroot].parent = broot;
    } else if ( subsets[aroot].rank > subsets[broot].rank ) {
        subsets[broot].parent = aroot;
    } else {
        subsets[broot].parent = aroot;
        subsets[broot].rank++;
    }
}

std::vector<Edge> Graph::kruskalMST() {
    sortEdges();
    std::vector<subset> subsets(numberOfEdges());
    for ( int i = 0; i < numberOfEdges(); ++i ) {
        subsets[i].rank = 0;
        subsets[i].parent = i;
    }
    int e = 0;
    int i = 0;
	std::vector<Edge> resultMST;
    while ( e < numberOfVertices() - 1) {
        Edge next_edge = edges[i++];
        int a = find( subsets, next_edge.x );
        int b = find( subsets, next_edge.y );
        if ( a != b ) {
			resultMST.push_back(next_edge);
            union_edges(subsets, a, b);
            ++e;
        }
    }
    return resultMST;
}

void printMST(std::vector<Edge> & MST) {
	std::cout << std::endl << "Given Graph's MST:\n";
	std::cout << "V1\tV2\tWeight\n";
	for ( auto e : MST ) {
		std::cout << e.x + 1 << "\t" << e.y + 1 << "\t" << e.r << std::endl;
	}
	std::cout << std::endl;
}

void inputFormat() {
	std::cout << "Input Format:\nFirst line has two integers N, denoting the number of nodes in the graph and M,"
				 "denoting the number of edges in the graph\n"
				 "The next M lines each consist of three space separated integers x y r,\n"
				 "where x and y denote the two nodes between which the undirected edge exists,"
				 "r denotes the weight of edge between the corresponding nodes.\n";
}

int main() {
    int N, M;
	inputFormat();
    std::cin >> N >> M;
    Graph G(N, M);
    G.getEdges();
	std::vector<Edge> MST = G.kruskalMST();
	printMST(MST);
    return 0;
}


