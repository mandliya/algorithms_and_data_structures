// You are given an array prices where prices[i]
//  is the price of a given stock on the ith day.

// Find the maximum profit you can achieve.
// You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day
// (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously
// (i.e., you must sell the stock before you buy again).

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (idx >= prices.size())
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
        profit = max(prices[idx] + func(idx + 2, 1, prices, dp), 0 + func(idx + 1, 0, prices, dp));
    }
    return dp[idx][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return func(0, 1, prices, dp);
}
int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}