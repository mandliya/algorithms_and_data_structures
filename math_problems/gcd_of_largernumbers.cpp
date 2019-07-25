/*APPROACH: In the given problem, we can see that first number ‘a’ can be handled by long long int data type but second number ‘b’ can not be handled by any int data type.
Here we read second number as a string and we will try to make it less than and equal to ‘a’ by taking it’s modulo with ‘a’.
*/

#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(a==0)
        return b;
    else
    {
        return gcd(b%a,a);
    }
}
int main()
{
    long long int a;
    string s;
    cin >> a >> s;
    long long int b=0;

    for(int i=0;i<s.size();i++)
    {
        int num = s[i]-'0';
        b = ( ( b*10 ) % a + num ) % a ;// important step....(a+b)%m = a%m+b%m
    }
    //cout<<a<<" "<<b<<endl;
    cout << gcd(a,b);
}
