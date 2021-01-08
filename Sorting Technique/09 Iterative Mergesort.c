// sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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
void IMergeSort(int A[], int n)
{
	int p, l, h, mid, i;
	for (p = 2; p <= n; p = p * 2) // for passes // always list size will be doubled 
	{
		for (i = 0; i + p - 1 < n; i = i + p) // for the sub lsit // merging all list in a single pass // i sud incremented by i  + p 
		{
			l = i; // every pass modify the low , mid and high value 
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge(A, l, mid, h); // call merge fxn 
		}
		if (n - i > p / 2)
		{
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge(A, l, mid, n - 1);
		}
	}
	if (p / 2 < n) // if there are some more elements remaning then we sud merge it as it is 
	{
		Merge(A, 0, p / 2 - 1, n - 1); // call merge 
	}
}
int main()
{
	int A[] = { 11,5,14,2,6,3,1 }, n = 7, i;
	IMergeSort(A, n);
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
// time complexity = o(m+n)