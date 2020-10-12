/*Given a number say(N) , The task is to reduce the number(N) by assuming new number(M) as the no. of bits in previous number(N).
-------------------------------------------------------------------
EXAMPLE 1:-

INPUT:-

N =10;

new number  =  number of bits in 10 = 1010 = 4(M)

now M= 4

new number = number of bits  in 4 = 100 = 3(M)

now M = 3

new number = number of bits in 3 =11 =2(M)

now M = 2

new number = number of bits in 2 = 10 =2(M)

now as new number = previous new number.

OUTPUT = 2.*/
#include <iostream>
using namespace std;
int BIT_COUNT(int i){
    int count=0,n=i;
    //To count number of bits
    while(i!=0){
        count++;//Will count number of bits
        i=i/2;
    }
    if(n==count){return n;}//base condition 
    //To terminate recursion when number of bits become equal to previous number.
    else{return BIT_COUNT(count);}
}
int main() {
    int i=10;
    cout<<BIT_COUNT(i)<<endl;//return final number 
	return 0;
}
