/*
 * Generate numbers between 1 to N, in binary using a data-structure.
 */

#include <iostream>
#include <string>
#include <queue>

void  print_n_binary(int n)
{
    std::queue<std::string> q;
    q.push("1");
    int i = 1;
    while (i++ <= n)
    {
        // append 0 and 1 to the existing binary string.
        //
        q.push(q.front() + "0");
        q.push(q.front() + "1");

        std::cout << q.front() << std::endl;
        q.pop();
    }
}

int main()
{
    int n;
    std::cout << "Enter number n:";
    std::cin >> n;
    print_n_binary(n);
    return 0;
}
