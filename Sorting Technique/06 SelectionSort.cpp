#include <iostream>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void SelectionSort(int A[], int n){
    for (int i=0; i<n-1; i++){
        int j;
        int k;
        for (j=k=i; j<n; j++){
            if (A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}
 
int main() {
 
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, "\t\tA");
 
    SelectionSort(A, n);
    Print(A, n, " Sorted A");
 
    return 0;
}