/**
 The Hamming distance between two integers is the number of positions at which
 the corresponding bits are different.
 Given two integers x and y, calculate the Hamming distance.

 Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different
*/

#include <iostream>

int hamming_distance(int x, int y)
{
    // XOR will set only those bits in z which are different in x and y
    int z = x ^ y;

    // Now just count set bits in z.
    int count = 0;
    while (z)
    {
        count += (z % 2);
        z >>= 2;
    }
    return count;
}


int main()
{
    int x = 4;
    int y = 1;
    std::cout << "Hamming distance between " << x << " and " << y << " is : "
        <<  hamming_distance(x, y) << std::endl;
}
