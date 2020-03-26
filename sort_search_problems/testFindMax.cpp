#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>

int findMaximum(std::vector<int> & arr, int low, int high) {
	// subset has only one element
	if ( high == low ) {
		return arr[low];
	}

	//subset has 2 elements
	if ( high - low == 1 ) {
		return arr[high] > arr[low] ? arr[high] : arr[low];
	}

	int mid = ( high + low )/2;
	if ( arr[mid-1] > arr[mid] ) {
		return findMaximum(arr, low, mid-1);
	} else {
		return findMaximum(arr, mid+1, high);
	}

}

TEST_CASE("Find max 1"){
	std::vector<int> arr1{ 8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1 };
	REQUIRE( findMaximum( arr1, 0, arr1.size()-1 ) == 500 );
}
TEST_CASE("Find max 2"){
	std::vector<int> arr2{1, 3, 50, 10, 9, 7, 6};
	REQUIRE( findMaximum( arr2, 0, arr2.size()-1 ) == 50 );
}
TEST_CASE("Find max 3"){
	std::vector<int> arr3{10, 20, 30, 40, 50};
	REQUIRE( findMaximum( arr3, 0, arr3.size()-1 ) == 50 );
}
TEST_CASE("Find max 4"){
	std::vector<int> arr4{120, 100, 80, 20, 0};
	REQUIRE( findMaximum( arr4, 0, arr4.size()-1 ) == 120 );
}