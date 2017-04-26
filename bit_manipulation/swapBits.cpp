#include <iostream>
#include <bitset>

int swapBits(int n, int p, int q)
{
    if (p == q)
    {
        return n;
    }
    // If bits are same, no point swapping.
    // Determine if bits are different
    //
    if (((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> q))
    {
        // toggle bits at p and q positions
        //
        n ^= (1 << p);
        n ^= (1 << q);
    }

    return n;
}

int main()
{
    int n, p, q;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Enter bit position 1:";
    std::cin >> p;
    std::cout << "Enter bit position 2:";
    std::cin >> q;
    int r = swapBits(n, p, q);
    std::cout << "Number before swap :" << n << " (" << std::bitset<8>(n).to_string() << ") "
        << std::endl <<  "Number after swapping bits at position "
        << p << " and " << q << " : "  << r << " (" << std::bitset<8>(r) << ")"
        << std::endl;
    return 0;
}