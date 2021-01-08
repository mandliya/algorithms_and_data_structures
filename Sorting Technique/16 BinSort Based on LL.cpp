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


int Max(struct Array* arr) // findinf the max of the array 
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

void Insert(Node** ptrBins, int idx) {
    Node* temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr) { // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
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

void BinSort(struct Array *A) {
    int max = Max(A);

    // Create bins array
    Node** bins = new Node * [max + 1];

    // Initialize bins array with nullptr
    for (int i = 0; i < max + 1; i++) {
        bins[i] = nullptr;
    }

    // Update count array values based on A values
    for (int i = 0; i < A->length; i++) {
        Insert(bins, A->A[i]);
    }

    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (i < max + 1) {
        while (bins[i] != nullptr) {
            A->A[j++] = Delete(bins, i);
        }
        i++;
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
    BinSort(&arr);
	Display(&arr);
	return 0;
}
