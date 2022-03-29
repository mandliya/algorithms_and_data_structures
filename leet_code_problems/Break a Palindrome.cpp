// https : // leetcode.com/problems/break-a-palindrome/

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {

        string s = palindrome;
        if (palindrome.size() == 1)
        {
            return "";
        }

        int cnt = 0;

        for (auto ch : palindrome)
        {
            if (ch == 'a')
            {
                cnt++;
            }
        }

        int n = palindrome.size();

        if (cnt == n or cnt == n - 1)
        {
            s[n - 1] = 'b';
            return s;
        }

        int index = 0;

        for (int i = 0; i < n; i++)
        {
            if (palindrome[i] != 'a')
            {
                index = i;
                break;
            }
        }

        s[index] = 'a';

        return s;
    }
};