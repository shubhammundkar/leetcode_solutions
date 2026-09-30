/*
====================================================================
LeetCode 125. Valid Palindrome
Difficulty : Easy
Topics     : String, Two Pointers
Link       : https://leetcode.com/problems/valid-palindrome/
====================================================================

PROBLEM
-------
A phrase is a palindrome if, after converting all uppercase letters
to lowercase and removing all non-alphanumeric characters, it reads
the same forward and backward.
Given a string s, return true if it is a palindrome, else false.

EXAMPLES
--------
Input : "A man, a plan, a canal: Panama"
Output: true    ("amanaplanacanalpanama")

Input : "race a car"
Output: false   ("raceacar")

Input : " "
Output: true    (empty string after cleaning is a palindrome)

CONSTRAINTS
-----------
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.

====================================================================
APPROACH 1: Clean + Two Pointers (my solution)
====================================================================
Idea:
  1. Build a new string `k` containing only lowercase letters and digits.
       - Uppercase 'A'-'Z' (ASCII 65-90) -> add 32 to make lowercase.
       - Keep only 'a'-'z' (97-122) and '0'-'9' (48-57).
  2. Use two pointers: left at start, right at end.
  3. If k[left] != k[right] -> not a palindrome, return false.
  4. Move pointers inward until they meet. If no mismatch -> true.

Time Complexity : O(n)  -> one pass to clean + one pass to compare
Space Complexity: O(n)  -> extra string `k`

ASCII cheat sheet:
  '0'-'9' = 48-57
  'A'-'Z' = 65-90
  'a'-'z' = 97-122
  'a' - 'A' = 32  (that's why +32 converts upper -> lower)

====================================================================
APPROACH 2: Two Pointers, no extra string (optimal space)
====================================================================
Idea:
  - Don't build a new string. Compare directly on the original `s`.
  - Move `left` forward while s[left] is not alphanumeric.
  - Move `right` backward while s[right] is not alphanumeric.
  - Compare the two characters (case-insensitive). Mismatch -> false.

Time Complexity : O(n)  -> each pointer travels the string at most once
Space Complexity: O(1)  -> no extra storage

Takeaway: same idea as Approach 1, but skip the cleaning step.
This is the version interviewers usually like to see.

====================================================================
NOTES / THINGS TO REMEMBER
====================================================================
- Digits count as valid characters ('0'-'9'), don't drop them.
- An empty cleaned string (e.g. " " or ".,") is a palindrome -> true.
- Alternative: use built-ins isalnum() and tolower() from <cctype>
  for shorter code (manual ASCII version below is good for understanding).
- Pattern to recall: "check symmetry" => two pointers from both ends.
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------------------
// Approach 1: Clean string, then two pointers  | O(n) time, O(n) space
// ---------------------------------------------------------------
class Solution {
public:
    bool isPalindrome(string s) {
        string k = "";

        // Step 1: clean string and convert to lowercase
        for (char c : s) {
            // uppercase -> lowercase (adding 32 converts 'A'-'Z' to 'a'-'z')
            if (c <= 90 && c >= 65) {
                c = c + 32;
            }

            // keep only lowercase letters and digits
            if ((c <= 122 && c >= 97) || (c >= 48 && c <= 57)) {
                k.push_back(c);
            }
        }

        // Step 2: two pointers comparison
        int left = 0, right = k.size() - 1;
        while (left < right) {
            if (k[left] != k[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// ---------------------------------------------------------------
// Approach 2: In-place two pointers  | O(n) time, O(1) space
// ---------------------------------------------------------------
class SolutionOptimal {
    // helper: is c a letter or digit?
    bool isAlnum(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }

    // helper: convert uppercase to lowercase, leave others unchanged
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') return c + 32;
        return c;
    }

public:
    bool isPalindrome(string s) {
        int left = 0, right = (int)s.size() - 1;

        while (left < right) {
            // skip non-alphanumeric characters on both sides
            while (left < right && !isAlnum(s[left]))  left++;
            while (left < right && !isAlnum(s[right])) right--;

            if (toLower(s[left]) != toLower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// ---------------------------------------------------------------
// Local testing (not needed on LeetCode)
// ---------------------------------------------------------------
int main() {
    Solution sol1;
    SolutionOptimal sol2;

    string tests[] = {
        "A man, a plan, a canal: Panama",  // true
        "race a car",                      // false
        " ",                               // true
        "0P"                               // false
    };

    for (const string& t : tests) {
        cout << "\"" << t << "\" -> "
             << boolalpha << sol1.isPalindrome(t) << " | "
             << sol2.isPalindrome(t) << "\n";
    }
    return 0;
}