// https://leetcode.com/problems/find-the-difference/

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char XOR = '\0';
        for (auto ch : s)
            XOR ^= ch;
        for (auto ch : t)
            XOR ^= ch;
        return XOR;
    }
};