/*
1
2	2	
3	0	3	
4	0	0	4	
5	0	0	0	5
*/

#include <iostream>
using namespace std;

int main() {
	int n,i,j;
	cin>>n;
	
	cout<<"1"<<endl;
	
	for(i = 1; i <= n-1; i++){
	    cout<<i+1<<"\t";
	    for(j = 1; j<i; j++){
	        cout<<"0"<<"\t"; 
	    }
	    cout<<i+1<<"\t"<<endl;
	}
	return 0;
}
