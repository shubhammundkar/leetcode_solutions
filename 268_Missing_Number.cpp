// LeetCode 268 - Missing Number
// Topic: Array, Math
//
// Approach:
// The array contains n distinct numbers taken from the range [0, n].
// Exactly one number is missing.
//
// The sum of numbers from 0 to n is:
//     n * (n + 1) / 2
//
// We calculate the expected sum and subtract the actual sum
// of elements in the array.
//
// Missing Number = Expected Sum - Actual Sum
//
// Example:
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