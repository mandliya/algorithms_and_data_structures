#include <iostream>

using namespace std;
 
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
int Delete(int A[], int n){
    int x = A[0];  // Max element
    A[0] = A[n-1];
 
    int i = 0;
    int j = 2 * i + 1;
 
    while (j < n-1){
        // Compare left and right children
        if (A[j] < A[j+1]){
            j = j+1;
        }
 
        // Compare parent and largest child
        if (A[i] < A[j]){
            swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    return x;
}
 
void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}
 
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
 
int main() {
 
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    Print(A, sizeof(A)/sizeof(A[0]), "A");
 
    Heapify(A, sizeof(A)/sizeof(A[0]));
    Print(A, sizeof(A)/sizeof(A[0]), "Heapified A");
    cout << endl;
 
    int B[] = {5, 10, 30, 20};
    Print(B, sizeof(B)/sizeof(B[0]), "B");
 
    Heapify(B, sizeof(B)/sizeof(B[0]));
    Print(B, sizeof(B)/sizeof(B[0]), "Heapified B");
 
    return 0;
}