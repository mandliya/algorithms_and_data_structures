/**
* Given two array A and B
* Is there an permutation A', B' possible of A and B, such that, A'i+B'i ≥ K for all i,
* where A'i denotes the ith element in the array A' and B'i denotes ith element in the array B'.
*
* Input: The first line contains two integers, N and K.
* The second line contains N space separated integers, denoting array A.
* The third line describes array B in a same format.
*
* Output: YES or NO
*
* Solution Approach :
* Greedy Algorithm.
* sort one of the arrays in ascending order and the other in descending order and
* then for every i, check if the condition (A[i] + B[i] >= k ) holds true or not
* for each of the array indices i. It can be deduced that if the condition fails on the sorted arrays,
* then there exists no permutation of A and B such that the condition holds good.
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int N, K;
  cin >> N >> K;
  int * A = new int[N];
  int * B = new int[N];
  for ( int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for(int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  sort(A, A + N);
  sort(B, B + N, std::greater<int>()); //decreasing order sort
  int j;
  for( j = 0; j < N; ++j ) {
    if (A[j] + B[j] < K) {
      std::cout << "NO" << std::endl;
      break;
    }
  }
  if ( j == N ) {
    std::cout << "YES" << std::endl;
  }
  return 0;
}

