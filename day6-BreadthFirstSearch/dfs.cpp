
#include<iostream>
#include<list>
#include<deque>
#include<iterator>

using namespace std;


//Reference source : http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/d
//A class representing Graph, it contains number of vertices and adjancency matrix.
class Graph{
	int V;					//number of vertices
	list<int> *adj;				//Pointer to a list containing Adjacency list
	
	public:
		Graph(int v);			//Constructor to initialize graph
		void addEdge(int x, int y);     //add edge between vertex x and y
		void BFS(int s);		//Perform breadth first search from source s
		~Graph();
};


Graph::Graph(int v):V(v),adj(new list<int>[V]){}

void Graph::addEdge(int x, int y){
	adj[x].push_back(y);
}

void Graph::BFS(int s){
	bool *visited = new bool[V];
	for(int i =0; i < V; ++i){
		visited[i] = false;
	}
	list<int> q;
	visited[s]= true;
	q.push_back(s);
	int temp;
	list<int>::iterator it;
	while(!q.empty()){
		temp = q.front();
		cout<<temp<<" ";
		q.pop_front();
		for(it = adj[temp].begin(); it != adj[temp].end(); ++it){
			if(!visited[*it]){
				visited[*it] = true;
				q.push_back(*it);
			} 
		}	
	}
	cout<<endl;
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
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
