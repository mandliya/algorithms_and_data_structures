#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <unordered_set>
#include <limits>

using namespace std;

int firstRepeating(std::vector<int> & arr) {
	std::unordered_set<int> arrSet;
	int min = -1;
	int arrSize = (int) arr.size();
	for ( int i = arrSize -1; i >= 0; i--) {
		if ( arrSet.find(arr[i]) != arrSet.end()) {
			min = i;
		} else {
			arrSet.insert(arr[i]);
		}
	}
	if ( min != -1 ) {
		return arr[min];
	} else {
		return std::numeric_limits<int>::min();
	}
}

TEST_CASE("Find first repeat 1"){
	vector<int> arr1{234, 453465, 234, 6345, 14123, 624, 44, 34, 26, 7345 };
	REQUIRE( firstRepeating(arr1) == 234 );
}

TEST_CASE("Find first repeat 2"){
	vector<int> arr1{234, 453465, 6345, 14123, 624, 44, 34, 26, 7345 };
	int theLimit = std::numeric_limits<int>::min();
	REQUIRE( firstRepeating(arr1) == theLimit );
}

TEST_CASE("Find first repeat 3"){
	vector<int> arr1;
	for(int i = 0; i < 1000; i++){
		if(i == 44){
			arr1.push_back(44);
		}
		arr1.push_back(i);
	}
	REQUIRE( firstRepeating(arr1) == 44 );
}