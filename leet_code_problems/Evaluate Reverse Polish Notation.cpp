// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution
{
public:
    int evalRPN(vector<string> &A)
    {
        stack<int> s;

        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == "+" || A[i] == "/" || A[i] == "*" || A[i] == "-")
            {
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();

                if (A[i] == "+")
                {
                    s.push(v1 + v2);
                }
                else if (A[i] == "-")
                {
                    s.push(v2 - v1);
                }
                else if (A[i] == "*")
                {
                    s.push(v1 * v2);
                }
                else if (A[i] == "/")
                {
                    s.push(v2 / v1);
                }
            }
            else
            {
                s.push(atoi(A[i].c_str()));
            }
        }

        return s.top();
    }
};