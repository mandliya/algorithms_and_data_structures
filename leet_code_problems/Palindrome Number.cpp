// https : // leetcode.com/problems/palindrome-number/submissions/

class Solution
{
public:
    bool isPalindrome(int x)
    {

        string str = to_string(x);
        reverse(str.begin(), str.end());

        return to_string(x) == str;
    }
};