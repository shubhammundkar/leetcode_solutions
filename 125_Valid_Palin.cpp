#include <iostream>
#include <string>
#include <cctype> // Required for isalnum and tolower

using namespace std;

class Solution {
public:
    // Function to check if a string is a palindrome, ignoring case and non-alphanumeric characters
    // Time Complexity: O(N) - single pass scan
    // Space Complexity: O(1) - performs operations in-place without extra strings
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // 1. Skip non-alphanumeric characters from the left pointer
            while (left < right && !isalnum(s[left])) { 
                left++;
            }
            // 2. Skip non-alphanumeric characters from the right pointer
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // 3. Compare characters by normalizing both to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // Found a mismatch, not a palindrome
            }
            
            // Move both pointers inward for the next comparison
            left++;
            right--;
        }
        return true; // Pointers met without any mismatches
    }
};

// Main function to execute and test the code in VS Code
int main() {
    Solution solver;
    
    // Test Case 1: Standard palindrome with mixed case, spaces, and punctuation
    string test1 = "A man, a plan, a canal: Panama";
    cout << "Test 1 (\"" << test1 << "\"): " 
         << (solver.isPalindrome(test1) ? "PASSED (True)" : "FAILED (False)") << endl;

    // Test Case 2: Non-palindrome string
    string test2 = "race a car";
    cout << "Test 2 (\"" << test2 << "\"): " 
         << (solver.isPalindrome(test2) ? "FAILED (True)" : "PASSED (False)") << endl;

    // Test Case 3: Empty string (or string with only spaces/punctuation)
    string test3 = "   ";
    cout << "Test 3 (\"" << test3 << "\"): " 
         << (solver.isPalindrome(test3) ? "PASSED (True)" : "FAILED (False)") << endl;

    return 0;
}
