// https : // leetcode.com/problems/remove-palindromic-subsequences/

class Solution
{
public:
    int removePalindromeSub(string s)
    {

        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (s[i] != s[j])
            {
                return 2;
            }

            i++;
            j--;
        }

        return 1;
    }
};