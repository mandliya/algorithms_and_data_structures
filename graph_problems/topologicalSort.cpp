#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<vector<int>> adj(N);
bool visited[N];
vector<int> top_sort;
void dfs(int src){
	visited[src]=true;
	for(auto v:adj[src]){
		if(!visited[v]) dfs(v);
	}
	top_sort.push_back(src);
}
int main(){
	int n,m;
	cin>>n>>m;
	memset(visited,false,sizeof(visited));
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	for(int i=0;i<n;i++){
		if(!visited[i]) dfs(i);
	}
	reverse(top_sort.begin(),top_sort.end());
	for(int i=0;i<top_sort.size();i++){
		cout<<top_sort[i]<<" ";
	}
}
