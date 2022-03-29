// https : // leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution
{
public:
    int balancedStringSplit(string s)
    {

        int cnt = 0;
        int n = s.size();
        int lftCnt = 0;
        int rgtCnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                lftCnt++;
            }

            if (s[i] == 'R')
            {
                rgtCnt++;
            }

            if (lftCnt == rgtCnt)
            {
                cnt++;
                lftCnt = 0;
                rgtCnt = 0;
            }
        }

        return cnt;
    }
};