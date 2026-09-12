
// LeetCode 122 - Best Time to Buy and Sell Stock II
// Topic: Array, Greedy
//
// Question:
// You are given an array prices where prices[i] is the price of a stock
// on the ith day.
//
// You can buy and sell the stock multiple times, but you must sell
// before buying again.
//
// Return the maximum profit.
//
// Example:
// Input: prices = [7,1,5,3,6,4]
//
// Output: 7
//
// Explanation:
// Buy at 1, sell at 5  -> profit = 4
// Buy at 3, sell at 6  -> profit = 3
//
// Total profit = 4 + 3 = 7
//
//
// Approach:
// Use Greedy.
//
// Compare every price with the previous day's price.
//
// If today's price is greater than yesterday's price,
// add the difference to profit.
//
// prices[i] - prices[i-1]
//
// Why does Greedy work?
//
// Whenever the price goes UP, we take that profit.
// Whenever the price goes DOWN, we ignore it.
//
// For example:
//
// prices = [1,2,3,4]
//
// We can:
// Buy at 1 -> Sell at 4
// Profit = 4 - 1 = 3
//
// Greedy does:
//
// 1 -> 2 = +1
// 2 -> 3 = +1
// 3 -> 4 = +1
//
// Total = 1 + 1 + 1 = 3
//
// Both give the same profit.
//
// Therefore, taking every positive increase captures
// all possible profit.
//
// Easy way to remember:
//
// Price goes UP   -> take the profit
// Price goes DOWN -> ignore it
//
//
// Example Walkthrough:
//
// prices = [7,1,5,3,6,4]
//
// 1 > 7  -> no profit
// 5 > 1  -> profit += 4
// 3 > 5  -> no profit
// 6 > 3  -> profit += 3
// 4 > 6  -> no profit
//
// Final profit = 4 + 3 = 7
//
//
// Time Complexity: O(n)
//
// Space Complexity: O(1)
//
//
// Final Code:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
