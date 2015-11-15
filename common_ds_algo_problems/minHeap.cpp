#include <iostream>
#include <vector>

template <typename T>
class Heap {
	T * arr;
	size_t capacity;
	size_t heap_size;

public:
	Heap( T * arr, size_t heap_size );
	T left( size_t i ) { return ( i - 1 )/2; }
	T right( size_t i ) { return (2 * i + 1); }
	T parent( size_t i ) { return ( 2 * i + 2 ); }
	void minHeapify( size_t i );
	T getMin() { return arr[0]; }
	int extractMin();
};

Heap::Heap(T * harr, size_t heapSize ) {
	heap_size = heapSize;
	arr = harr;
	size_t i = ( heap_size - 1 )/ 2;
	while ( i >= 0 ) {
		minHeapify(i);
		i--;
	}
}

template <typename T>
T Heap::extractMin() {
	if (heap_size == 0 ) {
		
	}
}
