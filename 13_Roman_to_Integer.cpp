// LeetCode 13 - Roman to Integer
// Topic: String, Math
//
// Question:
// Given a string containing a Roman numeral, convert it into
// its corresponding integer value.
//
// Roman numeral values:
//
// I = 1
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000
//
// A smaller value before a larger value is subtracted.
//
// Examples:
// IV = 4
// IX = 9
// XL = 40
// XC = 90
// CD = 400
// CM = 900
//
// Example:
// Input: s = "MCMXCIV"
// Output: 1994
//
// Explanation:
// M    = 1000
// CM   = 900
// XC   = 90
// IV   = 4
//
// Total = 1000 + 900 + 90 + 4
//       = 1994
//
// Approach:
// Traverse the Roman numeral from left to right.
//
// For every character, get its integer value.
//
// If the current value is smaller than the value of the
// next character, subtract the current value.
//
// Otherwise, add the current value.
//
// Rule:
//
// current < next  -> subtract current
// current >= next -> add current
//
// Example walkthrough:
// s = "MCMXCIV"
//
// M:
// current = 1000, next = 100
// 1000 > 100 -> add
// total = 1000
//
// C:
// current = 100, next = 1000
// 100 < 1000 -> subtract
// total = 900
//
// M:
// current = 1000, next = 10
// 1000 > 10 -> add
// total = 1900
//
// X:
// current = 10, next = 100
// 10 < 100 -> subtract
// total = 1890
//
// C:
// current = 100, next = 5
// 100 > 5 -> add
// total = 1990
//
// I:
// current = 1, next = 5
// 1 < 5 -> subtract
// total = 1989
//
// V:
// Last character -> add 5
// total = 1994
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    inline int getRomanVal(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int n = s.length();
        int total = 0;

        for(int i = 0; i < n; i++) {
            int current_val = getRomanVal(s[i]);

            if(i + 1 < n && current_val < getRomanVal(s[i + 1])) {
                total -= current_val;
            }
            else {
                total += current_val;
            }
        }

        return total;
    }
};