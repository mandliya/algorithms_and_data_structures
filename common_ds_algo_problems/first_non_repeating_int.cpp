/*
 * Given an array of integers, determine the first non repeating integer in the array.
 */
#include<bits/stdc++.h>
#include<iostream>
#include<map>
using namespace std;

#define ll long long int

ll nonRepeating(vector<ll> arr, int size){
	map<ll,ll> m;
	map<ll,ll>::iterator it;
	for(ll i = 0; i < size; ++i){
		it = m.find(arr[i]);
		if( it != m.end()){
			m[arr[i]] = ++(it->second);
		}
		else{
			m[arr[i]] = 1;
		}
	}

	for(ll i = 0; i < size; ++i){
		it = m.find(arr[i]);
		if( it != m.end()){
			if(it->second == 1)
				return arr[i];
		}
	}
	return -1;

}

int main(){
	ll size;
	//int *arr;

	cout<<"Enter size of array:";
	cin>>size;
	vector<ll> arr(size);
	//arr = new int[size];
	cout<<"Enter elements of array:";
	for(ll i = 0; i < size; ++i)
    {
		cin>>arr[i];
	}
	cout<<"First Non repeating integer in array:"<< nonRepeating(arr,size)<<endl;
	return 0;
}
