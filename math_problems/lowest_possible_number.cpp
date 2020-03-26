/*
 * Problem:
 * Given a string representation of a number, remove n characters
 * from the string such that number representation is lowest possible.
 * 
 * Example:
 * Input:
 * str = "4325043", n = 3
 * Output:
 * "2043"
 * 
 * Input:
 * str = "765028321", n = 5
 * Output:
 * "0221"
 * 
 * Input:
 * str = "12345", n = 6
 * Output:
 * 0
 * 
 * Input:
 * str = "12345", n = 0
 * Output:
 * 12345 
 */

#include <iostream>


void build_lowest_number(const std::string& num, std::string& result,
    int n)
{
    // If 0 characters are left to remove, append everything to result.
    if (n == 0) {
        result.append(num);
        return;
    }

    int len = num.length();

    // If there are more characters to remove than string length.
    // remove nothing and return, last example above.
    if (n >= len) {
        return;
    }

    // Now, we will find the minimum digit in n+1 characters.
    // Since we need to remove, smallest of n+1 digits should be
    // part of final string.
    int min_index = 0;
    for (int i = 1; i <= n; ++i) {
        if (num[i] < num[min_index]) {
            min_index = i;
        }
    }

    result.push_back(num[min_index]);
    std::string remaining_num = num.substr(min_index + 1,
        len - min_index);

    build_lowest_number(remaining_num, result, n-min_index);
}


int main()
{
    std::string num_string{"4325043"};
    std::string result;
    std::cout << "Number: " << num_string << std::endl;
    std::cout << "After removing 5 characters, smallest possible number:"
        << std::endl;
    build_lowest_number(num_string, result, 3);
    std::cout << result << std::endl;
    return 0;
}