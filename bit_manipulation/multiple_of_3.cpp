/**
 * Check if a given number is multiple of 3
 * Basic way of doing is : if sum of digits of number is multiple of 3,
 * number is divisible by 3.
 *
 * However another efficient way of doing it is:
 * Count the number of set bits at even positions.
 * Count the number of set bits at odd positions.
 * if difference is multiple of 3, number will be multiple of 3.
 *
 * Proof:
 * We can prove it by taking the example of 11 in decimal numbers.
 * (It will apply to 3 in binary numbers as well.)
 * AB = 10A + B ( A and B are digits of number AB)
 * AB = 11A + (B - A)
 * Clearly if (B-A) is multiple of 11, number would be muliple of 11.
 * We can do it similarly for 3 digits
 * ABC = 100A + 10B + C
 *     = 99A + A + 11B - B + C
 *     = 11(9A + B) + (A - B + C)
 * Clearly if A-B+C is multiple of 11, ABC would be multiple as well.
 * similarly for 4 digits
 * ABCD = 1000A + 100B + 10C + D
 *      = (1001A – 999B + 11C) + (D + B – A -C )
 *      So, if (B + D – A – C) is a multiple of 11 then is ABCD.
 */

#include <iostream>

bool is_multiple_of_3( int n )
{
  // change to positive if negative
  if ( n < 0 ) {
    n = -n;
  }
  if ( n == 0 ) {
    return true;
  }
  if ( n == 1 ) {
    return false;
  }
  int even_count = 0;
  int odd_count = 0;
  while ( n ) {
    if ( n & 1 ) {
      ++odd_count;
    }
    n >>= 1;
    if ( n & 1 ) {
      ++even_count;
    }
    n >>= 1;
  }
  return is_multiple_of_3( even_count - odd_count );
}

int main()
{
  int num;
  std::cout << "Enter a number:";
  std::cin >> num;
  if (is_multiple_of_3(num))  {
    std::cout << num << " is multiple of 3" << std::endl;
  } else {
    std::cout << num << " is not a multiple of 3" << std::endl;
  }
  return 0;
}
