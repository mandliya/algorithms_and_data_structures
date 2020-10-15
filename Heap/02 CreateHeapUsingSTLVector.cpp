#include <iostream>
#include <vector>

using namespace std;
 
void Insert(vector<int>& vec, int key){
    // Insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);
 
    // Rearrange elements: O(log n)
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2]){
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    vec[i] = key;
}
 
void InsertInplace(int A[], int n){
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}
 
void CreateHeap(vector<int>& vec, int A[], int n){
    // O(n log n)
    for (int i=0; i<n; i++){
        Insert(vec, A[i]);
    }
}
 
void createHeap(int A[], int n){
    for (int i=0; i<n; i++){
        InsertInplace(A, i);
    }
}
 
template <class T>
void Print(T& vec, int n, char c){
    cout << c << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
 
int main() {
 
    cout << "Create Heap" << endl;
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    Print(b, sizeof(b)/sizeof(b[0]), 'b');
 
    vector<int> v;
    CreateHeap(v, b, sizeof(b)/sizeof(b[0]));
    Print(v, v.size(), 'v');
 
    cout << "Inplace Insert" << endl;
    createHeap(b, sizeof(b)/sizeof(b[0]));
    Print(b, sizeof(b)/sizeof(b[0]), 'b');
 
 
    return 0;
}