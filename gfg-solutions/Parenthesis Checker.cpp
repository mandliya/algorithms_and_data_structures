// https : // practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

class Solution
{
public:
    bool ispar(string str)
    {
        stack<char> s;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' or str[i] == '{' or str[i] == '[')
            {
                s.push(str[i]);
            }
            else
            {
                if (s.empty())
                {
                    return false;
                }
                else if (str[i] == ')')
                {
                    if (s.top() == '(')
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (str[i] == ']')
                {
                    if (s.top() == '[')
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (str[i] == '}')
                {
                    if (s.top() == '{')
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if (s.empty())
        {
            return true;
        }

        return false;
    }
};