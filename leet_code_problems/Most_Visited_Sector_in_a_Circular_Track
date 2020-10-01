#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> mostVisited(int n, vector<int>& rounds) {
    int N=rounds.size();
    int count[n+1];
    for(int i=0;i<n;i++)
        count[i]=0;
    
    int start=rounds[0]-1;
    int i=1;
    while(i<N)
    {
        int end=rounds[i]-1;
        while(start!=end)
        {
            count[start]++;
            start=(start+1)%n;
        }
        i++;
    }
    count[start]++;
    int maxi=0;
    for(int i=0;i<n;i++)
        maxi=max(maxi,count[i]);
    vector<int> ans;
    for(int i=0;i<n;i++)
        if(maxi==count[i])
            ans.push_back(i+1);
    return ans;   
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
    	int N,M;
    	cin>>N>>M;
    	vector<int> rounds(M);
    	for(int i=0;i<M;i++)
    		cin>>rounds[i];
    	vector<int> ans=mostVisited(N,rounds);
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    	
    }
}
