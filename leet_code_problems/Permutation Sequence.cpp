// https : // leetcode.com/problems/permutation-sequence/

class Solution
{
public:
    string getPermutation(int n, int k)
    {

        int fact = 1;
        vector<int> val;

        for (int i = 1; i < n; i++)
        {
            fact *= i;
            val.push_back(i);
        }

        val.push_back(n);

        string res = "";
        k--; // coz we're following 0-indexing

        while (true)
        {
            res += to_string(val[k / fact]);
            val.erase(val.begin() + k / fact);

            if (val.size() == 0)
            {
                break;
            }

            k = k % fact;
            fact = fact / val.size();
        }

        return res;
    }
};