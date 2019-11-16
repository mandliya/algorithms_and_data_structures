/*
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. 
We can find all strongly connected components of a directed graph in O(V+E) time using Kosaraju’s algorithm. (V:vertices, E:edges)
Kosaraju's Algorithm:
1) Create an empty stack ‘S’ and do DFS traversal of a graph. 
In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack.
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty. 
Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). 
The DFS starting from v prints strongly connected component of v.
*/
//Code:

#include<bits/stdc++.h>
using namespace std;
void print(vector<int> a[],int V)
{
    for(int i=0;i<V;i++)
    {
        if(!a[i].empty())
            cout<<"i="<<i<<"-->";
        for(int j=0;j<a[i].size();j++)
            cout<<a[i][j]<<" ";
        if(!a[i].empty())
            cout<<endl;
    }
}
void calc_time(int v,stack<int> &st,bool vis[],vector<int> adj[])
{
    vis[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(vis[*i]==false)
            calc_time(*i,st,vis,adj);
    }
    st.push(v);
}
void dfs(int v,bool vis[],vector<int> grev[])
{
    vis[v]=true;
    // cout<<v<<" ";
    for(auto i=grev[v].begin();i!=grev[v].end();i++)
    {
        if(vis[*i]==false)
            dfs(*i,vis,grev);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // print(adj,V);
    bool vis[V]={};
    stack<int> st;
    for(int v=0;v<V;v++)
    {
        if(vis[v]==false)
            calc_time(v,st,vis,adj);
    }
    // cout<<"stack_size="<<st.size()<<endl;
    //making new graph (grev) with reverse edges as in adj[]
    vector<int> grev[V];
    for(int i=0;i<V+1;i++)
    {
        for(auto j=adj[i].begin();j!=adj[i].end();j++)
        {
            grev[*j].push_back(i);
        }
    }
    // cout<<"grev="<<endl;
    // print(grev,V);
    //reinitialise vis to 0
    for(int i=0;i<V;i++)
        vis[i]=false;
    int cnt_scc=0;
    while(!st.empty())
    {
        int t=st.top();
        st.pop();
        if(vis[t]==false)
        {
            dfs(t,vis,grev);
            cnt_scc++;
        }
    }
    // cout<<"cnt_scc="<<cnt_scc<<endl;
    return cnt_scc;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}
