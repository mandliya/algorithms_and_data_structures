/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :

Integer h

Output Format :

Count % 10^9 + 7

Input Constraints :
1 <= h <= 10^7
Sample Input 1:

3

Sample Output 1:

15

Sample Input 2:

4

Sample Output 2:

315

 */

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int binaryTreesOfHeightH(int h) {
    // Write your code here
    
    vector <long long> dp(h+1);
    
    dp[1]=1;
    dp[2]=3;
    
    if(h==1 || h==2)
        return dp[h];
    
    for(int i=3;i<=h;i++){
        dp[i]=((dp[i-1]%mod)*(dp[i-1]%mod))%mod+(2*(dp[i-2]%mod)*(dp[i-1]%mod))%mod;
    }
    return dp[h];

}


int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}
