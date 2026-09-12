
// LeetCode 3232 - Can Alice Win
// Topic: Array, Math
//
// Question:
// Given an array of positive integers nums, Alice wins if the sum
// of all single-digit numbers is NOT equal to the sum of all
// numbers with two or more digits.
//
// Return true if Alice wins, otherwise return false.
//
// Example:
// Input: nums = [5,10,15,3]
//
// Single-digit sum:
// 5 + 3 = 8
//
// Two-or-more-digit sum:
// 10 + 15 = 25
//
// Since 8 != 25:
//
// Output: true
//
//
// Approach:
// Traverse every number in the array.
//
// For each number, count its digits by repeatedly dividing it by 10.
//
// If digits == 1:
//     add the number to sum_sin_dig
//
// Otherwise:
//     add the number to sum_doub_dig
//
// Finally, compare both sums.
//
// If they are different, return true.
// Otherwise, return false.
//
//
// Example Walkthrough:
//
// nums = [5,10,15,3]
//
// 5  -> 1 digit  -> sum_sin_dig = 5
// 10 -> 2 digits -> sum_doub_dig = 10
// 15 -> 2 digits -> sum_doub_dig = 25
// 3  -> 1 digit  -> sum_sin_dig = 8
//
// 8 != 25
//
// Therefore, answer = true
//
//
// Time Complexity: O(n * d)
// n = number of elements
// d = number of digits
//
// Space Complexity: O(1)
//
//
// Final Code:

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum_sin_dig = 0;
        int sum_doub_dig = 0;
        int len = nums.size();
        bool result = false;

        for(int i = 0; i < len; i++)
        {
            int digits = 0;
            int curr_num = nums[i];

            while(curr_num != 0)
            {
                curr_num /= 10;
                digits++;
            }

            if(digits == 1)
            {
                sum_sin_dig += nums[i];
            }
            else
            {
                sum_doub_dig += nums[i];
            }
        }

        if(sum_sin_dig != sum_doub_dig)
        {
            result = true;
        }

        return result;
    }
};