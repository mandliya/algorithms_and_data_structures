#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// You are given an integer array prices where prices[i]
//  is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock.
//  You can only hold at most one share of the stock at any time.
//  However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve
// Input: prices = [7,1,5,3 ,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.

int func(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (idx == prices.size())
        return 0;
    int profit = 0;
    if (dp[idx][buy] != -1)
        return dp[idx][buy];
    if (buy)
    {
        profit = max(-prices[idx] + func(idx + 1, 0, prices, dp), func(idx + 1, 1, prices, dp));
    }
    else
    {
        profit = max(prices[idx] + func(idx + 1, 1, prices, dp), 0 + func(idx + 1, 0, prices, dp));
    }
    return dp[idx][buy] = profit;
}
int tabulation(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int profit = 0;
        for (int j = 0; j <= 1; j++)
        {

            if (j)
            {
                profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            }
            else
            {
                profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
            }
            dp[i][j] = profit;
        }
    }
    return dp[0][1];
}
int tabulationSpace(vector<int> &prices)
{
    int n = prices.size();
    vector<int> prev(2), curr(2);
    prev[0] = 0;
    prev[1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int profit = 0;
        for (int j = 0; j <= 1; j++)
        {

            if (j)
            {
                profit = max(-prices[i] + prev[0], 0 + prev[1]);
            }
            else
            {
                profit = max(prices[i] + prev[1], prev[0]);
            }
            curr[j] = profit;
        }
        prev = curr;
    }
    return prev[1];
}
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    // return func(0, 1, prices, dp);
    // return tabulation(prices);
    return tabulationSpace(prices);
}

int main()
{
    vector<int> prices = {1, 2, 3, 4, 5};
    cout << maxProfit(prices) << endl;
    return 0;
}