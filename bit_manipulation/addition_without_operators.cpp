/**
 * Addtion of two numbers without using any arithmatic operators.
 */
#include <iostream>

int sum( int x, int y ) {
  int carry = 0;
  while( y != 0 ) {

    //if x and y don't have same bits at same position, XOR of x and y
    //gives us sum of x and y at those positions.
    // bits wont change at positions containing same bits, however,
    // we have to incorporate carry bits. AND of x and y gives all carry bits.
    // carry will be added from position 1 (not 0), so we need to shift carry
    // by 1.
    carry = x & y;
    x = x ^ y;
    y = carry << 1;
  }
  return x;
}

//recursive version
int sum2( int x, int y ) {
  if ( y == 0 ) {
    return x;
  }
  return sum2( x ^ y, (x & y) << 1);
}

int main()
{
  int x , y;
  std::cout << "Addition of two numbers without using arithmatic operators:\n";
  std::cout << "Enter num 1 :" ;
  std::cin >> x;
  std::cout << "Enter num 2 :" ;
  std::cin >> y;
  std::cout << "Iterative version - Addition of " << x << " and " << y
            << " is " << sum(x, y) << std::endl;
  std::cout << "Recursive version - Addition of " << x << " and " << y
            << " is " << sum2(x, y) << std::endl;
  return 0;
}
