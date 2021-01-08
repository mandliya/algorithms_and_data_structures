// sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<stdio.h>

void Merge(int A[], int l, int mid, int h) // this is for two array inside one array 
{
	int i = l, j = mid + 1, k = l; 
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
void MergeSort(int A[], int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (l + h) / 2;
		MergeSort(A, l, mid);
		MergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);

	}
}
int main()
{
	int A[] = { 11,13,7,12,16,9,24,5,10,3 }, n = 10, i;

	MergeSort(A, 0, 9);

	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}
// time complexity = o(m+n)