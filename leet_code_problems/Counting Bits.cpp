// https : // leetcode.com/problems/counting-bits/

class Solution
{
public:
    vector<int> countBits(int n)
    {

        vector<int> ans;

        for (int i = 0; i <= n; i++)
        {
            int num = i;
            int sum = 0;

            while (num != 0)
            {
                sum += num % 2;
                num /= 2;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
x