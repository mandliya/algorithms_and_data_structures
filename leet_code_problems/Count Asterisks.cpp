// https : // leetcode.com/problems/count-asterisks/

class Solution
{
public:
    int countAsterisks(string s)
    {

        int bar = 0;
        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '|')
            {
                cnt++;
            }

            if (cnt == 2)
            {
                bar = 1;
                cnt = 0;
            }

            if (cnt == 0 and s[i] == '*')
            {
                ans++;
            }
        }

        return ans;
    }
};