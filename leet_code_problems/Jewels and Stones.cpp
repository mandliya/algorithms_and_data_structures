// https : // leetcode.com/problems/jewels-and-stones/

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {

        map<char, int> m;
        int cnt = 0;

        for (auto ch : stones)
        {
            m[ch]++;
        }

        for (int i = 0; i < jewels.length(); i++)
        {
            if (m.find(jewels[i]) != m.end())
            {
                cnt += m[jewels[i]];
            }
        }

        return cnt;
    }
};