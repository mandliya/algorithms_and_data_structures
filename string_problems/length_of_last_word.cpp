/*
 * Given a string consisting of lower/upper case alphabets and empty space character ' '.
 * Return the length of last word in the string.
 * 
 * A word is character sequence containing non-space characters only.
 * 
 * Return 0, if no last word exist.
 * 
 * Approach:
 * 
 * Start from end of the string, and trim the whitespace.
 * When we find the first non-space character, find the next space or till we reach beginning of string.
 * 
 */

#include <iostream>

int get_length_of_last_word(const std::string& str)
{
    if (str.length() == 0) {
        return 0;
    }
    
    int n = str.length();
    int i = n - 1;
    int j = 0;

    // Trim the whitespace in the end
    while(i >= 0 && str[i] == ' ') i--;

    // Check if we already reached beginning of the string.
    if (i < 0) {
        return 0;
    }

    // Now start from the first non-space character
    for (j = i; j >= 0; --j) {
        if (str[j] == ' ') break;
    }

    return i - j;
}

int main()
{
    std::string str1 = "Hello";
    std::string str2 = "Hello          ";
    std::string str3 = "Hello       World!";
    std::cout << "String without any space of length " << str1.length() << ": " << str1 << std::endl;
    std::cout << "Length of last word :" << get_length_of_last_word(str1) << std::endl;
    std::cout << "String with lot of space in the end, with length of string " << str2.length() << ": "  << str2 << std::endl;
    std::cout << "Length of last word :" << get_length_of_last_word(str2) << std::endl;
    std::cout << "String with lot of space in the middle, with length of string " << str3.length() << ": "  << str3 << std::endl;
    std::cout << "Length of last word :" << get_length_of_last_word(str3) << std::endl;
    return 0;
}