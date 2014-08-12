
#include<iostream>

int binarySearchUtil(int* arr, int start, int end, int q){
	if(start > end)
		return -1;
	int mid = (start + end)/2;
	if( q == arr[mid])
		return mid;
	else if ( q > arr[mid])
		return binarySearchUtil(arr, mid+1, end, q);
	else 
		return binarySearchUtil(arr, start, mid-1, q);
}

int binarySearch(int *arr,int n, int q)
{
	return binarySearchUtil(arr, 0, n-1, q);
}

int main(){
	int arr[] = {5,10,15,20,25,30};
	std::cout<<"Current array is:";
	for(int i =0; i < 6; ++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Searching 14 in above array:";
	int result = binarySearch(arr,6,14);
	if(result == -1)
		std::cout<<"Not found\n";
	else
		std::cout<<"found at index "<<result<<"\n";
	 

	std::cout<<"Searching 15 in above array:";
	result = binarySearch(arr,6,15);
	if(result == -1)
		std::cout<<"Not found\n";
	else
		std::cout<<"found at index "<<result + 1<<"\n";
	return 0;
}
