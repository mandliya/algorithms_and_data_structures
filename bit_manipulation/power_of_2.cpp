/*
 * Given a number, determine if its power of 2 using bit manipulation in O(1)
 */

#include <iostream>

bool powerOfTwo( int n )
{
    return  n>0 && !((1<<0) & n);
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
