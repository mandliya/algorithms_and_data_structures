/*
 * Implement pow(a, b) function.
 * We can recursively call a sub-problem
 * if n is even, then pow(a,b) = pow(a, b/2) * pow(a, b/2);
 * if n is odd then, pow(a, b) = a * pow(a, b/2) * pow(a, b/2);
 */

#include <iostream>

int power(int a, int b)
{
    // base condition
    //
    if (b == 0)
    {
        return 1;
    }

    // sub-problem for this recursive call.
    //
    int p = power(a, b/2);

    // if b is odd
    if (b & 1)
    {
        return (a * p * p);
    }
    else
    {
        // if b is even
        return (p * p);
    }
}

int main()
{
    int a, b;
    std::cout << "Calculating pow(a,b):\n";
    std::cout << "Enter a:";
    std::cin >> a;
    std::cout << "Enter b:";
    std::cin >> b;
    std::cout << "pow(a,b) :" << power(a, b) << std::endl;
 }

