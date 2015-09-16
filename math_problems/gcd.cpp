/**
 *  Given two numbers, determine the greatest common divisior of the two numbers.
 */

#include <iostream>


int gcd1( int a, int b ) {
    while( b > 0 ) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int gcd2( int a, int b ) {
    if ( b == 0 ) return a;
    if ( a == 0 ) return b;
    return gcd2(b, a % b);
}

int gcd3( int a, int b ) {
    if ( a == 0 ) return b;
    if ( b == 0 ) return a;
    while ( a != b ) {
        if ( a > b ) {
            a = a-b;
        } else {
            b = b-a;
        }
    }
    return a;
}

int gcd4 ( int a, int b ) {
    if ( a == 0 ) return b;
    if ( b == 0 ) return a;
    if ( a == b ) return a;
    if ( a > b ) return gcd4(b, a-b);
    else  return gcd4(a, b-a);
}

int main()
{
    int a, b;
    std::cout << "Enter number 1 : ";
    std::cin >> a;
    std::cout << "Enter number 2 : ";
    std::cin >> b;
    std::cout << "GCD of " << a << " and "
              << b << " is " << gcd1(a,b) << std::endl;
    std::cout << "GCD of " << a << " and "
              << b << " is " << gcd2(a,b) << std::endl;
    std::cout << "GCD of " << a << " and "
              << b << " is " << gcd3(a,b) << std::endl;
    std::cout << "GCD of " << a << " and "
              << b << " is " << gcd4(a,b) << std::endl;
    return 0;
}
