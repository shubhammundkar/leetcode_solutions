```cpp
// LeetCode 728 - Self Dividing Numbers
// Topic: Array, Math
//
// Question:
// A self-dividing number is a number that is divisible by every digit
// it contains.
//
// Return all self-dividing numbers between left and right.
//
// Example:
// Input: left = 1, right = 22
//
// Output:
// [1,2,3,4,5,6,7,8,9,11,12,15,22]
//
// Explanation:
// 12 is self-dividing because:
// 12 % 1 == 0
// 12 % 2 == 0
//
// 13 is not self-dividing because:
// 13 % 3 != 0
//
//
// Approach:
// Check every number from left to right.
//
// For each number, use a temporary variable `dummy` to extract
// its digits without changing the original number.
//
// dummy % 10 -> gets the last digit
// dummy / 10 -> removes the last digit
//
// For every digit:
// 1. If digit == 0, the number is invalid because division by 0
//    is not possible.
// 2. Check if the original number is divisible by that digit.
//
// If any digit fails, set isValid = false and stop checking.
//
// If all digits are valid, add the number to ans.
//
//
// Example Walkthrough:
//
// i = 12
//
// dummy = 12
//
// curr_num = 12 % 10 = 2
// 12 % 2 == 0 -> valid
//
// dummy = 12 / 10 = 1
//
// curr_num = 1
// 12 % 1 == 0 -> valid
//
// dummy = 1 / 10 = 0
//
// All digits are valid.
//
// Add 12 to ans.
//
//
// Important Idea:
//
// int dummy = i;
//
// We use `dummy` because we need to keep the original `i`
// for this check:
//
// i % curr_num == 0
//
// If we directly changed `i` while extracting digits,
// we would lose the original number.
//
//
// `isValid` is used to remember whether all digits are valid.
//
// If one digit fails:
//
// isValid = false;
// break;
//
// Then we don't need to check the remaining digits.
//
//
// Time Complexity: O(n * d)
//
// n = number of numbers from left to right
// d = number of digits in each number
//
// Space Complexity: O(k)
//
// k = number of self-dividing numbers stored in ans
//
//
// Final Code:

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for(int i = left; i <= right; i++)
        {
            int dummy = i;
            bool isValid = true;

            while(dummy != 0)
            {
                int curr_num = dummy % 10;

                if(curr_num == 0 || i % curr_num != 0)
                {
                    isValid = false;
                    break;
                }

                dummy = dummy / 10;
            }

            if(isValid)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```
