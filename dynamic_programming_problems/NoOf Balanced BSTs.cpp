/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :

Integer n 

Output Format :

Count of BSTs

Contraints :
1<= N <=1000
Sample Input 1:

8

Sample Output 1:

1430

Sample Input 2:

3

Sample Output 2:

5

*/

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;



int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    vector <long long> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    if(n==1 || n==2)
        return dp[n];
    for(int i=3;i<=n;i++){
        
        //Make each node root one at time
        for(int j=0;j<=i-1;j++){
            dp[i]=((dp[i]%mod)+((int)dp[j]*(int)dp[i-1-j])%mod)%mod;
        }
    }
    return dp[n]%mod;
    
}


int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
