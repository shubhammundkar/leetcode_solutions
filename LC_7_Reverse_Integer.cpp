
// LeetCode 7 - Reverse Integer
// Topic: Math
//
// Question:
// Given a signed 32-bit integer x, return x with its digits reversed.
//
// If the reversed number goes outside the 32-bit signed integer range,
// return 0.
//
// Example:
// Input: x = 123
//
// Output: 321
//
//
// Approach:
// Extract the last digit using % 10.
//
// Add that digit to reverse:
//
// reverse = reverse * 10 + rem
//
// Remove the last digit from x using / 10.
//
// Repeat until x becomes 0.
//
// We use long long for reverse so that we can safely check
// whether the reversed number exceeds the 32-bit integer range.
//
// Finally, check:
//
// reverse > INT_MAX
// OR
// reverse < INT_MIN
//
// If either condition is true, return 0.
//
// Otherwise, return reverse.
//
//
// Example Walkthrough:
//
// x = 123
//
// rem = 123 % 10 = 3
// reverse = 0 * 10 + 3 = 3
// x = 123 / 10 = 12
//
// rem = 12 % 10 = 2
// reverse = 3 * 10 + 2 = 32
// x = 12 / 10 = 1
//
// rem = 1 % 10 = 1
// reverse = 32 * 10 + 1 = 321
// x = 1 / 10 = 0
//
// Final answer = 321
//
//
// Time Complexity: O(d)
// where d = number of digits
//
// Space Complexity: O(1)
//
//
// Final Code:

class Solution {
public:
    int reverse(int x) {
        
        long long reverse = 0;

        while(x != 0)
        {
            long long rem = x % 10;
            reverse = reverse * 10 + rem;
            x /= 10;
        }
        
        if(reverse > INT_MAX || reverse < INT_MIN)
        {
            return 0;
        }

        return reverse;
    }
};
