/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format

Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house

Output Format

 Line 1 : Maximum amount of money looted

Input Constraints

1 <= n <= 10^4
1 <= A[i] < 10^4

Sample Input :

6
5 5 10 100 10 5

Sample Output 1 :

110

 */

#include <bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    
    /*
    The logic would be to understand that for a ith house from left, the theief has two options
    1) Either steal from ith house and add its loot to his optimal looting of i-2 houses
    2) Don't steal from ith house, and hence keep his optimal looting for i-1 houses
    */
    // setting dp[0]=0 base case
    vector <int> dp(n+1,0);
    
    //Bottom up dp
    //If there is only 1 house
    dp[1]=arr[0];
    if (n==1)
        return arr[0];
    for(int i=2;i<=n;i++){
        
        dp[i]=max(arr[i-1]+dp[i-2],dp[i-1]);
    }
    return dp[n];
    

}

int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}
