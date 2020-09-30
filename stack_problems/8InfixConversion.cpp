#include<iostream>
#include<stack>
using namespace std;

int precedence(char ch)
{
	if(ch=='+')
	{
		return 1;
	}
	else if(ch=='-')
	{
		return 1;
	}
	else if(ch=='*')
	{
		return 2;
	}
	else
	{
		return 2;
	}
}
void infixConversion(string s)
{
	stack<char>oprtr;
	stack<string>pre;
	stack<string>post;
	for(int i=0;i<s.size();i++)
	{
		char ch=s[i];
		if(ch=='(')
		{
			oprtr.push(ch);
		}
		else if((ch>='1' && ch<='9') || (ch>='a' && ch<='z' ) || (ch>='A' && ch<='Z'))
		{
			pre.push(string(1,ch));
			post.push(string(1,ch));
		}
		else if(ch==')')
		{
			while(oprtr.top()!='(')
			{
				char op=oprtr.top();
				oprtr.pop();
				string val2=pre.top();
				pre.pop();
				string val1=pre.top();
				pre.pop();
				string val2Post=post.top();
				post.pop();
				string val1Post=post.top();
				post.pop();
				
				string prefix=op+val1+val2;
				string postfix=val1Post+val2Post+op;
				pre.push(prefix);
				post.push(postfix);				
			}
			oprtr.pop();
		}
		else
		{
			if(oprtr.size()>0 && oprtr.top()!='(' && precedence(ch)<=precedence(oprtr.top()))
			{
				char op=oprtr.top();
				oprtr.pop();
				string val2=pre.top();
				pre.pop();
				string val1=pre.top();
				pre.pop();
				string val2Post=post.top();
				post.pop();
				string val1Post=post.top();
				post.pop();
				
				string prefix=op+val1+val2;
				string postfix=val1Post+val2Post+op;
				pre.push(prefix);
				post.push(postfix);	
			}
			oprtr.push(ch);
		}
	}
	while(oprtr.size()!=0)
	{
		char op=oprtr.top();
		oprtr.pop();
		string val2=pre.top();
		pre.pop();
		string val1=pre.top();
		pre.pop();
		string val2Post=post.top();
		post.pop();
		string val1Post=post.top();
		post.pop();
		
		string prefix=op+val1+val2;
		string postfix=val1Post+val2Post+op;
		pre.push(prefix);
		post.push(postfix);	
	}
	cout<<pre.top()<<endl;
	cout<<post.top()<<endl;
}
int main()
{
	string s;
	getline(cin,s);
	infixConversion(s);
}
