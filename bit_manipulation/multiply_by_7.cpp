/**
 * Problem : Muliply a number by 7 by using bit manipulation.
 * Approach : left shift n by 3 --> 8n
 * Therefore 7n = 8n - n;
 */
#include <iostream>

int multiply_by_7( int number )
{
  return ((number << 3) - number);
}

int main()
{
  std::cout << "Enter a number:";
  int num;
  std::cin >> num;
  std::cout << "7 x " << num << " = "
            << multiply_by_7(num) << std::endl;
  return 0;
}
