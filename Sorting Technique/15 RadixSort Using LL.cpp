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


int Max(struct Array* arr) // finding the max of the array 
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

// Linked List node
class Node {
public:
    int value;
    Node* next;
};

int countDigits(int x) {
    int count = 0;
    while (x != 0) {
        x = x / 10;
        count++;
    }
    return count;
}

void initializeBins(Node** p, int n) {
    for (int i = 0; i < n; i++) {
        p[i] = nullptr;
    }
}

void Insert(Node** ptrBins, int value, int idx) {
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr) {
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    }
    else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx) {
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

int getBinIndex(int x, int idx) {
    return (int)(x / pow(10, idx)) % 10;
}

void RadixSort(struct Array *A) {
    int max = Max(A);
    int nPass = countDigits(max);

    // Create bins array
    Node** bins = new Node * [10];

    // Initialize bins array with nullptr
    initializeBins(bins, 10);

    // Update bins and A for nPass times
    for (int pass = 0; pass < nPass; pass++) {

        // Update bins based on A values
        for (int i = 0; i < A->length; i++) {
            int binIdx = getBinIndex(A->A[i], pass);
            Insert(bins, A->A[i], binIdx);
        }

        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10) {
            while (bins[i] != nullptr) {
                A->A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }

    // Delete heap memory
    delete[] bins;
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
    RadixSort(&arr);
	Display(&arr);
	return 0;
}
