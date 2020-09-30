/*
Noor is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line and each of them has a score according to performance. Noor wants to give at least 1 chocolate to each student. She distributes chocolates to them such that If two students sit next to each other then the one with the higher score must get more chocolates. Noor wants to save money, so she wants to minimise the total number of chocolates.
Note that when two students have equal score they are allowed to have different number of chocolates.
Input Format:

First Line: Integer N, the number of students in Noor’s class. 
Second Line: Each of the student's score separated by spaces.

Output Format:

Output a single line containing the minimum number of chocolates Noor must give.

Input Constraints

 1 <= N <= 100000
 1 <= score <= 100000

Sample Input:

4
1 4 4 6

sample Output:

6

Sample Input:

3
8 7 5

sample Output:

6

*/

#include <iostream>
using namespace std;
int getMin(int *arr, int n){
   /* Don't write main().
      Don't read input, it is passed as function argument.
      Return output and don't print it.
      Taking input and printing output is handled automatically.
   */
    int dp[n];
    
    dp[0]=1;
    
    for(int i=1;i<n;i++){
        if(arr[i-1]<arr[i])
            dp[i]=dp[i-1]+1;
        
        else if(arr[i-1]==arr[i]){
            dp[i]=(dp[i-1]>1)?1:dp[i-1];
        }
        
        else{
            int j=i;
            dp[j]=1;
            while(arr[j-1]>arr[j]){
                dp[j-1]=(dp[j-1]<=dp[j])?dp[j-1]+1:dp[j-1];
                j--;
            }
        }
    }
    
    int sum=0;
    for(int i=0;i<n;i++){
        //cout<<dp[i]<<" ";
        sum+=dp[i];
    }
    cout<<endl;
    return sum;

}


int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << getMin(arr, n);
    delete []arr;
}