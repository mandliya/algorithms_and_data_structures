/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
 * Design an algorithm to find the maximum profit.
 */

#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
	if (prices.size() == 0 ) {
		return 0;
	}
	std::vector<int> dp(prices.size());
	dp[0] = 0;
	int buyPrice = prices[0];
	int mostProfit = 0;
	for ( size_t i = 1; i < prices.size(); ++i ) {
		if ( prices[i] >= buyPrice ) {
			dp[i] = dp[i-1] + prices[i] - prices[i-1];
		} else {
			dp[i] = 0;
			buyPrice = prices[i];
		}
		if (mostProfit < dp[i]) {
			mostProfit = dp[i];
		}
	}
	return mostProfit;
}

void printStocks( std::vector<int> & stocks ) {
	std::cout << "Stock prices:";
	for ( auto stock : stocks ) {
		std::cout << stock << " ";
	}
	std::cout << std::endl;
}
int main() {
	std::vector<int> prices{ 45, 33, 66, 78, 90, 47 };
	printStocks(prices);
	std::cout << "Max profit from above price range:" << maxProfit(prices) << std::endl;
	return 0;
}
