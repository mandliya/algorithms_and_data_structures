/**
 *  Given a vector of numbers, only one number occurs odd number of times, find the number
 *  Example - { 1, 1, 2, 2, 2, 2, 3, 3, 3} ==> Answer 3
 *  Approach - XOR of number with itself is 0, so even numbers will cancel out
 *  and we will be left with odd number.
 */

#include <iostream>
#include <vector>

int find_odd_one_out( const std::vector<int> & vec )
{
  int check = 0;
  for ( auto i : vec )
  {
    check ^= i;
  }
  return check;
}

void printVector( const std::vector<int> & vec )
{
  for ( auto & i : vec ) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> vec{2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
  std::cout << "Vector contains :" << std::endl;
  printVector( vec );
  std::cout << "Number which occurs odd time in the above vector :"
            << find_odd_one_out( vec ) << std::endl;
  return 0;
}
