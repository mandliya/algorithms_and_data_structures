/**
 * Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted.
 * Examples:
 * 1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that the subarray lies between the indexes 3 and 8.
 *
 * 2) If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], your program should be able to find that the subarray lies between the indexes 2 and 5.
 */


#include <iostream>
#include <vector>
#include <utility>

std::pair<size_t, size_t> minLengthSubarray( std::vector<int> arr ) {

	//step 1: scan from left to right, find first element which is greater than next element
	size_t start = 0;
	for ( start = 0; start < arr.size() - 1; ++start ) {
		if ( arr[start] > arr[start+1] ) {
			break;
		}
	}
	if ( start == arr.size() - 1 ) {
		return std::make_pair(0,0);
	}

	//step 2: scan from right to left, and find first element(from right)
	//which is smaller than element before it( on left)

	size_t end;
	for ( end = arr.size() - 1; end > 0; --end ) {
		if ( arr[end] < arr[end-1] ) {
			break;
		}
	}

	// find minimum and maximum element in arr[start..end]
	int min = arr[start], max = arr[start];
	for ( size_t i = start + 1; i <= end; ++i ) {
		if ( arr[i] > max ) {
			max = arr[i];
		}
		if ( arr[i] < min ) {
			min = arr[i];
		}
	}

	// find the first element bigger than min in subarry arr[0..start-1], and
	// change the start index to that element index

	for ( size_t i = 0; i < start; ++i ) {
		if ( arr[i] > min ) {
			start = i;
			break;
		}
	}

	// similarly find first element from right which is smaller than max, and
	// change the end index to that element index
	for ( size_t i = arr.size() - 1; i >= end+1 ; --i ) {
		if ( arr[i] < max ) {
			end = i;
			break;
		}
	}
	return std::make_pair( start, end );

}


void printVec( std::vector<int> & vec, size_t begin, size_t end ) {
	for ( size_t i = begin; i <= end; ++i ) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec1{10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	std::pair<size_t, size_t> subArrayIndices = minLengthSubarray(vec1);
	std::cout << "Array:";
	printVec( vec1, 0, vec1.size() - 1 );
	size_t start = subArrayIndices.first;
	size_t end = subArrayIndices.second;
	if ( start == 0 && end == 0 ) {
		std::cout << "Above array is already sorted\n";
	} else {
		std::cout << "Min length subarray in above array which needs to be sorted to sort above array completely is : ";
		printVec(vec1, start, end);
	}

	std::vector<int> vec2 { 0, 1, 15, 25, 6, 7, 30, 40, 50 };
	subArrayIndices = minLengthSubarray(vec2);
	std::cout << "Array:";
	printVec( vec2, 0, vec2.size() - 1 );
	start = subArrayIndices.first;
	end = subArrayIndices.second;
	if ( start == 0 && end == 0 ) {
		std::cout << "Above array is already sorted\n";
	} else {
		std::cout << "Min length subarray in above array which needs to be sorted to sort above array completely is : ";
		printVec(vec2, start, end);
	}

	return 0;
}
