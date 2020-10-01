#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int maxCoins(vector<int>& piles) {
    sort(piles.begin(),piles.end());
    int ans=0;
    for(int i=0,j=piles.size()-2;i<j;i++,j-=2)
        ans+=piles[j];
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
    	int N;
    	cin>>N;
    	vector<int> piles(N);
    	for(int i=0;i<N;i++)
    		cin>>piles[i];
    	cout<<maxCoins(piles)<<endl;
    }
}
