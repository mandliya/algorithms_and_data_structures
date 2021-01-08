#include <iostream>

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

void ShellSort(struct Array* A, int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap >= 1; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = A->A[i];
			j = i - gap;
			while (j >= 0 && A->A[j] > temp)
			{
				A->A[j + gap] = A->A[j];
				j = j - gap;
			}
			A->A[j + gap] = temp;

		}
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
    ShellSort(&arr,no);
	Display(&arr);
	return 0;
}
