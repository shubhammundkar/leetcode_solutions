// LeetCode 9 - Palindrome Number
//
// Approach:
// Reverse the given number and compare it with the original number.
// If both are equal, the number is a palindrome.
//
// Example:
// x = 121
// Reverse = 121
// Since original == reverse, return true.
//
// Important:
// - Negative numbers are not palindromes.
// - Numbers ending in 0 are not palindromes (except 0).
//
// Time Complexity: O(log10(n))
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers and numbers ending with 0
        // (except 0 itself) cannot be palindromes.
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int original = x;
        long long reverse = 0;

        while (x != 0) {
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
        }

        return reverse == original;
    }
};