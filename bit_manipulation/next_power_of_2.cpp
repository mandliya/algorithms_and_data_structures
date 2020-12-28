/*
 * Write a function that, for a given no n, finds a number p which is greater than or equal to n and is a power of 2.
 */
#include <iostream>

int next_power_of_2( int num ) {
  if(num & (1<<0)){
  	return num+1;
  }
  	return num;
}

int main()
{
  std::cout << "Enter a number:";
  int num;
  std::cin >> num;
  std::cout << "Next power of 2 which is greater than or equal to " << num
            << " is: " << next_power_of_2(num) << std::endl;
  return 0;
}
