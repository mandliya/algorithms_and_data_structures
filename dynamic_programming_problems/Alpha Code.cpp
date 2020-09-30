/*
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:

Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”

For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input

Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.

Output

For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"

Sample Input:

25114
1111111111
3333333333
0

Sample Output:

6
89
1

*/


#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

/*
Follow through this example
        25114
        /   \
    2(5114) 25 (114)  <---We cannot have more branches than this because English has 26 characters :P
      /         /\
    5(114)
      /  \
   1(14)  11(4)
     /\
  1(4) 14
     
This could be done other way round

We cannot go beyond (4), no other way to split it
Remember we only need to return the count not character itself
*/

long long counts(long long dp[],string n){
    if(n.size()<=0)
        return 1;
    if(dp[n.size()])
        return dp[n.size()];
    if(n[0]!='0')
        dp[n.size()]=counts(dp,n.substr(1))%mod;
    
    if(n[1]==0)
        return dp[n.size()]%mod;
    int d=(n[0]-48)*10+(n[1]-48);
    if(d<=26 && d>=10)
        dp[n.size()]=(dp[n.size()]+counts(dp,n.substr(2)))%mod;
    
    return dp[n.size()]%mod;
    
}
int main()
{
    while(true){
        string n;
        cin>>n;
        if(n[0]=='0')
            break;
        long long dp[n.size()+1]={0};
        
        long long ans=counts(dp,n);
        cout<<dp[n.size()]<<endl;
        
    }
    
    return 0;
}
