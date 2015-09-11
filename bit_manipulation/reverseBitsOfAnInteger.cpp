/**
 *  Problem : Reverse bits of an unsigned integer
 */

#include <iostream>
#include <sstream>
#include <cassert>
#include <algorithm>

/**
 * swapBits - utility function to swap bits at position i and j in unsigned int x
 * l represents bit at position i
 * r represents bit at position j
 * if l and r are same nothing needs to be done.
 * if l and r are different i.e. (l ^ r == 1),
 * we toggle bits at position i and j, and return new x.
 */
unsigned int swapBits(unsigned int x, unsigned int i, unsigned int j)
{
  unsigned int l = ((x >> i) & 1);
  unsigned int r = ((x >> j) & 1);
  if ( l ^ r )
  {
    x ^= ((1U << i) | (1U << j));
  }
  return x;
}

/*
 reverseBits1 : we swap first bit with last,
 second with one before last and so on.
 */

unsigned int reverseBits1(int n)
{
  unsigned bitCount = sizeof(n) * 8;
  for( unsigned int i = 0; i < bitCount/2; ++i) {
    n = swapBits(n, i, bitCount-i-1);
  }
  return n;
}


/**
 *  Now, approach 2, divide and conquer:
 *
 *    	  01101001
 *       /         \
 *     0110      1001
 *     /   \     /   \
 *    01   10   10   01
 *    /\   /\   /\   /\
 *   0 1  1 0  1 0  0 1
 *
 *  Just like merge sort, swap at each level and you are done.
 *  First swap all odd and even bits, and then consecutive pair of bits
 *  and so on.
 *  This below approach will work on assumption that unsigned int size is 4bytes
 *  or 32 bits.
 *  Lets say a is 10 = 00000000 00000000 00000000 00001010
 *  Step 1: swap all odd and even positions.
 * a = (a & 0x55555555) << 1 | (a & 0xAAAAAAAA) >> 1
 * 0x55555555 = 01010101 01010101 01010101 01010101
 *     a      = 00000000 00000000 00000000 00001010
 * --------------------------------------------------- and
 * a & (0x5..) = 00000000 00000000 00000000 00000000
 * a & (0x5..) << 1 = 00000000 00000000 00000000 00000000
 *
 * 0xAAAAAAAA  = 10101010 10101010 10101010 10101010
 * a           = 00000000 00000000 00000000 00001010
 * ------------------------------------------------- and
 * a & (0xA..) = 00000000 00000000 00000000 00001010
 * a & (0xA..) >> 1 = 00000000 00000000 00000000 00000101
 *
 * (a & (0x5..)) << 1 | (x & (0xA..)) >> 1
 * 						=  00000000 00000000 00000000 00000101
 *  a =   00000000 00000000 00000000 00000101
 *
 ***********************************************************
 *
 * Step2 : swap two consecutive bits with next consecutive two bits.
 *  a = ((a & 0x33333333) << 2) | ((a & 0xCCCCCCCC) >> 2)
 * 0x33333333  = 00110011 00110011 00110011 00110011
 * a           = 00000000 00000000 00000000 00000101
 * ------------------------------------------------- and
 * a & (0x33..)= 00000000 00000000 00000000 00000001
 *
 * a & (0x33.) << 2 = 00000000 00000000 00000000 00000100
 *
 * 0xCCCCCCCC  = 11001100 11001100 11001100 11001100
 * a           = 00000000 00000000 00000000 00000101
 * ------------------------------------------------- and
 * a & (0xcc..)= 00000000 00000000 00000000 00000100
 * a & (0xcc..) >> 2 =  00000000 00000000 00000000 00000001
 * (a & (0x33..) << 2) | (a & (0xcc) >> 2 )
 *           = 00000000 00000000 00000000 00000101
 * a = 00000000 00000000 00000000 00000101
 *
 * **********************************************************
 *
 * Step3 : Swap 4 consecutive bits with next 4
 * a = ((a & 0x0F0F0F0F) << 4) | ((a & 0xF0F0F0F0) >> 4);
 * 0x0F0F0F0F  = 00001111 00001111 00001111 00001111
 * a           = 00000000 00000000 00000000 00000101
 * ------------------------------------------------ and
 * a & (0x0F..)= 00000000 00000000 00000000 00000101
 * a & (0x0F..) << 4 = 00000000 00000000 00000000 01010000
 *
 * 0xF0F0F0F0  = 11110000 11110000 11110000 11110000
 * a           = 00000000 00000000 00000000 00000101
 * ---------------------------------------------------
 * a & (0xF0..)= 00000000 00000000 00000000 00000000
 * a & (0xF0..) >> 4 = 00000000 00000000 00000000 00000000
 * therefore a = ((a & 0x0F0F0F0F) << 4) | ((a & 0xF0F0F0F0) >> 4)
 * 					 a = 00000000 00000000 00000000 01010000
 *
 * ***********************************************************
 *
 * Step4 : Swap consecutive bytes with each other
 * a = ((a & 0x00FF00FF) << 8) | ((a & 0xFF00FF00) >> 8);
 * 0x00FF00FF = 00000000 11111111 00000000 11111111
 * 0xFF00FF00 = 11111111 00000000 11111111 00000000
 * Clearly same as above operations, our a will become
 * a = 00000000 00000000 01010000 00000000
 *
 * ************************************************************
 * step5 : Finally swap two consecutive bytes with next two i.e. swapping left
 * 16 bits with right
 *
 * a = ((a & 0x0000FFFF) << 16) | ((a & 0xFFFF0000) >> 16);
 * So we will end up with
 * a = 01010000 00000000 00000000 00000000
 * Clearly which is reverse of how we started
 */

unsigned int reverseBits2( unsigned int num )
{
  assert(sizeof(num) == 4); // this method will work only for 32 bits
  num = ((num & 0x55555555) << 1)  |  ((num & 0xAAAAAAAA) >> 1);
  num = ((num & 0x33333333) << 2)  |  ((num & 0xCCCCCCCC) >> 2);
  num = ((num & 0x0F0F0F0F) << 4)  |  ((num & 0xF0F0F0F0) >> 4);
  num = ((num & 0x00FF00FF) << 8)  |  ((num & 0xFF00FF00) >> 8);
  num = ((num & 0x0000FFFF) << 16) |  ((num & 0xFFFF0000) >> 16);
  return num;
}

std::string printBinary(unsigned int n)
{
  std::stringstream ss;
  std::string bin;
  int count = 0;
  while(n)
  {
    ss << (n % 2);
    n /= 2;
    ++count;
  }
  bin = ss.str();
  bin.append(32-count, '0');
  std::reverse(bin.begin(), bin.end());
  return bin;
}

int main()
{
  std::cout << "Enter an unsigned number:";
  unsigned int n;
  std::cin >> n;
  std::cout << "Binary representation of entered number               : "
            << printBinary(n) << std::endl;
  std::cout << "Reversing bits of entered number\n";
  n = reverseBits1(n);
  std::cout << "Binary representation of number when bits are reversed: "
            << printBinary(n) << std::endl;
  std::cout << "Reversing bits again\n";
  n = reverseBits2(n);
  std::cout << "Binary representation of number when bits are reversed: "
            << printBinary(n) << std::endl;
  return 0;
}
