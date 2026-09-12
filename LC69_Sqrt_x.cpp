// LeetCode 69 - Sqrt(x)
// Topic: Math, Binary Search
//
// Question:
// Given a non-negative integer x, return the square root of x
// rounded down to the nearest integer.
// The returned integer should be non-negative.
//
// You are not allowed to use any built-in exponent function
// or operator, such as pow(x, 0.5) or x ** 0.5.
//
// Example:
// Input: x = 8
// Output: 2
//
// Explanation:
// The square root of 8 is approximately 2.828.
// Rounding it down gives 2.
//
// Approach:
// We need to find the largest integer i such that:
//     i * i <= x
//
// We start from 1 and keep increasing i while:
//     i * i <= x
//
// When the condition becomes false, i is one greater than
// the required answer, so we return i - 1.
//
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)

class Solution {
public:
    int mySqrt(int x) {
        long long i = 1;

        while(i * i <= x) {
            i++;
        }

        return i - 1;
    }
};