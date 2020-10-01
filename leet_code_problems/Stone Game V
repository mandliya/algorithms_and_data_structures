#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int sum[500][500],dp[500][500];
int func(int s, int e)
{
    if(s>=e)
        return 0;
    
    if(dp[s][e]==-1)
    {
        int ans=0;
        for(int i=s;i<e;i++)
        {
            int x=sum[s][i];
            int y=sum[i+1][e];
            if(x<y)
                ans=max(ans,func(s,i)+x);
            else if(x>y)
                ans=max(ans,func(i+1,e)+y);
            else
                ans=max(ans,max(func(s,i)+x, func(i+1,e)+y));
        }
        dp[s][e]=ans;
    }
    return dp[s][e];
}
int stoneGameV(vector<int>& stoneValue) {
    int N=stoneValue.size();
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            dp[i][j]=-1;
            sum[i][j]=0;
        }
    
    for(int i=0;i<N;i++)
    {
        int x=0;
        for(int j=i;j<N;j++)
        {
            x+=stoneValue[j];
            sum[i][j]=x;
        }
    }
    
    return func(0,N-1);
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
    	vector<int> stoneValue(N);
    	for(int i=0;i<N;i++)
    		cin>>stoneValue[i];
    	cout<<stoneGameV(stoneValue)<<endl;
    }
}
