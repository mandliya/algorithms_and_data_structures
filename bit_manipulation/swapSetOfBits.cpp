/**
 * Problem - Given a number 'num' and two positions (p1 and p2 from right side) in binary representation of num,
 *  write a function that swaps n bits at given two positions and returns the result.
 *  It is also given that the two sets of bits do not overlap.
 */

#include <iostream>

int swapBits(unsigned int num, unsigned int p1,
             unsigned int p2, unsigned int n )
{
  //Step1 lets form a number set1 by  moving  n bits at position p1 to the rightmost
  unsigned int set1 = (num >> p1 ) & ((1U << n) - 1);
  // Lets understand what we just did.
  // Part1 : (num >> p1), we just right shifted num so that bit at p1 position takes 0th postion.
  // Part2 : Remember we needed n bits from position p1(which has become position 0)
  //         So, (1U << n) moves 1 to nth bit, i.e. it the value formed by this movement is 2^n
  //         Now, If we substract 1 from the (2^n), it will give us all 1's for n positions.
  //         For example (1U << 3) = 1000
  //         and (1U << 3) - 1 = 0111
  // Part3 : Thus Part1 & Part2 will give as n bits which were at P1 (now moved to 0)

  //similarly for p2
  unsigned int set2 = (num >> p2) & ((1U << n) - 1);

  // xor two sets ( we are doing similar to xor swap algorithm )
  // https://en.wikipedia.org/wiki/XOR_swap_algorithm
  unsigned int xorSets = set1 ^ set2;

  // now moving back the xor'd sets to p1 and p2
  xorSets = (xorSets << p1) | (xorSets << p2);

  unsigned int finalVal = xorSets ^ num;
  return finalVal;
}

int main()
{
  std::cout << "Swaping bits in number 28, such that 2 bits starting from 0th bit and 2 bits "
               "starting from 3rd bit are swapped, 28 becomes " << swapBits(28, 0, 3, 2)
               << std::endl;

  std::cout << "Swaping bits in number 47, such that 3 bits starting from 1st bit(0 based counting) and 3 bits "
               "starting from 5th bit(0 based counting) are swapped, 47 becomes " << swapBits(47, 1, 5, 3)
               << std::endl;
}
