// https : // practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

class Solution
{
public:
    unordered_map<string, int> mpp;
    int mod = 1003;

    int solve(string S, int i, int j, bool is_true)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (is_true == true)
                return S[i] == 'T';
            else
                return S[i] == 'F';
        }

        string tmp = to_string(i) + " " + to_string(j) + " " + to_string(is_true);
        if (mpp.find(tmp) != mpp.end())
            return mpp[tmp];
        int ans = 0;

        for (int k = i + 1; k < j; k = k + 2)
        {
            int left_true = solve(S, i, k - 1, true);
            int right_true = solve(S, k + 1, j, true);
            int left_false = solve(S, i, k - 1, false);
            int right_false = solve(S, k + 1, j, false);

            if (S[k] == '&')
            {
                if (is_true == true)
                    ans += left_true * right_true;
                else
                    ans += left_false * right_false + left_true * right_false + right_true * left_false;
            }
            else if (S[k] == '|')
            {
                if (is_true == true)
                    ans += left_true * right_false + right_true * left_false + left_true * right_true;
                else
                    ans += left_false * right_false;
            }
            else if (S[k] == '^')
            {
                if (is_true == true)
                    ans += left_true * right_false + left_false * right_true;
                else
                    ans += left_false * right_false + left_true * right_true;
            }
        }

        return mpp[tmp] = ans % mod;
    }

    int countWays(int N, string S)
    {
        mpp.clear();
        return solve(S, 0, N - 1, true);
    }
};