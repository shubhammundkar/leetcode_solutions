```cpp
// LeetCode 167 - Two Sum II - Input Array Is Sorted
// Topic: Array, Two Pointers
//
// Question:
// Given a 1-indexed array of integers numbers that is already sorted
// in non-decreasing order, find two numbers whose sum equals target.
//
// Return their 1-based indices.
//
// Example:
// Input: numbers = [2,7,11,15], target = 9
//
// Output: [1,2]
//
// Explanation:
// numbers[0] + numbers[1]
// = 2 + 7
// = 9
//
//
// Approach:
// Use two pointers:
//
// left  -> starts from the beginning
// right -> starts from the end
//
// Calculate:
//
// curr_sum = numbers[left] + numbers[right]
//
// If curr_sum == target:
//     answer found.
//
// If curr_sum < target:
//     increase left.
//
// If curr_sum > target:
//     decrease right.
//
//
// Why does this work?
//
// The array is sorted.
//
// If the sum is too small, moving right further left would make
// the sum even smaller, so we increase left.
//
// If the sum is too large, moving left further right would make
// the sum even larger, so we decrease right.
//
//
//
// Example Walkthrough:
//
// numbers = [2,7,11,15]
// target = 9
//
// left = 0, right = 3
// 2 + 15 = 17 > 9
// right--
//
// 2 + 11 = 13 > 9
// right--
//
// 2 + 7 = 9
// target found.
//
// Return {left + 1, right + 1}
//
// We add 1 because the question uses 1-based indexing.
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right)
        {
            int curr_sum = numbers[left] + numbers[right];

            if(curr_sum == target)
            {
                return {left + 1, right + 1};
            }
            else if(curr_sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return {};
    }
};
```
