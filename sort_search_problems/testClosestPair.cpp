#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <utility>
#include <limits>
#include <cmath>

using namespace std;

std::pair<int,int> closestPair( std::vector<int> & vec1, std::vector<int> & vec2, int x ) {
	int left = 0;
	int right = vec2.size() - 1;
	int minDiff = std::numeric_limits<int>::max();
	int leftRes, rightRes;
	while (left < vec1.size() && right >= 0 ) {
		int diff = std::abs(vec1[left] + vec2[right] - x);
		if ( diff < minDiff ) {
			minDiff = diff;
			leftRes = left;
			rightRes = right;
		}
		if ( vec1[left] + vec2[right] > x ) {
			--right;
		} else {
			++left;
		}
	}
	return std::make_pair(vec1[leftRes], vec2[rightRes]);
}

TEST_CASE("Closest pairs in small list"){
	vector<int> l_first {0, 50, 100};
	vector<int> l_second {15, 30, 45}; 
	pair<int,int> myPair = closestPair(l_first, l_second, 75);
	pair<int,int> pear = closestPair(l_first, l_second, 132);
	REQUIRE( myPair.first == 50 );
    REQUIRE( myPair.second == 30 );	
    REQUIRE( pear.first == 100 );
    REQUIRE( pear.second == 30 );		
}

TEST_CASE("Closest pairs in bigger lists"){
	vector<int> l_first {0, 50, 100, 150, 200, 250, 300, 321, 350};
	vector<int> l_second {122, 123, 3423, 3451, 4444, 5555, 7777, 99999, 100000}; 
	pair<int,int> myPair = closestPair(l_first, l_second, 3602);
	pair<int,int> pear = closestPair(l_first, l_second, 3523);
	REQUIRE( myPair.first == 150 );
    REQUIRE( myPair.second == 3451 );	
	REQUIRE( pear.first == 100 );	
	REQUIRE( pear.second == 3423 );	
}

TEST_CASE("Closest pairs in lists of different size"){
	vector<int> l_first {0, 50, 100};
	vector<int> l_second {122, 123, 3423, 3451, 4444, 5555, 7777, 99999, 100000}; 
	pair<int,int> myPair = closestPair(l_first, l_second, 5657);
	pair<int,int> pear = closestPair(l_first, l_second, 201);
	REQUIRE( myPair.first == 100 );
    REQUIRE( myPair.second == 5555 );	
	REQUIRE( pear.first == 100 );	
	REQUIRE( pear.second == 122 );	
}