/*
 * Implement wildcard pattern maching with support for '?' & '*'
 * '?' Matches any single character
 * '*' Matches any sequence of character
 * Source : Leetcode problem 44.
 * 
 * Approach:
 * 
 * Consider examples:
 * is_match("aa", "a") false
 * is_match("aa", "aaa") false
 * is_match("aa", "?a") true
 * is_match("aa", "?*") true
 * is_match("aa", "*") true
 * is_match("aa", "*a") true
 * is_match("aa", "a*") true
 * is_match("cabcab", "*ab") true
 * 
 * Approach:
 * Clearly, the '*' with multiple pattern matches makes this problem
 * a little complicated, for example last case in the example.
 * The second pattern of ab will give us the right answer.
 * Therefore, we will have to try and match the same * with multiple
 * patterns, and backtrack when we fail to match.
 * For example:
 * When we iterate source string and target pattern 
 * "cabcab" and "*ab" with i and j respectively, we will realize at
 * i = 3 and j = 3 that we failed, at that time, we will have backtrack
 * j back to position next to '*' i.e. j = 1, so that we can continue
 * looking for further occurances of ab.
 * Therefore, we will have to remember positions of '*' and reset
 * iterator when we try to match the pattern.
 */

#include <iostream>
#include <string>


bool is_match(const std::string& str, const std::string& pattern)
{
    int sLen = str.length();
    int pLen = pattern.length();
    int i = 0;
    int j = 0;
    int last_star_position = -1;
    int last_match = -1;
    while (i < sLen) {
        if (j < pLen && (str[i] == pattern[j] ||
            pattern[j] == '?')) {
            ++i;
            ++j;
        }
        else if (j < pLen && pattern[j] == '*') {
            last_star_position = j;
            last_match = i;
            j++;
        }
        else if (last_star_position != -1) {
            j = last_star_position + 1;
            last_match++;
            i = last_match;
        }
        else return false;
    }

    while (j < pLen && pattern[j] == '*') {
        ++j;
    }
    return j == pLen;
}

int main()
{
    std::string str{"cabcab"};
    std::string pattern{"*ab"};
    if (is_match(str, pattern)) {
        std::cout << "'" << str << "'"
            << " and '" <<  pattern << "'" << " are a match\n";
    } else {
        std::cout << "'" << str << "'"
            << " and '" <<  pattern << "'" << " are not a match\n";
    }
    return 0;
}