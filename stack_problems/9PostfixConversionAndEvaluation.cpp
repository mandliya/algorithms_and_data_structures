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
void postfixConversion(string s)
{
	stack<int> val;
	stack<string> in;
	stack<string> pre;
	
	for(int i=0;i<s.size();i++)
	{
		char ch=s[i];
		if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		{
			int val2=val.top();
			val.pop();
			int val1=val.top();
			val.pop();
			int ans=operation(val1,val2,ch);
			val.push(ans);
			
			string in2=in.top();
			in.pop();
			string in1=in.top();
			in.pop();
			string ansIn='('+in1+ch+in2+')';
			in.push(ansIn);
			
			string pre2=pre.top();
			pre.pop();
			string pre1=pre.top();
			pre.pop();
			string ansPre=ch+pre1+pre2;
			pre.push(ansPre);
		}
		else
		{
			val.push(ch-'0');
			in.push(string(1,ch));
			pre.push(string(1,ch));
		}
	}
	cout<<val.top()<<endl;
	cout<<in.top()<<endl;
	cout<<pre.top()<<endl;
 } 
int main()
{
	string s;
	getline(cin,s);
	postfixConversion(s);
}
