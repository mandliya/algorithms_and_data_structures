/*
 * Problem: Print all the permutations of a string.
 *
 * Details: Permutation is "arrangement number" or "order". So problem is given a string, how many strings can we produce by rearranging them.
 *
 * Example: Permutations of ABC are ABC, ACB, BCA, BAC, CAB, CBA
 *
 * Approach: Lets take a backtracking approach. We select one letter, then recursively permute the remaining letters.
 *           At each step of permutation process, the given set will have two parts, a part we have already processed and the part we are yet to process.
 *           So, at ith step we exchange the i’th value with the value being chosen at that stage. 
 *
 */
#include <iostream>
#include <cstring>

/*
 * Helper routine to swap pointers
 */
void swap( char *a, char *b )
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Function : Permute
 * Arg 1: c string
 * Arg 2: starting index of the string.
 * Arg 3: ending index of the string/
 */
void permute(char *str, int l, int r)
{
    if (l == r) 
    {
        std::cout << str << std::endl;
    }

    for (int i = l; i <= r; ++i) 
    {
        swap( (str + l), (str + i) );
        permute(str, l+1, r);
        swap( (str + l), (str + i) );
    }
}

int main()
{
    char str[] = "abc";
    std::cout << "Permutations of the string " << str << " are :\n";
    permute(str, 0, std::strlen(str)-1);
    return 0;
}

