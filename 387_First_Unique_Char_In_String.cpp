```cpp
// LeetCode 387 - First Unique Character in a String
// Topic: String, Hashing
//
// Question:
// Given a string s, find the first character that does not repeat.
// Return its index. If no unique character exists, return -1.
//
// Example:
// Input: s = "leetcode"
//
// Output: 0
//
// Explanation:
// 'l' appears only once, so its index is 0.
//
//
// Approach:
// Use a frequency array of size 26 because the string contains
// only lowercase English letters.
//
// First, count the frequency of every character.
//
// hash[c - 'a']++;
//
// Here:
// 'a' - 'a' = 0
// 'b' - 'a' = 1
// 'c' - 'a' = 2
// ...
// 'z' - 'a' = 25
//
// Then traverse the string again.
//
// If:
//
// hash[s[i] - 'a'] == 1
//
// that character occurs only once, so return its index.
//
// We traverse the string from left to right, so the first one found
// is automatically the first unique character.
//
//
// Example Walkthrough:
//
// s = "leetcode"
//
// Frequencies:
//
// l -> 1
// e -> 3
// t -> 1
// c -> 1
// o -> 1
// d -> 1
//
// Traverse again:
//
// i = 0 -> 'l'
// hash['l' - 'a'] == 1
//
// Therefore, return 0.
//
//
// Important Idea:
//
// hash[c - 'a']++;
//
// converts a character into an array index.
//
// For example:
//
// c = 'd'
//
// 'd' - 'a' = 3
//
// So:
//
// hash[3]++;
//
//
// Time Complexity: O(n)
//
// Space Complexity: O(1)
// Since the frequency array always has 26 elements.
//
//
// Final Code:

class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26] = {0};

        // Count frequency of every character
        for(char c : s)
        {
            hash[c - 'a']++;
        }

        // Find the first character with frequency 1
        for(int i = 0; i < s.size(); i++)
        {
            if(hash[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};
```
