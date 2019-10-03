/*
 * You are given a digit string (e.g "1234", "567" etc), 
 * provide all possible letter combinations we could generate from this digit string,
 * based on the mapping we see on the telphone/mobile dialpad. 
 * If you have typed SMS in old style phones, you would know. For e.g. "1" is mapped to "abc", 
 * 2 is mapped to "def". 
 * Example: "34" will give output: {"dg","dh","di","eg","eh","ei","fg","fh","fi"}
 * Note that order does not matter in result set.
 * 
 * Approach:
 * 
 * We can use a simple backtracking approach. Since each digit letter could be mapped to multiple characters,
 * for example '1' is mapped to 'a', 'b' and 'c'. As we move along in the digit string, for an index i, we will
 * add all possible letters to the string and recursively move ahead to i+1, 
 * i.e. we will choose say 'a' as our choice for the iteration, we map '1' to 'a' and then move to next
 * digit letter (i+1) and recurse, then we will make 'b' as our choice for position i, and then 'c'
 * This way we do it for all the letters at all the positions. 
 * The idea is to generate all possible subsets of the string, keeping in mind the order.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<char, std::string> dict {
    {'1' , "" },
    {'2' , "abc"},
    {'3' , "def"},
    {'4' , "ghi"},
    {'5' , "jkl"},
    {'6' , "mno"},
    {'7' , "pqrs"},
    {'8' , "tuv"},
    {'9' , "wxyz"},
    {'0' , " "},
    {'*' , "*"},
    {'#' , "#"}
};

void helper(const std::string& digits, std::string rs,
    std::vector<std::string>& result, int index)
{
    if (index == digits.length()) {
        result.push_back(rs);
        return;
    }
    
    char c = digits[index];
    std::string ps = dict[c];
    for (int i = 0; i < ps.length(); ++i) {
        helper(digits, rs + ps[i], result, index + 1);
    }
}

std::vector<std::string> letter_combinations(const std::string& digits)
{
    std::vector<std::string> result;
        if (digits.size() == 0) {
            return result;
        }
        std::string rs("");
        helper(digits, rs, result,  0);
        return result;
}

void print_vec(const std::vector<std::string>& vec)
{
    for(auto v: vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}
int main()
{
    std::string digits{"34"};
    std::cout << "All possible combinations of digits " << digits << " are: \n";
    print_vec(letter_combinations(digits));
    return 0;
}