// https : // leetcode.com/problems/detect-capital/

class Solution
{
public:
    bool detectCapitalUse(string word)
    {

        int n = word.size();
        int pos = -1;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (isupper(word[i]))
            {
                pos = i;
                cnt++;
            }
        }

        if (cnt == 0 || cnt == n || pos == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};