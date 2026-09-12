// LeetCode 2485 - Find the Pivot Integer
// Topic: Math
//
// Question:
// Given a positive integer n, find an integer x such that
// the sum of all numbers from 1 to x is equal to the sum
// of all numbers from x to n.
//
// If no such integer exists, return -1.
//
// Example:
// Input: n = 8
// Output: 6
//
// Explanation:
//
// Left side:
// 1 + 2 + 3 + 4 + 5 + 6 = 21
//
// Right side:
// 6 + 7 + 8 = 21
//
// Since both sums are equal, x = 6.
//
// Approach:
// The total sum from 1 to n is:
//
//     sum = n * (n + 1) / 2
//
// For a pivot integer x:
//
//     1 + 2 + ... + x = x + (x + 1) + ... + n
//
// This condition simplifies to:
//
//     x * x = sum
//
// Therefore, we only need to check whether the total sum
// is a perfect square.
//
// If sum is a perfect square:
//
//     x = sqrt(sum)
//
// Otherwise, return -1.
//
// Example walkthrough:
// n = 8
//
// sum = 8 * 9 / 2
//     = 36
//
// sqrt(36) = 6
//
// 6 * 6 = 36
//
// Therefore, the pivot integer is 6.
//
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;

        int x = sqrt(sum);

        if(x * x == sum) {
            return x;
        }

        return -1;
    }
};