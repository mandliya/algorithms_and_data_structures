#include <iostream>

using std::cout;
using std::endl;
using std::flush;
using std::string;
 
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
 
// Code is similar to Insertion Sort with some modifications
void ShellSort(int A[], int n){
    for (int gap=n/2; gap>=1; gap/=2){
        for (int j=gap; j<n; j++){
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp){
                A[i+gap] = A[i];
                i = i-gap;
            }
            A[i+gap] = temp;
        }
    }
}
 
int main() {
 
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "\t\tA");
    ShellSort(A, n);
    Print(A, n, " Sorted A");
 
    return 0;
}