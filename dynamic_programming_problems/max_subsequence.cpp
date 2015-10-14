/**
 * Maximum Value Contiguous Subsequence
 * Given an array of n numbers, give an algorithm for finding a contigous
 * subsequence A(i)...A(j) for which the sum of elements is maximum.
 * Example - { -2, 11, -4, 13, -5, 2} --> 20 i.e. { 11, -4, 13}
 * Example - { 1, -3, 4, -2, -1, 6} --> 7 { 4, -2, -1, 6}
 *
 * Approach :
 * For selecting an ith element, we have to make a decision
 * 			- Add it to the old sum M(i-1) + A[i]
 * 			- or start the new window with one element A[i]
 *
 * We will use above approach in solving it with O(n) space and with O(1) space (Kadane's approach).
 * Special Case:
 * If all the elements are positive then, we the Maximum Value Contigous Subsequence would be the entire set
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

//approach one using O(n) space.
int max_contigous_subsequence_sum( const std::vector<int> & v ) {

  //special case when all the elements are negative.
  bool allNegativeOrZero = true;
  int maxSum = std::numeric_limits<int>::min();
  for ( size_t i = 0; i < v.size(); ++i ) {
    if ( v[i] > 0 ) {
      allNegativeOrZero = false;
    }
    if (v[i] > maxSum) {
      maxSum = v[i];
    }
  }

  if (allNegativeOrZero) {
    return maxSum;
  }

  maxSum = 0;

  std::vector<int> M(v.size(), 0);
  if (v[0] > 0) {
    M[0] = v[0];
  }
  for (size_t i = 1; i < v.size(); ++i) {
    if ( M[i-1] + v[i] > 0 ) {
      M[i] = M[i-1] + v[i];
    } else {
      M[i] = 0;
    }
  }
  for ( size_t i = 0; i < v.size(); ++i ) {
    if (M[i] > maxSum) {
      maxSum = M[i];
    }
  }
  return maxSum;
}

//approach two
// Kadane's algorithm.
// Since we care about sum till i-1 for calculating i
// and we need to pick the maximum of all the sums eventully,
// We don't really need an array to store sums.
// We have to take care of special case when array contains only negative nums.
int max_contigous_subsequence_sum2( std::vector<int> & v ) {
  int max_so_far = std::numeric_limits<int>::min();
  int sum_so_far = 0;

  //special case all negative or zero
  bool allNegativeOrZero = true;
  for ( size_t i = 0; i < v.size(); ++i ) {
    if ( v[i] > 0 ) {
      allNegativeOrZero = false;
    }
    if ( v[i] > max_so_far ) {
      max_so_far = v[i];
    }
  }
  if (allNegativeOrZero) {
    return max_so_far;
  }

  //case 2 normal case;
  max_so_far = 0;
  for ( size_t i = 0; i < v.size(); ++i ) {
    sum_so_far += v[i];
    if ( sum_so_far < 0 ) {
      sum_so_far = 0;
    }
    if ( max_so_far < sum_so_far ) {
      max_so_far = sum_so_far;
    }
  }
  return max_so_far;
}


void printVec(const std::vector<int> & vec) {
  for(auto x : vec) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> vec{ -2, 11, -4, 13, -5, 2};
  std::cout << "Vector: ";
  printVec(vec);
  std::cout << "Sum of Maximum Contiguous Subarray for above vector is : "
            << max_contigous_subsequence_sum(vec) << std::endl;

  std::vector<int> vec1{ -2, -1, -4, -3, -5, -2};
  std::cout << " Special Vector: ";
  printVec(vec1);
  std::cout << "Sum of Maximum Contiguous Subarray for above vector is : "
            << max_contigous_subsequence_sum(vec1) << std::endl;

  std::vector<int> vec2{ -200, -100, -50, -70, -500, -51};
  std::cout << " Special Vector: ";
  printVec(vec2);
  std::cout << "Sum of Maximum Contiguous Subarray for above vector is : "
            << max_contigous_subsequence_sum(vec2) << std::endl;

  std::vector<int> vec3{ 1, -3, 4, -2, -1, 6 };
  std::cout << "Vector: ";
  printVec(vec3);
  std::cout << "Sum of Maximum Contiguous Subarray for above vector is : "
            << max_contigous_subsequence_sum(vec3) << std::endl;
  return 0;
}
