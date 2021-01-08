#include <stdio.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Insertionsort(int A[], int n)
{
	int i, j, x;
	for (i = 1; i < n; i++) // this is for repetation of passes 
	{
		j = i - 1; // set j as one before the last 
		x = A[i]; // the elemets that we have to insert
		// go on shifting the elements as long as a[j] is greater then x and everytime reduce j by 1 ; j-- 
		while (j > -1 && A[j] > x) // shifting  the elements 
		{
			// when place is found to insert then 
			A[j + 1] = A[j]; // everytime at the next location copy the elemets of j
			j--; // decrement j 
		}
		A[j + 1] = x; // at end copy the element at appropriate position 
	}

}
int main()
{
	int A[20],no,i;
	scanf_s("%d", &no);
	for (i = 0; i < no; i++)
	{
		scanf_s("%d", &A[i]);
	}
	Insertionsort(A, no);
	for (i = 0; i < no; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;

}