// LeetCode 1295 - Find Numbers with Even Number of Digits
// Topic: Array, Math
//
// Question:
// Given an array of integers nums, return how many of them contain
// an even number of digits.
//
// Example:
// Input: nums = [12, 345, 2, 6, 7896]
//
// Output: 2
//
// Explanation:
// 12 has 2 digits  -> even
// 345 has 3 digits -> odd
// 2 has 1 digit    -> odd
// 6 has 1 digit    -> odd
// 7896 has 4 digits -> even
//
// Therefore, the answer is 2.
//
//
// Approach:
// Traverse every number in the array.
//
// For each number, repeatedly divide it by 10.
// Every division removes one digit.
//
// For example:
// 7896
// 7896 / 10 = 789
// 789  / 10 = 78
// 78   / 10 = 7
// 7    / 10 = 0
//
// Number of divisions = 4
// Therefore, 7896 has 4 digits.
//
// If the digit count is even, increment ans.
//
// Finally, return ans.
//
//
// Example Walkthrough:
//
// nums = [12, 345, 7896]
//
// For 12:
// 12 -> 1 -> 0
// count = 2
// 2 % 2 == 0
// ans = 1
//
// For 345:
// 345 -> 34 -> 3 -> 0
// count = 3
// 3 % 2 != 0
// ans = 1
//
// For 7896:
// 7896 -> 789 -> 78 -> 7 -> 0
// count = 4
// 4 % 2 == 0
// ans = 2
//
// Final answer = 2
//
//
// Time Complexity: O(n * d)
// where n = number of elements and d = number of digits
//
// Space Complexity: O(1)

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {   
            int count=0;
            while(nums[i]!=0)
            {
                nums[i]/=10;
                count++;
            }
            if(count%2==0)
            {
                ans++;
            }

        }
        return ans;
    }
};