/*

 */


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findSum(int arr[],int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Don't print output and return the output.
     * Taking input and printing output is handled automatically.
     */
    
    int all_neg=1;
    
    //Loop to check for all negatives;
    
    int neg_max=-200;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            all_neg=0;
            break;
        }
        neg_max=max(neg_max,arr[i]);
        
    }
    if(all_neg)
        return neg_max;
        
    int maxsum=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0)
            sum=0;
        maxsum=max(sum,maxsum);
    }
    return maxsum;
    

}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
	cout<<findSum(arr,n);

    return 0;
}

