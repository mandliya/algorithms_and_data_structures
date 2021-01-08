#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) // function for swapping
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Bubble(int A[], int n) // size of array // no of elements 
{
	int i, j, flag = 0; // flag is for adptive (Criteria)
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]); // if is greater then swap the elements 
				flag = 1; 
			}
		}
		if (flag == 0)
			break;

	}
}
int main()
{
	int A[20], i;
	int n = sizeof(A) / sizeof(int);
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", & A[i]);
	}
	
	Bubble(A, n); //  callig the funtion 

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}

// Bubble sort is Adptive: if the list is sorted it will use flag  // Bubble sort is stable  : in case of duplicate 
// time complexity is : min = o(n) - in the case of Adaptivity 
//					  : max = o(n2)