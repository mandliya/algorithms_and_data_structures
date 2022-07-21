// https : // leetcode.com/problems/permutation-in-string/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> m;

        for (auto i : s1)
        {
            m[i]++;
        }

        int cnt = m.size();
        int i = 0;
        int j = 0;
        int k = s1.size();

        while (j < s2.size())
        {
            if (m.find(s2[j]) != m.end())
            {
                m[s2[j]]--;
                if (m[s2[j]] == 0)
                {
                    cnt--;
                }
            }

            if (j - i + 1 < k)
            {
                j++;
            }

            else if (j - i + 1 == k)
            {
                if (cnt == 0)
                {
                    return true;
                }

                if (m.find(s2[i]) != m.end())
                {
                    m[s2[i]]++;

                    if (m[s2[i]] == 1)
                    {
                        cnt++;
                    }
                }

                i++;
                j++;
            }
        }

        return false;
    }
};