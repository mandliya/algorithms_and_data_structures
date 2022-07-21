// https : // leetcode.com/problems/palindrome-partitioning/

class Solution
{
public:
    bool isValid(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    void findPartition(vector<vector<string>> &ans, vector<string> &ds, string s, int idx)
    {
        if (idx == s.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (isValid(s, idx, i))
            {
                ds.push_back(s.substr(idx, i - idx + 1));
                findPartition(ans, ds, s, i + 1);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {

        vector<vector<string>> ans;
        vector<string> ds;

        int idx = 0;

        findPartition(ans, ds, s, idx);

        return ans;
    }
};