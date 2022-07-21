// https : // leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> mp;

        for (auto ch : s)
            mp[ch]++;

        set<int> st;
        int cnt = 0;

        for (auto it : mp)
        {
            while (st.find(it.second) != st.end())
            {
                it.second--;
                cnt++;
            }

            if (it.second > 0)
                st.insert(it.second);
        }

        return cnt;
    }
};