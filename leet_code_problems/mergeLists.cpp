/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold 
 * additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 */


#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int  k = m + n - 1;
        while ( i >= 0 && j >= 0 ) {
            if ( nums1[i] > nums2[j] ) {
                nums1[k] = nums1[i];
                --i;
            } else {
                nums1[k] = nums2[j];
                --j;
            }
            --k;
        }
        while ( j >= 0 ) {
            nums1[k] = nums2[j];
            --j;
            --k;
        }
    }

void printVec(std::vector<int> & vec ) {
	for ( auto x : vec ) {
		std::cout << x << " " ;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec1 { 2, 4, 6, 8, 10, 0, 0, 0, 0, 0};
	std::vector<int> vec2 { 1, 2, 3, 4, 5 };
	merge(vec1, 5, vec2, 5 );
	printVec(vec1);
	return 0;
}
