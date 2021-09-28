#include<bits/stdc++.h>
using namespace std;
// you have to count number of set bits in number for example 101 sets bits are 2
// we will check if if number contain 1 at right most bit if yes than increment count 
// then after each step right shift number by 1 for example 
//n=1010,count=0 rigthbit=0
// n=0101 ,count=1,rightbit=1
//n=0010 count=1 rightbit=0
// n=0001 count=2 rightbit=0
int countbits(int n)
{
unsigned int count = 0;
    for (int i = 0; i < 32; i++)
    {
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
}
int main(){
    int n=5;
    cout<<countbits(n);
    return 0;
}