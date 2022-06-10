// https : // leetcode.com/problems/valid-palindrome-ii/

class Solution
{
public:
    bool validPalindrome(string str)
    {

        int s = 0;
        int e = str.size() - 1;

        int cnt1 = 0;
        int cnt2 = 0;

        while (s < e)
        {
            if (str[s] == str[e])
            {
                s++;
                e--;
            }

            else
            {
                s++;
                cnt1++;
            }

            if (cnt1 > 1)
            {
                break;
            }
        }

        s = 0;
        e = str.size() - 1;

        while (s < e)
        {
            if (str[s] == str[e])
            {
                s++;
                e--;
            }

            else
            {
                e--;
                cnt2++;
            }

            if (cnt2 > 1)
            {
                break;
            }
        }

        if (cnt1 == 1 or cnt2 == 1)
        {
            return true;
        }

        if (cnt1 == 0 or cnt2 == 0)
        {
            return true;
        }

        return false;
    }
};