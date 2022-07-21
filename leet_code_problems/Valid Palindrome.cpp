// https : // leetcode.com/problems/valid-palindrome/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str = "";

        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= '0' and s[i] <= '9'))
            {
                str += tolower(s[i]);
            }
        }

        int i = 0, j = str.size() - 1;

        while (i < j)
        {
            if (str[i] != str[j])
                return false;
            i++, j--;
        }

        return true;
    }
};