/*
 * You are provided a vector of numbers, where each number represents
 * price of a stock on ith day. If you are permitted to only complete
 * one transaction per day (i.e buy one and sell one stock), design
 * an algorithm to find the maximum profit.
 * 
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5 
 * max. difference = 6-1 = 5
 * (not 7-1 = 6, as selling price needs to be larger than buying price)
 * 
 * Approach:
 * 
 * We need to find the maximum difference between two numbers in the array
 * (which would be maximum profit) such that selling price(second number)
 *  is bigger than buying price.
 */

#include <iostream>
#include <vector>
#include <limits>

int maximum_profit(const std::vector<int>& prices)
{
    int min_price = std::numeric_limits<int>::max();
    int max_profit = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
        }
    }
    return max_profit;
}

void print_vector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    std::cout << "Prices of stocks in last " << prices.size()
        << " days:" << std::endl;
    print_vector(prices);
    std::cout << "Maximum profit: " << maximum_profit(prices)
        << std::endl;

    return 0;
}