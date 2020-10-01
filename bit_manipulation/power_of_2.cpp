/*
 * Given a number, determine if its power of 2 using bit manipulation in O(1)
 */

#include <iostream>

bool powerOfTwo( int n )
{
    if (n == 0) 
        return 0; 
    while (n != 1) 
    { 
        if (n%2 != 0) 
            return 0; 
        n = n/2; 
    } 
    return 1;
}

int main()
{
    int n;
    std::cout << "Enter a number :";
    std::cin >> n;
    if ( powerOfTwo(n) ) {
        std::cout << n << " is power of 2\n";
    } else {
        std::cout << n << " is not power of 2\n";
    }
    return 0;
}
