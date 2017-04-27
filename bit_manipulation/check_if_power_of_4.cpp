/*
 * Check if a given number is power of 4 or not.
 * 
 * Approach: If a value is power of 4, it has to be power of 2 and
 * it will have set bits at even position (as the number is power of 2, it will have
 * only one set bit.) For example:
 * 4 (10)
 * 16 (10000)
 * 64 (1000000)
 * If a number is power of 2 then it would have only one set bit and that set
 * bit would be reset by the expression (n & (n-1)), thus if (n & (n-1)) == 0,
 * means n is power of 2.
 * Now, since we have one set bit and if it is at even position it would be
 * power of 4, to check if set bit is at even position, we should AND it with
 * expression 10101010101010101010101010101010 i.e. 0xAAAAAAAA. Notice we have
 * set bits at all odd positions (it is 0 indexed), thus if expression
 * (n & 0xAAAAAAAA) == 0, then we have that set bit at even position.
 */

 #include <iostream>

 bool isPowerOf4 (unsigned int n)
 {
     // The number should be power of 2, and should have set bit at even position
     //
     return (n && !(n & (n-1)) && !(n & 0xAAAAAAAA));
 }

 int main()
 {  
     unsigned int n;
     std::cout << "Enter a number:";
     std::cin >> n;
     if (isPowerOf4(n))
     {
         std::cout << n << " is power of 4.\n";
     }
     else
     {
         std::cout << n << " is not a power of 4.\n";
     }
 }