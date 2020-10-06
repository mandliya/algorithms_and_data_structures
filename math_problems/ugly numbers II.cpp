// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.


class Solution {
public:
    int nthUglyNumber(int n) {
        
        if(n==0){
            return 0;
        }
        
        // if(n==1){
        //     return 1;
        // }
        
        int dp[n];
        
        dp[0]=1;
        
        int i2=0,i3=0,i5=0;
        
        for(int i=1;i<n;i++){
            // cout<<dp[i-1];
            dp[i]=min(dp[i2]*2, min(dp[i3]*3,dp[i5]*5));
            
            if(dp[i]==dp[i2]*2){
                i2++;
            }
            
             if(dp[i]==dp[i3]*3){
                i3++;
            }
            
            if(dp[i]==dp[i5]*5){
                i5++;
            }
        }
        
        return dp[n-1]; 
    }
};