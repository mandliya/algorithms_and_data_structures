#include<iostream>
#include<list>
#include<iterator>

class Graph{
		int V;						//Number of vertices
		std::list<int> *adj; 				//A pointer to an array containing adjacency list
		void DFSHelper(int s, bool visited[]);		//A helper function to perform Depth first Search
	public:
		Graph(int v);					//A constructor to initialize graph
		void addEdge(int x, int y);			//For adding edges in the graph
		void DFS(int s);				//To perform DFS from source 's'
		~Graph();
};

Graph::Graph(int v):V(v),adj(new std::list<int>[v]) {}

void Graph::addEdge(int x, int y){
	adj[x].push_back(y);
}

void Graph::DFSHelper(int s, bool visited[]){
	visited[s] = true;
	std::cout<<s<<" ";
	std::list<int>::iterator it;
	for( it = adj[s].begin(); it != adj[s].end(); ++it){
		if( !visited[*it])
			DFSHelper(*it, visited);
	}
}

void Graph::DFS(int s){
	bool *visited = new bool[V];
	for( int i = 0; i < V; ++i)
		visited[i] = false;
	DFSHelper(s, visited);
}

Graph::~Graph(){
	delete[] adj;
}



int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    std::cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}
