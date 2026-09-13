// LeetCode 507 - Perfect Number
// Topic: Math, Number Theory
//
// Question:
// A perfect number is a positive integer that is equal to the sum
// of its positive divisors, excluding itself.
//
// Example:
// Input: num = 28
//
// Divisors of 28:
// 1, 2, 4, 7, 14
//
// Sum = 1 + 2 + 4 + 7 + 14 = 28
//
// Output: true
//
//
// Approach:
// Start sum with 1 because 1 is a divisor of every number greater than 1.
//
// Check every number from 2 to num/2.
//
// If num is divisible by i:
//     i is a divisor
//     add i to sum
//
// We only go up to num/2 because no proper divisor of num
// can be greater than num/2.
//
// Finally:
//     if sum == num -> perfect number
//     otherwise -> not a perfect number
//
//
// Example Walkthrough:
//
// num = 28
//
// sum = 1
//
// 28 % 2 == 0 -> sum = 3
// 28 % 3 != 0
// 28 % 4 == 0 -> sum = 7
// 28 % 7 == 0 -> sum = 14
// 28 % 14 == 0 -> sum = 28
//
// sum == num
//
// Therefore, answer = true
//
//
// Edge Case:
//
// if(num <= 1)
//     return false;
//
// 1 is not a perfect number.
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
    bool checkPerfectNumber(int num) {
        if(num <= 1)
            return false;

        int sum = 1;

        for(int i = 2; i <= num / 2; i++)
        {
            if(num % i == 0)
            {
                sum += i;
            }
        }

        return (sum == num);
    }
};