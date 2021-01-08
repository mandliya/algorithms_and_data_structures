#include<iostream>
using namespace std;

struct Array
{
	int* A;
	int size;
	int length;
};

void Display(struct Array* arr)
{
	int i;
	cout << "The elements of the array is " << endl;
	for (i = 0; i < arr->length; i++)
		cout << arr->A[i] << " ";
}
int Findmax(struct Array* arr) // findinf the max of the array 
{
	int a = INT_MIN;
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (arr->A[i] > a)
			a = arr->A[i];
	}
	return a;
}

void Countsort(struct Array* arr)
{
	int max, i;
	int* C;
	max = Findmax(arr); // finding the max element of the array 
	C = new int[max + 1]; // create an array of max size element in the array 
	for (i = 0; i < max + 1; i++)
		C[i] = 0; // initialize all the count array with zero 
	for (i = 0; i < arr->length; i++)
	{
		C[arr->A[i]]++; // count the number of element present in the array and increament count 
	}
	int j;
	i = 0, j = 0;
	while (i < max + 1)// with this loop  depending on the count of the elements will be filled in the array in sorted manner 
	{
		if (C[i] > 0) {
			arr->A[j++] = i;
			C[i]--;
		}
		else
			i++;

	}

}
int main()
{
	struct Array arr;
	cout << "Enter the size of the Array" << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	int no, i;
	cout << "Enter the length of the Array " << endl;
	cin >> no;
	arr.length = 0;
	cout << "Enter the elements of the Array" << endl;
	for (i = 0; i < no; i++)
		cin >> arr.A[i];
	arr.length = no;
	Countsort(&arr);
	//cout<<"The max of the array is  -> "<<Findmax(&arr);
	Display(&arr);
	return 0;
}
