// LeetCode 3871 - Count Commas in Range II
// Topic: Math
//
// Question:
// Given an integer n, count the total number of commas used when
// writing all integers from 1 to n in standard number formatting.
//
// Example:
// Input: n = 1,000,005
// Output: 999,012
//
// Explanation:
// Numbers from 1,000 onward contain at least one comma.
// Numbers from 1,000,000 onward contain one additional comma.
//
// Approach:
// Commas are added after every three digits.
//
// First comma:
// 10^3 = 1,000
// Every number >= 1,000 has at least 1 comma.
//
// Second comma:
// 10^6 = 1,000,000
// Every number >= 1,000,000 has 1 additional comma.
//
// Third comma:
// 10^9 = 1,000,000,000
// Every number >= 1,000,000,000 has 1 additional comma.
//
// Therefore, we process the thresholds:
//
// 10^3, 10^6, 10^9, 10^12, ...
//
// For each threshold, every number from that threshold to n
// contains one additional comma.
//
// Number of such numbers:
//     n - threshold + 1
//
// After processing one threshold, multiply it by 1000
// to move to the next comma position.
//
// Example walkthrough:
// n = 1,000,005
//
// threshold = 1,000
//
// Numbers from 1,000 to 1,000,005:
//     1,000,005 - 1,000 + 1
//   = 999,006
//
// These numbers each contribute 1 comma.
//
// Next threshold = 1,000,000
//
// Numbers from 1,000,000 to 1,000,005:
//     1,000,005 - 1,000,000 + 1
//   = 6
//
// These numbers each contribute 1 additional comma.
//
// Total commas:
//     999,006 + 6
//   = 999,012
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    long long countCommas(long long n) {
        long long threshold = 1000;
        long long commas = 0;

        while(n >= threshold) {
            commas += n - threshold + 1;

            if(threshold > LLONG_MAX / 1000)  //  If multiplying threshold by 1000 would exceed the maximum long long value, stop the loop. simple overflow check.
            {
                break;
            }

            threshold *= 1000;
        }

        return commas;
    }
};