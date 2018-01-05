/*
 * Given a string, sort it in decreasing order based on the frequency of characters.
 * Example:
 * Input: cccbbbbaa
 * Output: bbbcccaa
 * 
 * Input: AaaBBaa
 * Output: aaaaBBA
 * 
 * Input: cccaaa
 * Output:cccaaa or aaaccc
 * 
 * Notice that order of chars in alphabatical order does not matter for same frequency elements.
 * However, also all the same characters should be together. cacaca will not be a valid answer.
 */

#include <iostream>
#include <unordered_map>
#include <map>

std::string frequencySort(std::string s) {
        
        // Create a hash map of our characters with frequency as their values.
        std::unordered_map<char,int> frequencyMap;
        for (char c : s) {
            frequencyMap[c]++;
        }
        
        // Now we will maintain an another ordered map whose key would be
        // the frequency and values would be accumulated chars of same frequency.
        //
        std::map<int, std::string> stringMap;
        for (auto frqPair : frequencyMap) {
            char c = frqPair.first;
            int n = frqPair.second;
            stringMap[n] += std::string(n, c);
        }
        
        // Now pick the accumulated string in reverse order (highest first)
        std::string result;
        for (auto it = stringMap.rbegin(); it != stringMap.rend(); ++it) {
            result += it->second;
        }
        return result;
    }

int main()
{
    std::string input1{"cccbbbbaa"};
    std::cout << "Input: " << input1 << std::endl;
    std::cout << "Output:" << frequencySort(input1) << std::endl;
    std::string input2{"cccaaa"};
    std::cout << "Input:" << input2 << std::endl;
    std::cout << "Output:" << frequencySort(input2) << std::endl;
    return 0;
}