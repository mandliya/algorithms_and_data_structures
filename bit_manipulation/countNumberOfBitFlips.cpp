/**
 *  Given two numbers A and B, count number of flips required to convert number A to B
 *  Approach : Take XOR of A and B, the result will contain set bits only at positions
 *  where A differed B. Therefore number of set bits in the result of A ^ B is the number
 *  of flips required to convert A to B
 */

#include <iostream>

int countSetBits( int x )
{
  int count = 0;
  while( x ) {
    ++count;
    x = x & (x - 1);
  }
  return count;
}

int countBitFlips( int a, int b )
{
  return countSetBits(a ^ b);
}

int main()
{
  int x, y;
  std::cout << "Enter number 1 :";
  std::cin >> x;
  std::cout << "Enter number 2 :";
  std::cin >> y;
  std::cout << "Bit flips required to convert " << x
            << " to " << y << " is " << countBitFlips(x, y) << std::endl;
  return 0;
}
