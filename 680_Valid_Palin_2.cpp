#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function to check if a specific substring is a strict palindrome
    // Passed by reference (const string&) to prevent copying string data into memory
    bool isSubPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                return false; // Substring contains a mismatch; it's not a palindrome
            }
        }
        return true; // Checked all characters without finding a mismatch
    }
    
    // Main function to check if the string can be a palindrome after deleting at most 1 character
    // Time Complexity: O(N) - single pass scan with up to two small substring checks
    // Space Complexity: O(1) - constant space because strings are passed by reference
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                // Mismatch found! Try skipping either the character at 'left' OR the character at 'right'.
                // If either resulting substring is a valid palindrome, the overall condition is met.
                return (isSubPalindrome(s, left + 1, right) || isSubPalindrome(s, left, right - 1));
            }
        }
        return true; // The original string was already a perfect palindrome without any deletions
    }
};

// Main function to execute and test the code in VS Code
int main() {
    Solution solver;
    
    // Test Case 1: Already a perfect palindrome
    string test1 = "aba";
    cout << "Test 1 (\"" << test1 << "\"): " 
         << (solver.validPalindrome(test1) ? "PASSED (True)" : "FAILED (False)") << endl;

    // Test Case 2: Becomes a palindrome after deleting 'c' from the middle
    string test2 = "abca";
    cout << "Test 2 (\"" << test2 << "\"): " 
         << (solver.validPalindrome(test2) ? "PASSED (True)" : "FAILED (False)") << endl;

    // Test Case 3: Completely invalid (requires deleting more than 1 character)
    string test3 = "abcde";
    cout << "Test 3 (\"" << test3 << "\"): " 
         << (solver.validPalindrome(test3) ? "FAILED (True)" : "PASSED (False)") << endl;

    return 0;
}
