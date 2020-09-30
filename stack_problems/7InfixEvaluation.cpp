#include<iostream>
#include<stack>
using namespace std;

int precedence(char oprtr)
{
	if(oprtr=='+')
	{
		return 1;
	}
	else if(oprtr=='-')
	{
		return 1;
	}
	else if(oprtr=='*')
	{
		return 2;
	}
	else
	{
		return 2;
	}
}

int operation(int v1,int v2,char oprtr)
{
	if(oprtr=='+')
	{
		return v1+v2;
	}
	else if(oprtr=='-')
	{
		return v1-v2;
	}
	else if(oprtr=='*')
	{
		return v1*v2;
	}
	else
	{
		return v1/v2;
	}
}

int infixEval(string s)
{
	stack<char> op;
	stack<int> opand;
	for(int i=0;i<s.size();i++)
	{
		char ch=s[i];
		if(ch=='(')
		{
			op.push(ch);
		}
		else if(isdigit(ch))
		{
			opand.push(ch-'0');
		}
		else if(ch==')')
		{
			while(op.top()!='(')
			{
				char oprtr=op.top();
				op.pop();
				int val2=opand.top();
				opand.pop();
				int val1=opand.top();
				opand.pop();
				int ans=operation(val1,val2,oprtr);
				opand.push(ans);
			}
			op.pop();
		}
		else if(ch=='+'|| ch=='-' || ch=='*' || ch=='/')
		{
			while(op.size()>0 && op.top()!='(' && precedence(ch)<=precedence(op.top()))
			{
				char oprtr=op.top();
				op.pop();
				int val2=opand.top();
				opand.pop();
				int val1=opand.top();
				opand.pop();
				int ans=operation(val1,val2,oprtr);
				opand.push(ans);
			}
			op.push(ch);
		}
		else
		{
			continue;
		}
	}
	while(op.size()!=0)
	{
		char oprtr=op.top();
		op.pop();
		int val2=opand.top();
		opand.pop();
		int val1=opand.top();
		opand.pop();
		int ans=operation(val1,val2,oprtr);
		opand.push(ans);
	}
	return opand.top();
}

int main()
{
	string s;
	getline(cin,s);
	int ans=infixEval(s);
	cout<<ans<<endl;
}
