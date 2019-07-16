#include<iostream>
using namespace std;


void maxHeapify(int*, int, int);
void buildHeap(int*, int);
void heapsort(int*, int);

int main() {

	int arr[] = { 4,2,3,1,5,6,8,};

	heapsort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

void maxHeapify(int* arr, int n, int i) {
	if (i > n / 2 - 1) {
		//if index of element is greater than i/2 it is in the last level of the heap. no need to call maxHeapify for it.
		return;
	}
	if (arr[i] > arr[2 * i] && arr[i] > arr[(2 * i) + 1]) {
		//heap property already satisfied.
		return;
	}
	
	int maxInx = i, temp;

	while (i <= (n / 2 - 1)) {
		//finding the index of the largest child of i.
		if (arr[2 * i + 1] > arr[i] && (2 * i + 1) < n) {
			maxInx = 2 * i + 1;
		}
		if (arr[(2 * i) + 2] > arr[maxInx] && (2 * i + 2) < n) {
			maxInx = (2 * i) + 2;
		}
		//if no change occurs. then return.
		if (i == maxInx) { return; }

		//having obtained the index of the largest node swap it with i.
		//swapping arr[i] with arr[maxInx]
		temp = arr[maxInx];
		arr[maxInx] = arr[i];
		arr[i] = temp;
		i = maxInx;
	}

}

void buildHeap(int* arr, int n) {
	//start calling from the last parent in the heap(n/2) and go upto the root node.
	//start from the last parent instead of root because here the loop invacriant is that heap condition is 
	//satisfied for all nodes other than the one for which it is called. which would not be true when it is 
	//called for the root node of the array when the array is compeletely random.
	//refer to CORMEN for more details.
	for (int i = (n / 2 - 1); i >= 0; i--) {
		maxHeapify(arr, n, i);
	}
}

void heapsort(int* arr, int n) {
	buildHeap(arr, n);
	
	int temp;
	while (n > 0) {
	//after the heap is built take the element a[0], swap it with the last element, discard it and call maxheapify 
	//for the root element

		temp = arr[n - 1];
		arr[n - 1] = arr[0];
		arr[0] = temp;
		n--;
		maxHeapify(arr, n, 0);
	}
}
