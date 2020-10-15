#include <stdio.h>
void Insert(int A[], int n) // it is taking a heap array as well as index of element thst you want to insert 
{
	int i = n, temp; // i sud point on index of element when it is inserted i.e i will start from n // take a temp variable 
	temp = A[i]; // temp variable sud have value which we want to strore in heap  
	// now compare and swap the element or arrage it 
	while (i > 1 && temp > A[i / 2])  // as long as i is greater then 1 and temp is grateter then parent // if temp is greater then parent copy the patend value 
	{
		A[i] = A[i / 2];  // a of i copy the value of a of i by 2 
		i = i / 2; // and i sud be moved to the parent 
	}
	A[i] = temp; // finally we move to last place //temp reach at the right place //   then copy the element a of i as temp 
}
int Delete(int A[], int n) //  fxn for del elements from the heap // take array as a // and the size of array we need the last index 
{
	int i, j, x, temp, val; 
	val = A[1]; // value which is deleated 
	x = A[n]; // take last elemet in x
	A[1] = A[n]; // copy last at 1st place 
	A[n] = val; // last value sud be assign with deleted value // that element will not consider in heap 
	i = 1; j = i * 2; // i starts from 1st elements and j points on left child of i (i*2)
	while (j <= n - 1) // adjusting the elements // as we del 1 elements so size of array reduced so it is n-1 
	{
		if (j<n - 1 && A[j + 1]>A[j]) //compare left child and right child which ever is greater let j point on that 
			j = j + 1; 
		if (A[i] < A[j]) // if parent is smaller then child 
		{
			temp = A[i]; // swap the elements 
			A[i] = A[j];
			A[j] = temp;
			i = j; // i sud come upon j i.e child 
			j = 2 * j; // j sud move to left child 
		}
		else // it it  is properly adjusted  then break 
			break; 
	}
	return val; // return deleted value 
}
int main() {
	//int H[] = { 0,10,20,30,25,5,40,35 }; // 1st pos will be 0 since it starts from 1 
	int H[20],no;
	int i;
	printf("enter the no of elements in array ");
	scanf_s("%d", &no);
	for (i = 0; i <= no; i++)
	{
		scanf_s("%d", &H[i]);
	}

	
	for (i = 2; i <= 7; i++) // using loop we are inserting elements  // 1st is inserted so we will start from  2 
		Insert(H, i); // every time set element to the index 

	// now let us run a loop for Heap sort 
	for (i = 7; i >1 ; i--)
	{
		Delete(H, i); //  calling del fxn 
	}
	for (i = 1; i <= 7; i++) // using for loop to traverse through elements  
		printf("%d ", H[i]); // print all the elements in a sorted manner 
	printf("\n");

	return 0;
}