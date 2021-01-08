#include<stdio.h>

void Merge(int A[], int l, int mid, int h) // this is for two array inside one array 
{
	int i = l, j = mid + 1, k = l;  // it sud be initizlized 
	int B[100];

	while (i <= mid && j <= h) 
	{
		if (A[i] < A[j])
			B[k++] = A[i++]; // copy element from a to b 
		else
			B[k++] = A[j++]; // copy element from another side of a to b 
	}
	for (; i <= mid; i++)
		B[k++] = A[i];
	for (; j <= h; j++)
		B[k++] = A[j];

	for (i = l; i <= h; i++) // this is for copy all the elements from B to A( back )
		A[i] = B[i];
}
// recursive fxn for mergesort 
void RMergeSort(int A[], int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (l + h) / 2; 
		RMergeSort(A, l, mid);
		RMergeSort(A, mid + 1, h);
		Merge(A, l, mid, h); // merging will done in postorder 

	}
}
int main()
{
	int A[] = { 11,13,7,12,16,9,24,5,10,3 }, n = 10, i;

	RMergeSort(A,0,n-1); //passing array // low // high 

	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}
// TC : O(nlogn) // n is time taken for merging and logn is for the logn time the merging will be performed 
// this will take extra space 