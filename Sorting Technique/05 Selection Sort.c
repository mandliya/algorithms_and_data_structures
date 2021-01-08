#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectionsort(int A[], int n)
{
	int i, j, k; // for indexes 
	for (i = 0; i < n - 1; i++) // for passes // in 1st pass we will get the smallest element 
	{
		for (j = k = i; j < n; j++) // for checing all elements // keep i,j,k on 1st pos and strating moving j everytime and compare with k 
		{
			// move j to next element and comp with k . if j is smaller then k then bring k at j.. 
			if (A[j] < A[k]) // if j is less then k then move k and we will 
				k = j; // now k is pointing on the smallest elements 
		}
		swap(&A[i], &A[k]); // now swap k with i then we will get the smallest elements at that position (i) // in this only one swap will happen
	}
}
int main()
{
	int no, i, A[20];
	no = sizeof(A) / sizeof(int);
	scanf_s("%d", &no);
	for (i = 0; i < no; i++)
	{
		scanf_s("%d", &A[i]);
	}
	selectionsort(A, no);
	for (i = 0; i < no; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
