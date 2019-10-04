/*

            1	
		2	3	2	
	3	4	5	4	3	
4	5	6	7	6	5	4	

*/

#include <iostream>
using namespace std;

int main() {
	int n,i,j,k;
	cin>>n;
	
	for(i = 1; i<=n; i++){
	    for(j = 1; j<= (n-i); j++){
	        cout<<"\t";
	    }
	    
	    for(k = i; k<=(2*i - 1); k++){
	        cout<<k<<"\t";
	    }k -= 2;
	    
	    for( ; k>=i; k--){
	        cout<<k<<"\t";
	    }
	    
	    cout<<endl;
	}
	return 0;
}
