// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution
{
public:
    string removeDuplicates(string A)
    {
        stack<char> s;
        for (int i = 0; i < A.size(); i++)
        {
            if (s.empty() || s.top() != A[i])
            {
                s.push(A[i]);
            }
            else
            {
                s.pop();
            }
        }

        string str = "";
        while (!s.empty())
        {
            str.push_back(s.top());
            s.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};