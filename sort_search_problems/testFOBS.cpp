#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

 int firstOccurrenceBinarySearch( const std::vector<int> & vec, int key )
 {
   int high = vec.size() - 1;
   int low  = 0;
   int firstOccurrance = -1;
   while ( low <= high ) {
     int mid = (high + low) / 2;
     if ( key < vec[mid] ) {
       high = mid - 1;
     } else if ( key > vec[mid]) {
       low = mid + 1;
     } else {
       firstOccurrance = mid;
       high = mid - 1 ;
     }
   }
   return firstOccurrance;
 }

TEST_CASE("Find key 1"){
	std::vector<int> arr1{ 8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1 };
	sort(arr1.begin(), arr1.end());
	REQUIRE( firstOccurrenceBinarySearch(arr1, 20) == 5 );
}

TEST_CASE("Find key 2"){
	std::vector<int> arr1{1, 1, 1, 2, 3, 4, 4, 5, 234, 234, 234, 234};
	REQUIRE( firstOccurrenceBinarySearch(arr1, 234) == 8 );
}

TEST_CASE("Find key 3"){
	std::vector<int> arr1{1, 1, 1, 2, 3, 4, 4, 5, 234, 234, 234, 234};
	REQUIRE( firstOccurrenceBinarySearch(arr1, 124415) == -1 );
}
TEST_CASE("Find key 4"){
	std::vector<int> arr1{1, 5, 324};
	REQUIRE( firstOccurrenceBinarySearch(arr1, -123) == -1 );
}