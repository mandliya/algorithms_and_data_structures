// https : // leetcode.com/problems/generate-parentheses/

class Solution
{
public:
    void helper(vector<string> &v, int n, int open, int close, int i, string s)
    {
        if (i == 2 * n)
        {
            v.push_back(s);
            return;
        }

        if (open < n)
        {
            helper(v, n, open + 1, close, i + 1, s + '(');
        }

        if (close < open)
        {
            helper(v, n, open, close + 1, i + 1, s + ')');
        }
    }

    vector<string> generateParenthesis(int n)
    {

        string s;
        vector<string> v;

        helper(v, n, 0, 0, 0, s);

        return v;
    }
};