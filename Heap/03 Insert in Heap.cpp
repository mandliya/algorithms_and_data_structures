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

int main() {
	int H[] = { 0,10,20,30,25,5,40,35 }; // 1st pos will be 0 since it starts from 1 
	int i;
	for (i = 2; i <= 7; i++) // using loop we are inserting elements  // 1st is inserted so we will start from  2 
		Insert(H, i); // every time set element to the index 
	 

	for (i = 1; i <= 7; i++) // using for loop to Display all the elements 
		printf("%d ", H[i]); // print all the elements as a heap 
	printf("\n");

	return 0;
}