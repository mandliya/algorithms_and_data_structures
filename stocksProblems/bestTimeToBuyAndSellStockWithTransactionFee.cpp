// You are given an array prices where prices[i]
// is the price of a given stock on the ith day,
// and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve.
// You may complete as many transactions as you like,
//  but you need to pay the transaction fee for each transaction.

// Note: You may not engage in multiple transactions simultaneously
// (i.e., you must sell the stock before you buy again).
// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp, int fee)
{
    if (idx == prices.size())
        return 0;
    int profit = 0;
    if (dp[idx][buy] != -1)
        return dp[idx][buy];
    if (buy)
    {
        profit = max(-prices[idx] + func(idx + 1, 0, prices, dp, fee), func(idx + 1, 1, prices, dp, fee));
    }
    else
    {
        profit = max(prices[idx] + func(idx + 1, 1, prices, dp, fee) - fee, 0 + func(idx + 1, 0, prices, dp, fee));
    }
    return dp[idx][buy] = profit;
}
int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));
    return func(0, 1, prices, dp, k);
}

int main()
{

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int transactionFee = 2;
    cout << maxProfit(prices, transactionFee) << endl;
    return 0;
}