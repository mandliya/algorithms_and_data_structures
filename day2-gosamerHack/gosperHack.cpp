/*
	Gosamer hack is one of the most elegant way to find all possible subsets of size k from a given n number of elements.
	Please read README for complete explanation.	


*/

#include<iostream>
#include<vector>
using namespace std;


vector<vector<int> > subsets(int arr[], int n, int k){
	vector<vector<int> > res; 
	
	int set = (1 << k) - 1;
	int limit = (1 << n);
	while (set < limit) {
		
		//extract the current set elements by checking individual bit if it is set or not in current 'set'
		int num = set;
		vector<int> curr;
		int idx = 0;
		while(num){
			int bit = num & 1;
			if(bit){
				curr.push_back(arr[idx]);
			}
			++idx;
			num = num>>1;
		}
		res.push_back(curr);
    		// Gosper's hack:
		// let us move to next set
    		int c = set & -set;
    		int r = set + c;
    		set = (((r^set) >> 2) / c) | r;
	}
	return res;
}


int main(){
	int arr[] = {1,2,3,4,5};
	cout<<"Printing all combinations of size 3 of {1,2,3,4,5}:\n";
	vector<vector<int> > res = subsets(arr, 5,3);
	for(unsigned int i = 0; i < res.size(); ++i){
		vector<int> temp = res[i];
		for(unsigned int j = 0; j < temp.size(); ++j){
				cout<<temp[j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
