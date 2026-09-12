// LeetCode 14 - Longest Common Prefix
// Topic: String, Array
//
// Question:
// Given an array of strings, find the longest common prefix
// shared by all the strings.
//
// If there is no common prefix, return an empty string.
//
// Example:
// Input: strs = ["flower", "flow", "flight"]
// Output: "fl"
//
// Explanation:
// The strings have the characters 'f' and 'l' in common
// at the beginning.
//
// "flower"
// "flow"
// "flight"
//  ^^
//  fl
//
// Approach:
// First, find the length of the shortest string.
// The common prefix cannot be longer than the shortest string.
//
// Then compare the characters column by column.
//
// For every index:
//     1. Take the character from the first string.
//     2. Compare it with the character at the same index
//        in every other string.
//     3. If any character is different, return the prefix
//        collected so far.
//     4. Otherwise, add the character to the answer.
//
// Example walkthrough:
// strs = ["flower", "flow", "flight"]
//
// Step 1: Find minimum string length.
//
// "flower" -> 6
// "flow"   -> 4
// "flight" -> 6
//
// mini = 4
//
// Step 2: Compare characters.
//
// Index 0:
// "flower" -> f
// "flow"   -> f
// "flight" -> f
// All same -> ans = "f"
//
// Index 1:
// "flower" -> l
// "flow"   -> l
// "flight" -> l
// All same -> ans = "fl"
//
// Index 2:
// "flower" -> o
// "flow"   -> o
// "flight" -> i
//
// Characters are different, so return "fl".
//
// Time Complexity: O(n * m)
// Space Complexity: O(1)
// where n = number of strings and m = length of the shortest string.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";

        int mini = strs[0].length();

        for(int i = 0; i < strs.size(); i++) {
            int len = strs[i].length();
            mini = min(mini, len);
        }

        string ans = "";

        for(int i = 0; i < mini; i++) {
            char current_string_char = strs[0][i];

            for(int j = 0; j < strs.size(); j++) {
                if(current_string_char != strs[j][i]) {
                    return ans;
                }
            }

            ans.push_back(current_string_char);
        }

        return ans;
    }
};