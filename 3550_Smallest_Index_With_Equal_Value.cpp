```cpp
// LeetCode 2057 - Smallest Index With Equal Value
// Topic: Array, Math
//
// Question:
// Given an integer array nums, return the smallest index i such that
// the sum of the digits of nums[i] is equal to i.
//
// If no such index exists, return -1.
//
// Example:
// Input: nums = [1,2,3,4,5,6]
//
// For index 5:
// nums[5] = 6
// Digit sum = 6
//
// Since digit sum == index:
// Output: 5
//
//
// Approach:
// Traverse the array from left to right.
//
// For every number, calculate its digit sum.
//
// num % 10 -> gets the last digit
// num / 10 -> removes the last digit
//
// After calculating the digit sum:
//
// if(sum == i)
//     return i;
//
// Since we check from left to right, the first match is
// automatically the smallest index.
//
//
// Example Walkthrough:
//
// nums = [10,21,30,4]
//
// i = 0:
// 10 -> 1 + 0 = 1
// 1 != 0
//
// i = 1:
// 21 -> 2 + 1 = 3
// 3 != 1
//
// i = 2:
// 30 -> 3 + 0 = 3
// 3 != 2
//
// i = 3:
// 4 -> 4
// 4 != 3
//
// No match -> return -1.
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
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            int num = nums[i];

            while(num != 0)
            {
                sum += num % 10;
                num = num / 10;
            }

            if(sum == i)
            {
                return i;
            }
        }

        return -1;
    }
};
```
