
// LeetCode 2091 - Removing Minimum and Maximum From Array
// Topic: Array, Greedy
//
// Question:
// Given an array nums, remove the minimum and maximum elements
// using the minimum number of deletions.
//
// In one deletion, you can remove an element from either the beginning
// or the end of the array.
//
// Return the minimum number of deletions required.
//
//
// Approach:
// First, find the minimum and maximum values and their indices.
//
// There are only 3 possible strategies:
//
// 1. Delete both from the left:
//    We need to delete up to the rightmost index.
//
//    op1 = rightmost + 1
//
// 2. Delete both from the right:
//    We need to delete from the right up to the leftmost index.
//
//    op2 = n - leftmost
//
// 3. Delete one from the left and the other from the right:
//
//    op3 = (leftmost + 1) + (n - rightmost)
//
// Take the minimum of these three strategies.
//
//
// Example:
// nums = [2,10,7,5,4,1,8,6]
//
// Minimum = 1  -> index 5
// Maximum = 10 -> index 1
//
// leftmost  = 1
// rightmost = 5
//
// Strategy 1:
// Delete from left until index 5
// op1 = 5 + 1 = 6
//
// Strategy 2:
// Delete from right until index 1
// op2 = 8 - 1 = 7
//
// Strategy 3:
// Delete index 1 from left and index 5 from right
// op3 = (1 + 1) + (8 - 5)
//     = 2 + 3
//     = 5
//
// Minimum = 5
//
// Therefore, answer = 5
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
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2)
            return n;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int miniInd = 0;
        int maxiInd = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                maxiInd = i;
            }

            if(nums[i] < mini)
            {
                mini = nums[i];
                miniInd = i;
            }
        }

        int rightmost = max(miniInd, maxiInd);
        int leftmost = min(miniInd, maxiInd);

        // Strategy 1: delete both from left
        int op1 = rightmost + 1;

        // Strategy 2: delete both from right
        int op2 = n - leftmost;

        // Strategy 3: delete leftmost from left, rightmost from right
        int op3 = (leftmost + 1) + (n - rightmost);

        return min({op1, op2, op3});
    }
};
