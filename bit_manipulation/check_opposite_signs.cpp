/*
 * Given two integers, using bit manipulations determine if they are of opposite signs.
 * Most Significant Bit (MSB) of number represents sign of the number. If it is 1, it represents
 * a negative value, if it is 0, it represents a positive value.
 * If MSB of two numbers are different, their XOR would be 1, otherwise it would be 0.
 * Thus, result of XOR of two numbers will have MSB 1 if they are of opposite signs,
 * 0 other wise, in other words, XOR of two numbers would be negative (MSB 1) if they are of
 * opposite signs.
 * Source : http://graphics.stanford.edu/~seander/bithacks.html
 */

#include <iostream>

 bool are_of_different_signs(int a, int b)
 {
     return ((a ^ b) < 0);
 }

 int main()
 {
     int a, b;
     std::cout << "Enter number 1: ";
     std::cin >> a;
     std::cout << "Enter number 2:";
     std::cin >> b;
     if (are_of_different_signs(a, b))
     {
         std::cout << a << " and " << b << " are of different signs" << std::endl;
     }
     else
     {
         std::cout << a << " and " << b << " are of same signs" << std::endl;
     }
     return 0;
 }