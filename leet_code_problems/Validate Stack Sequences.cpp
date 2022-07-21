// https : // leetcode.com/problems/validate-stack-sequences/

// Stacks
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {

        int j = 0;
        int n = pushed.size();
        stack<int> st;

        for (int i = 0; i < pushed.size(); i++)
        {
            st.push(pushed[i]);

            while (!st.empty() and st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};

// Inplace Stack
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {

        int i = 0;
        int j = 0;

        for (int k : pushed)
        {
            pushed[i] = k;
            i++;

            while (i > 0 and pushed[i - 1] == popped[j])
            {
                i--;
                j++;
            }
        }

        return i == 0;
    }
};
