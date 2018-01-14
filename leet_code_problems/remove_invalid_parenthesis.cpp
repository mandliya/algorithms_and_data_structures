/*
 * Remove the minimum number of invalid parentheses in order to make the input string valid.
 * Return all possible results.
 * Note: The input string may contain letters other than the parentheses ( and ).
 * 
 * Source: Leetcode, 301. Remove Invalid Parentheses
 * 
 * solution approach:
 * 
 * We can solve this problem in many ways, I am choosing DFS.
 * For a string to be valid, we have two requirements:
 * 1. The number of left and right parenthesis should be same.
 * 2. They should be in right order, for each open there has to be a close, so for example '()' is valid
 * but ')(' is not.
 * 
 * 1. We track the count of left and right parenthesis which are out of place.
 * 2. We recursively backtrack and go two ways.
 * If a character is left or right parenthesis,
 *  a.  we keep it
 *  b. or we drop it.
 * 3. In both the cases we adjust open left and right parameters accordingly.
 * Open is the count of parenthesis sets which are open but not close yet.
 * When we reach end of string, we check if it is valid by left, right and open count and
 * push the string to result set.
 * 4. If a character is not a parenthesis operator, we simply add it to the result string.
 * 5. At the end of backtracking, we simply replace the current result string with the one
 * we started this iteration with.
 * 
 * We are using a set to keep the results unique.
 * 
 */


#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

void dfs(const std::string& s, std::string temp, int index, int left, int right, int open,
            std::unordered_set<std::string>& result)
{
    if (index == s.length()) {
        if (left == 0 && right == 0 && open == 0) {
            result.insert(temp);
        }
        return;
    }
    
    if (left < 0 || right < 0 || open < 0) {
        return;
    }
    
    std::string current{temp};
    char c = s[index];
    if (c == '(') {
        // Drop
        dfs(s, temp, index + 1, left - 1, right, open, result);
        // Keep
        dfs(s, temp + c, index + 1, left, right, open + 1, result);
    } else if (c == ')') {
        // Drop
        dfs(s, temp, index + 1, left, right - 1, open, result);
        // Keep
        dfs(s, temp + c, index + 1, left, right, open - 1, result);
    } else {
        dfs(s, temp + c, index + 1, left, right, open, result);
    }
    
    temp = current;
}

std::vector<std::string> remove_invalid_parenthesis(const std::string& s) {
    std::vector<std::string> result;
    if (s.length() == 0) {
        result.push_back("");
        return result;
    }
    int left = 0;
    int right = 0;
    for (char c : s) {
        if (c == '(') left++;
        else if (c == ')') {
            if (left > 0) left--;
            else right++;
        }
    }
    std::unordered_set<std::string> result_set;
    std::string temp("");
    dfs(s, temp, 0, left, right, 0, result_set);
    return std::vector<std::string>(result_set.begin(), result_set.end());
}

template<typename T>
void print_vec(const std::vector<T>& vec) {
    for (auto v: vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::string str("(a)())()");
    std::cout << "Pattern: " << str << std::endl;
    std::cout << "Possible valid parenthesis combinations: ";
    print_vec(remove_invalid_parenthesis(str));
}
