/*
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:

First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.

Output:

 Print total number of subsequences

Input Constraints:

1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000

Sample Input 1 :

3
1 2 3

Sample output:

8

Sample Output Explanation:

Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }

Sample Input 2:

7
1 2 3 4 5 9 10

Sample Output:

37

 */

#include <bits/stdc++.h>
#define MOD 100001
using namespace std;

int numofAP(int *arr, int N){
    /*
    Return all possible AP subsequences formed from the given integer array. You do not need to take input or print anything.
    Just return the ans.
    */
    int mina=INT_MAX,maxa=INT_MIN;
    
    for(int i=0;i<N;i++){
        mina=min(mina,arr[i]);
        maxa=max(maxa,arr[i]);
    }
    
    //Iterate through all common difference
    int count=N+1;
    int dp[N]={0};
    int sum[MOD]={0};
    for(int d=mina-maxa;d<=maxa-mina;d++){
        
        memset(sum,0,MOD);
        
        sum[arr[0]]=1;
        for(int i=1;i<N;i++){
            dp[i]=1;
            
            if(arr[i]-d>=1 && arr[i]-d<=100000)
                dp[i]=(dp[i]+sum[arr[i]-d])%MOD;
            
            count=(count+dp[i]-1)%MOD;
            
            sum[arr[i]]=(sum[arr[i]]+dp[i])%MOD;
        }
    }
    return count;
    
    
}

int main(){

    int N;
    cin >> N;

    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;

    return 0;
}