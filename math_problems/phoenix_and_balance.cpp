//Phoenix has n coins with weights 21,22,…,2n. He knows that n is even.

/*He wants to split the coins into two piles such that each pile has exactly n2 coins and the difference of weights between the two piles is minimized. Formally, let a denote the sum of weights in the first pile, and b denote the sum of weights in the second pile. Help Phoenix minimize |a-b|, the absolute value of a-b.
*/
/* input- 2 
          2
          4
   output- 2
           6
*/
/* In the first test case, Phoenix has two coins with weights 2 and 4. No matter how he divides the coins, the difference will be 4-2=2.
In the second test case, Phoenix has four coins of weight 2, 4, 8, and 16. It is optimal for Phoenix to place coins with weights 2 and 16 in one pile, and coins with weights 4 and 8 in another pile. The difference is (2+16)-(4+8)=6.
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int sum1=0;
		int sum2=0;
		for(int i=1;i<=n;i++){
			arr[i]=pow(2,i);
			if(i<(n/2)||i==n)
			sum1+=arr[i];
			else sum2+=arr[i];
		}
		cout<<abs(sum1-sum2)<<endl;
	}
	return 0;
}