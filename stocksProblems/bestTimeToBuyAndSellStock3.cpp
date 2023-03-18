#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// You are given an array prices where prices[i]
// is the price of a given stock on the ith day.

// Find the maximum profit you can achieve.
// You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously
// (i.e., you must sell the stock before you buy again).

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1)
// and sell on day 8 (price = 4), profit = 4-1 = 3.
int func(int idx, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp, int count)
{
    if (idx == prices.size())
        return 0;
    if (count == 0)
        return 0;
    int profit = 0;
    if (dp[idx][buy][count] != -1)
        return dp[idx][buy][count];
    if (buy)
    {
        profit = max(-prices[idx] + func(idx + 1, 0, prices, dp, count), func(idx + 1, 1, prices, dp, count));
    }
    else
    {
        profit = max(prices[idx] + func(idx + 1, 1, prices, dp, count - 1), 0 + func(idx + 1, 0, prices, dp, count));
    }
    return dp[idx][buy][count] = profit;
}
int tabulation(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
    for (int buy = 0; buy <= 1; buy++)
    {
        for (int count = 0; count <= 2; count++)
            dp[n][buy][count] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            dp[i][j][0] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int profit = 0;
        for (int j = 0; j <= 1; j++)
        {
            for (int count = 1; count <= 2; count++)
            {
                if (j)
                {
                    profit = max(-prices[i] + dp[i + 1][0][count], 0 + dp[i + 1][1][count]);
                }
                else
                {
                    profit = max(prices[i] + dp[i + 1][1][count - 1], dp[i + 1][0][count]);
                }
                dp[i][j][count] = profit;
            }
        }
    }
    return dp[0][1][2];
}
int tabulationSpace2D(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3)), curr(2, vector<int>(3));
    for (int buy = 0; buy <= 1; buy++)
    {
        for (int count = 0; count <= 2; count++)
            prev[buy][count] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            prev[j][0] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int profit = 0;
        for (int j = 0; j <= 1; j++)
        {
            for (int count = 1; count <= 2; count++)
            {
                if (j)
                {
                    profit = max(-prices[i] + prev[0][count], 0 + prev[1][count]);
                }
                else
                {
                    profit = max(prices[i] + prev[1][count - 1], prev[0][count]);
                }
                curr[j][count] = profit;
            }
        }
        prev = curr;
    }
    return prev[1][2];
}
int maxProfit(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
    // return func(0, 1, prices, dp, 2);
    // return tabulation(prices);
    return tabulationSpace2D(prices);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}