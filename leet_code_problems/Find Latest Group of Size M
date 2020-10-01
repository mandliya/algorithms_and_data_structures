#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int arr[100001],size_[100001],count_[100001],mark[100001];
int root(int x)
{
    while(arr[x]!=x)
        x=arr[x];
    return x;
}
void func(int x, int y)
{
    int root_x=root(x);
    int root_y=root(y);
    if(root_x==root_y)
        return;
    if(size_[root_x]<=size_[root_y])
    {
        count_[size_[root_x]]--;
        count_[size_[root_y]]--;
        size_[root_y]+=size_[root_x];
        size_[root_x]=0;
        count_[0]++;
        count_[size_[root_y]]++;
        arr[root_x]=root_y;
    }
    else
    {
        count_[size_[root_x]]--;
        count_[size_[root_y]]--;
        size_[root_x]+=size_[root_y];
        size_[root_y]=0;
        count_[size_[root_x]]++;
        arr[root_y]=root_x;
    }
}
int findLatestStep(vector<int>& A, int m) {
    int N=A.size();
    for(int i=1;i<=N;i++)
    {
        arr[i]=i;
        size_[i]=0;
        count_[i]=0;
        mark[i]=0;
    }
    count_[0]=N;
    
    int ans=-1;
    for(int i=0;i<N;i++)
    {
        int x=A[i];
        size_[x]=1;
        count_[0]--;
        count_[1]++;
        mark[x]=1;
        if(x-1>=1 && mark[x-1])
            func(x-1,x);
        if(x+1<=N && mark[x+1])
            func(x+1,x);
        if(count_[m]!=0)
            ans=i+1;
    }
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
    	vector<int> A(N);
    	for(int i=0;i<N;i++)
    		cin>>A[i];
    	int m;
    	cin>>m;
    	cout<<findLatestStep(A,m)<<endl;
    }
}
