/**
 *  Problem : One line function to return the position of right most bit.
 *  Approach : take 2's compliment and it with number.
 *  And finally taking a log of 2  + 1 will give us the position
 */

#include <iostream>
#include <cmath>

int position_of_first_set_bit( int num )
{
  return log2(num & -num) + 1;
}

int main()
{
  int num;
  std::cout << "Enter a number :";
  std::cin >> num;

  std::cout << "Position of first set bit number in binary representation of "
            << num << " is " << position_of_first_set_bit( num )
            << std::endl;

  return 0;
}
