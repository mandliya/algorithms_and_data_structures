#include<bits/stdc++.h>

using namespace std;

// Graph using class
class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int V);
    void addEdge(int u, int w);
    void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

// to add edge
void Graph::addEdge(int u, int w){
    adj[u].push_back(w);
    // adj[w].push_back(u); //remove comment to make it undirected graph
}


// Breadth First traversal
void Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int i = 0;i < V; i++)
        visited[i] == false;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        s = q.front();
        q.pop();
        cout<<s<<" ";

        list<int>::iterator i;
        for(i = adj[s].begin(); i!=adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main(){
    Graph g(5);
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 
  
    g.BFS(0);
    cout<<endl;
    return 0;
}
