// LeetCode 9 - Palindrome Number
// Topic: Math
//
// Question:
// Given an integer x, return true if x reads the same forward
// and backward. Otherwise, return false.
//
// Example:
// Input: x = 121
// Output: true
//
// Explanation:
// 121 reversed is 121, so it is a palindrome.
//
// Approach:
// Store the original number and reverse the digits of x.
// Then compare the reversed number with the original number.
//
// Negative numbers are not palindromes.
// A number ending in 0 is not a palindrome unless the number is 0.
//
// Example walkthrough:
// x = 121
//
// digit = 1 -> reverse = 1
// digit = 2 -> reverse = 12
// digit = 1 -> reverse = 121
//
// reverse == original
// Therefore, return true.
//
// Time Complexity: O(log10(n))
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;

        long long rev = 0;
        int original = x;

        while(x != 0) {
            int rem = x % 10;
            rev = rev * 10 + rem;
            x = x / 10;
        }

        return rev == original;
    }
};