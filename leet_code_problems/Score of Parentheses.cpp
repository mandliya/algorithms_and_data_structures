// https : // leetcode.com/submissions/detail/661587983/

class Solution
{
public:
    int scoreOfParentheses(string s)
    {

        stack<int> st;
        int idx = 0;

        for (auto i : s)
        {
            if (i == '(')
            {
                st.push(idx);
                idx = 0;
            }
            else
            {
                idx = st.top() + max(2 * idx, 1);
                st.pop();
            }
        }

        return idx;
    }
};