/*
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str 
 * contains lowercase letters separated by a single space.
 * 
 * Approach:
 * 
 * Split the string into words, and then map it to each character of the patterns as _we move.
 * If the character is being mapped to multiple words, or a word is being mapped to multiple
 * character, then the str is not following pattern.
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

bool match_pattern(const std::string& str, const std::string& pattern)
{
    // split string to words
    std::istringstream iss(str);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, 
                                std::istream_iterator<std::string>());
    if (words.size() != pattern.size()) {
        return false;
    }

    std::unordered_map<char, std::string> map;
    std::unordered_set<std::string> set;
    for (int i = 0; i < pattern.size(); ++i) {
        if (map.find(pattern[i]) != map.end()) {
            // pattern is already mapped to some other string.
            if (words[i] != map[pattern[i]]) {
                return false;
            }
        } else {
            // word is already mapped to some other string.
            if (set.count(words[i])) {
                return false;
            } else {
                map[pattern[i]] = words[i];
                set.insert(words[i]);
            }
        }
    }
    return true;
}

int main() {
    std::string pattern{"abba"};
    std::string str{"dog cat cat dog"};
    std::cout << "Pattern : " << pattern << std::endl;
    std::cout << "String :" << str << std::endl;
    bool r = match_pattern(str, pattern);
    std::string result = (r) ? "true" : "false";
    std::cout << "Result :" << result << std::endl;

    pattern = "aaaa";
    std::cout << "Pattern : " << pattern << std::endl;
    std::cout << "String :" << str << std::endl;
    r = match_pattern(str, pattern);
    result = (r) ? "true" : "false";
    std::cout << "Result :" << result << std::endl;


    return 0;
}