/*
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 * Note:
 * The vowels does not include the letter "y".
 */

#include <iostream>
#include <algorithm>

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' ||
            c == 'i' || c == 'o' ||
            c == 'u' || c == 'A' ||
            c == 'E' || c == 'I' ||
            c == 'O' || c == 'U');
}

std::string reverseVowels(std::string s)
{
    if (s.length() == 0)
    {
        return s;
    }
    
    unsigned int i = 0;
    unsigned int j = s.length() - 1;
    while (i < j)
    {
        while (i < j && !isVowel(s[i]))
        {
            i++;
        }
        
        while (i < j && !isVowel(s[j]))
        {
            j--;
        }
        
        if (i < j)
        {
            std::swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
    
    return s;
}
    
int main()
{
    std::string str;
    std::cout << "Please enter input string: ";
    std::cin >> str;
    std::cout << "Expected output string: " << reverseVowels(str) << std::endl;

    return 0;
}
