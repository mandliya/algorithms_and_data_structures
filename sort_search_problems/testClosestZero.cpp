#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

std::pair<int, int> pairSumClosestToZero( std::vector<int> & vec ) {
	std::pair<int, int> minPair( 0, 0 );
	if ( vec.size() < 2 ) {
		return minPair;
	}

	size_t minLeft = 0, minRight = vec.size()-1;
	size_t left = 0, right = vec.size() -1;
	int minSum = std::numeric_limits<int>::max();

	std::sort( vec.begin(), vec.end() );

	while( left < right ) {
		int sum = vec[left] + vec[right];
		if ( std::abs(minSum) > std::abs(sum) ) {
			minSum = sum;
			minLeft = left;
			minRight = right;
		}
		if ( sum > 0 ) {
			--right;
		} else {
			++left;
		}
	}
	minPair.first = vec[minLeft];
	minPair.second = vec[minRight];
	return minPair;
}

TEST_CASE("Closest pairs to zero test 1"){
	vector<int> lyst { 2, -100, -80, 2, 4, 300, 74};
	pair<int,int> mine = pairSumClosestToZero(lyst);
	REQUIRE( mine.first == 2 );
    REQUIRE( mine.second == 2 );
}

TEST_CASE("Closest pairs to zero test 2"){
	vector<int> lyst { -10123, -3414, 3, -34664, 10023, 6526, 47324, 100, 2351, 37345, 12576, 12356};
	pair<int,int> mine = pairSumClosestToZero(lyst);
	REQUIRE( mine.first == -10123 );
    REQUIRE( mine.second == 10023 );
}

TEST_CASE("Closest pairs to zero on huge array"){
	vector<int> lyst;
	for(int i = 20000; i < 20100; i++){
		lyst.push_back(i);
	}
	lyst.push_back(-5);
	lyst.push_back(7);
	pair<int,int> mine = pairSumClosestToZero(lyst);
	REQUIRE( mine.first == -5 );
    REQUIRE( mine.second == 7 );
}
