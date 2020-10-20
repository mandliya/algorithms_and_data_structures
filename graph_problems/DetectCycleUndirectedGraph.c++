#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> g[], int start,vector<int> &visited) {
    visited[start]=1;
    int flag=0,len=0;
    for(int x:g[start]){
        if(!visited[x]){
            flag=1;
            if(dfs(g,x,visited))
                return true;
        }
        else{
            len++;
        }
        
        if(len>1)
            return true;
    }
    
    return false;
}

bool isCyclic(vector<int> g[], int n)
{
  
    vector<int> visited(n);
    int i;
    for(i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(g,i,visited))
                return true;
        }
        
    }
return false;
}


int main(){

 
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    cout<<isCyclic(adj,v)<<"\n";

}