#include<iostream>
#include<stack>
using namespace std;

int operation(int val1,int val2,char ch)
{
	if(ch=='+')
	{
		return val1+val2;
	}
	else if(ch=='-')
	{
		return val1-val2;
	}
	else if(ch=='*')
	{
		return val1*val2;
	}
	else
	{
		return val1/val2;
	}
}

void prefixConversion(string s)
{
	stack<int> val;
	stack<string> in;
	stack<string> post;
	
	for(int i=s.size()-1;i>=0;i--)
	{
		char ch=s[i];
		if(ch=='+'|| ch=='-' ||ch=='*'|| ch=='/')
		{
			int val1=val.top();
			val.pop();
			int val2=val.top();
			val.pop();
			int ans=operation(val1,val2,ch);
			val.push(ans);
			
			string in1=in.top();
			in.pop();
			string in2=in.top();
			in.pop();
			string inAns='('+in1+ch+in2+')';
			in.push(inAns);
			
			string post1=post.top();
			post.pop();
			string post2=post.top();
			post.pop();
			string postAns=post1+post2+ch;
			post.push(postAns);
		}
		else if(ch==' ')
		{
			continue;
		}
		else
		{
			val.push(ch-'0');
			in.push(string(1,ch));
			post.push(string(1,ch));
		}
	}
	
	cout<<val.top()<<endl;
	cout<<in.top()<<endl;
	cout<<post.top()<<endl;
}
int main()
{
	string s;
	getline(cin,s);
	prefixConversion(s);
}
