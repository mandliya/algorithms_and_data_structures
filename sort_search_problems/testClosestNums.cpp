#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

TEST_CASE("Compute mindiff 1"){
    vector<int> small_lyst;
	small_lyst.push_back(2);
	small_lyst.push_back(6);
	small_lyst.push_back(234);
	small_lyst.push_back(734);
	small_lyst.push_back(25687);
	small_lyst.push_back(1);
    sort(small_lyst.begin(), small_lyst.end());
	int mindiff = INT_MAX;
	int mySizem = static_cast<int>(small_lyst.size() - 1);
    for( int i = 0; i < mySizem; i++){
        if (small_lyst[i+1]-small_lyst[i] < mindiff) {
            mindiff = small_lyst[i+1]-small_lyst[i];
        }
    }
	vector<int> newList;
	for( int i =0; i < mySizem; i++ ) {
        if (small_lyst[i+1]-small_lyst[i] == mindiff) {
			newList.push_back(small_lyst[i]);
			newList.push_back(small_lyst[i+1]);
        }
    }
	
	REQUIRE( newList.size() == 2 );
    REQUIRE( newList.at(0) == 1 );	
	REQUIRE( newList.at(1) == 2 );	
}
