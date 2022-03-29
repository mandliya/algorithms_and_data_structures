// https : // leetcode.com/problems/champagne-tower/

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {

        float dp[101][101] = {0};
        dp[0][0] = poured;

        for (int r = 0; r < query_row; r++)
        {
            for (int c = 0; c <= r; c++)
            {
                float overflow = (dp[r][c] - 1) / 2;

                if (overflow > 0)
                {
                    dp[r + 1][c] += overflow;
                    dp[r + 1][c + 1] += overflow;
                }
            }
        }

        if (dp[query_row][query_glass] > 1.0)
        {
            return 1.0;
        }
        else
        {
            return dp[query_row][query_glass];
        }
    }
};