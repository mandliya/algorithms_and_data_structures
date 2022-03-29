// https : // leetcode.com/problems/final-value-of-variable-after-performing-operations/

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int x = 0;

        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "--X" or operations[i] == "X--")
            {
                x -= 1;
            }
            else
            {
                x += 1;
            }
        }

        return x;
    }
};