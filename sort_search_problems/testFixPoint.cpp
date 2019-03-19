#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>

using namespace std;

int binarySearchFixedPoint( const std::vector<int> & arr) {
	int high = arr.size() -1;
	int low = 0;
	while ( low <= high ) {
		int mid = (low + high)/2;
		if ( arr[mid] == mid ) {
			return mid;
		} else if ( mid > arr[mid] ) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

TEST_CASE("Compute fixed point with small list"){
    vector<int> vec {-1, 0, 2, 2, 1000, 10000};
    REQUIRE( binarySearchFixedPoint(vec) == 2 );
}

TEST_CASE("Compute not finding fixed point with small list"){
    vector<int> vec {100, 3333, 10000};
    REQUIRE( binarySearchFixedPoint(vec) == -1 );
}

TEST_CASE("Compute finding fixed point with big list"){
    vector<int> vec;
	for(int i = 0; i < 100; i++){
		vec.push_back(i + 1);
	}
	vec.push_back(100);
	for(int i = 101; i < 1000; i++){
		vec.push_back(i + 1);
	}
    REQUIRE( binarySearchFixedPoint(vec) == 100 );
}