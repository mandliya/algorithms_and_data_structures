/*
 * Given a string containing just the characters '(', ')', '{', '}', 
 * '[' and ']', determine if the input string is valid. The brackets must
 * close in the correct order, "()" and "()[]{}" 
 * are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include <stack>

bool is_valid_parenthesis(std::string str)
{
    std::stack<char> st;
    for (char c: str) {
        if (c == '(') {
            st.push(')');
        } else if (c == '{') {
            st.push('}');
        } else if (c == '[') {
            st.push(']');
        } else if (!st.empty()) {
            if (st.top() != c) {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main()
{
    std::string str1{"()[]{}"};
    if (is_valid_parenthesis(str1)) {
        std::cout << str1 << " has valid parenthesis." << std::endl;
    } else {
        std::cout << str1 << " does not have valid parenthesis." << std::endl;
    }
    std::string str2{"([)]"};
    if (is_valid_parenthesis(str2)) {
        std::cout << str2 << " has valid parenthesis." << std::endl;
    } else {
        std::cout << str2 << " does not have valid parenthesis." << std::endl;
    }
    return 0;
}