// LeetCode 3483 - Unique 3-Digit Even Numbers
// Topic: Array, Hash Set, Brute Force
//
// Question:
// You are given an array of digits.
//
// Form every possible 3-digit even number using three different
// elements from the array.
//
// The number:
// 1. Cannot have 0 as its first digit.
// 2. Must be even.
// 3. Cannot reuse the same array element more than once.
//
// Return the number of unique 3-digit even numbers that can be formed.
//
// Example:
// Input: digits = [2,1,3,0]
//
// Output: 2
//
// Explanation:
// The possible 3-digit even numbers are:
// 102
// 120
// 130
// 132
// 210
// 230
// 302
// 310
// 312
// 320
//
// After considering the available digits and uniqueness,
// the answer is the number of distinct valid numbers.
//
//
// Approach:
// We use three nested loops.
//
// i -> chooses the hundreds digit
// j -> chooses the tens digit
// k -> chooses the units digit
//
// The hundreds digit cannot be 0 because then the number would
// not be a 3-digit number.
//
// The same index cannot be used twice, so:
// i != j
// i != k
// j != k
//
// The units digit must be even, so:
// digits[k] % 2 == 0
//
// We then construct the number:
// number = hundreds * 100 + tens * 10 + units
//
// We store every valid number in an unordered_set.
// This automatically removes duplicate numbers when the input
// contains repeated digits.
//
// Finally, the size of the set gives the number of unique numbers.
//
// Example Walkthrough:
//
// digits = [1, 2, 3, 4]
//
// Choose:
// i = 0 -> hundreds = 1
// j = 1 -> tens = 2
// k = 3 -> units = 4
//
// number = 1 * 100 + 2 * 10 + 4
//        = 124
//
// 124 is even, so we insert it into the set.
//
// Another combination:
// i = 0, j = 2, k = 3
//
// number = 134
//
// 134 is also even, so it is inserted.
//
// If the same number is formed again because of duplicate digits,
// unordered_set keeps only one copy.
//
// Time Complexity: O(n^3)
// Space Complexity: O(n^3) in the worst case

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> nums;

        int len = digits.size();

        if (len < 3)
            return 0;

        for (int i = 0; i < len; i++)
        {
            // First digit cannot be 0
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < len; j++)
            {
                // Cannot reuse the same index
                if (j == i)
                    continue;

                for (int k = 0; k < len; k++)
                {
                    // Cannot reuse the same index
                    if (k == i || k == j)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 == 0)
                    {
                        int n = digits[i] * 100
                              + digits[j] * 10
                              + digits[k];

                        nums.insert(n);
                    }
                }
            }
        }

        return nums.size();
    }
};