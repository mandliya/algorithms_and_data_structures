#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <bubbleSort.h>
#include <generic.h>

using namespace std;

bool isSorted(int myData[], int size){
    for(int i = 0; i < size - 1; i++){
        if(myData[i] > myData[i+1])
            return false;
    }
    return true;
}

TEST_CASE("Compute bubble sort with small list"){
    int small_lyst[] = { 6, 5, 4, 100, 1, 3 };
    algo::bubbleSort(small_lyst, 0, 6);
    REQUIRE( isSorted(small_lyst, 6) == true );	
}

TEST_CASE("Compute bubble sort with big list"){
	const int LENGTH = 1000;
    int lyst[LENGTH];
	for(int i = 0; i < LENGTH; i++){
		lyst[i] = LENGTH - i;
	}
    algo::bubbleSort(lyst, 0, LENGTH);
    REQUIRE( isSorted(lyst, 1000) == true );	
}