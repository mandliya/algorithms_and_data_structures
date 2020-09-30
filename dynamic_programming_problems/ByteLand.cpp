/*
In Byteland, they have a very strange monetary system. Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit). The coins can be exchanged as many times as you want. That is, if initially you have a coin of value 500, you can first exchange into 250, 166 and 125. And after that you can further exchange your 250 coin into 125, 83, 62. So we can exchange our any coin as many times as we want.
You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.
You have one gold coin. What is the maximum amount of American dollars you can get for it?

Input format : A single integer N, denoting value of your gold coin

Output Format : A single integer, denoting the maximum amount of American dollars you can make
Sample Input 1 :

12

Sample Output 1 :

13

Sample Output 1 Explanation :
You can change 12 into 6, 4 and 3, and then change these into $6+$4+$3 = $13.
Sample Input 2 :

2

Sample Output 1 :

2

Sample Output 2 Explanation :
If you try changing the coin 2 into 3 smaller coins, you will get 1, 0 and 0, and later you can get no more than $1 out of them. It is better just to change the 2 coin directly into $2.

*/

// int64_t is a data type of 8 byte integer.

#include<stdint.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int64_t cal(vector <int64_t> &dp,int64_t n)
{
    if(n<10)
        return n;
    if(n<10000000)
    {
        if(dp[n])
            return dp[n];
        
        int64_t ans=cal(dp,n/2)+cal(dp,n/3)+cal(dp,n/4);
        
        dp[n]=max(n,ans);
        
        return dp[n];
    }
    
    
}

int64_t bytelandian(int64_t n) {
	// Write your code here
    
    vector <int64_t> dp(10000000,0);
    
    int64_t ans=cal(dp,n);
    
    return ans;

}

int main() {
		int64_t n;
		cin>>n;
		int64_t x=bytelandian(n);
		cout<<x<<endl;	
}