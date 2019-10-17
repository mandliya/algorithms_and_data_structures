#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>&,int,int);

int partition(vector<int>&, int,int);

int main()
{
    vector<int> A = {6,10,13,5,8,3,2,25,4,11};
    int start = 0;
    int end = 10;

    cout << "Before:" << endl;
    for(auto value : A)
        cout << value <<" ";
    cout << endl;    

    quickSort(A, start, end);

    cout << "After: " << endl;
    for(auto value : A)
        cout << value <<" ";
    cout << endl;   
}


void quickSort(vector<int>& A, int start,int end)
{
    int pivot;
    if(start < end)
    {
        pivot=partition(A, start, end);
        quickSort(A, start, pivot);  
        quickSort(A, pivot+1, end);
    }
}


int partition(vector<int>& A, int start,int end)
{
    int x = A[start];
    int i = start;
    int j;

    for(j = start+1; j < end; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
			swap(A[i],A[j]);
        }

    }

    swap(A[i],A[start]);
    return i;
}
