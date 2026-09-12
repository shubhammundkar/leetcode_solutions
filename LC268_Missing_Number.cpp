// LeetCode 268 - Missing Number
// Topic: Array, Math
//
// Question:
// Given an array containing n distinct numbers from the range [0, n],
// exactly one number is missing.
// Return the missing number.
//
// Example:
// Input: nums = [3, 0, 1]
// Output: 2
//
// Explanation:
// The numbers from 0 to 3 are:
// 0, 1, 2, 3
//
// The array contains:
// 0, 1, 3
//
// Therefore, 2 is missing.
//
// Approach:
// Calculate the expected sum of all numbers from 0 to n:
//
//     Sum = n * (n + 1) / 2
//
// Then calculate the actual sum of all elements in the array.
//
// The difference between the expected sum and actual sum
// gives the missing number.
//
// Missing Number = Expected Sum - Actual Sum
//
// Example walkthrough:
// nums = [3, 0, 1]
//
// n = 3
// Expected sum = 3 * 4 / 2 = 6
// Actual sum   = 3 + 0 + 1 = 4
//
// Missing number = 6 - 4 = 2
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return n * (n + 1) / 2 - sum;
    }
};