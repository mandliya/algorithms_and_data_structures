#include<iostream>
#include<stack>
using namespace std;

int celeb(int n,int **ar)
{
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		s.push(i);
	}
	
	while(s.size()>=2)
	{
		int i=s.top();
		s.pop();
		int j=s.top();
		s.pop();
		if(ar[i][j]==1)  //i knows j --> i can not be celeb.
		{
			s.push(j);
		}
		else
		{ //i does not know j --> j can not be celeb.
			s.push(i);
		}
	}
	
	int pot=s.top();
	s.pop();
	
	for(int i=0;i<n;i++)
	{
		if(pot!=i)
		{
			if(ar[i][pot]==0 || ar[pot][i]==1 )
			{
				return 0;
			}
		}
	}
	return pot;
}
int main()
{
	int n;
	cin>>n;
	int **ar=new int*[n];
	for(int i=0;i<n;i++)
	{
		ar[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>ar[i][j];
		}
	}
	int ans=celeb(n,ar);
	if(ans==0)
	{
		cout<<"none"<<endl;
	}
	else
		cout<<ans<<endl;
}
