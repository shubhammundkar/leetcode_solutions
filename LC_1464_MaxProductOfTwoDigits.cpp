```cpp
// LeetCode 1464 - Maximum Product of Two Elements in an Array
// Topic: Array, Greedy
//
// Question:
// Given an integer array nums, find the maximum product of
// (nums[i] - 1) * (nums[j] - 1), where i != j.
//
// Example:
// Input: nums = [3,4,5,2]
//
// Output: 12
//
// Explanation:
// Choose 5 and 4:
//
// (5 - 1) * (4 - 1)
// = 4 * 3
// = 12
//
//
// Approach:
// Find the two largest values in the array.
//
// max1 stores the largest value.
// max2 stores the second largest value.
//
// Whenever we find a new largest value:
//
// max2 = max1
// max1 = current value
//
// If the current value is not larger than max1 but is larger
// than max2, update max2.
//
// Finally:
//
// return (max1 - 1) * (max2 - 1);
//
//
// Example Walkthrough:
//
// nums = [3,4,5,2]
//
// 3 -> max1 = 3
//
// 4 -> max2 = 3
//      max1 = 4
//
// 5 -> max2 = 4
//      max1 = 5
//
// 2 -> no change
//
// max1 = 5
// max2 = 4
//
// Answer:
// (5 - 1) * (4 - 1)
// = 4 * 3
// = 12
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
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max1)
            {
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2)
            {
                max2 = nums[i];
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
```
