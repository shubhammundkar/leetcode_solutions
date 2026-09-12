// LeetCode 2094 - Finding 3-Digit Even Numbers
// Topic: Array, Set, Brute Force
//
// Question:
// You are given an array of digits where each digit may be used at most once.
// Return all possible 3-digit even numbers that can be formed using these digits.
//
// The following conditions must be satisfied:
// 1. The number must be a 3-digit number.
// 2. The first digit cannot be 0.
// 3. The last digit must be even.
// 4. Each index can be used only once.
// 5. The answer should contain unique numbers in increasing order.
//
// Example:
// Input: digits = [2,1,3,0]
//
// Output: [102,120,130,132,210,230,302,310,312,320]
//
// Explanation:
// We select three different positions from the array.
//
// Example:
// 1 0 2 -> 102
// 1 2 0 -> 120
// 1 3 0 -> 130
// 1 3 2 -> 132
// 2 1 0 -> 210
// 2 3 0 -> 230
// 3 0 2 -> 302
// 3 1 0 -> 310
// 3 1 2 -> 312
// 3 2 0 -> 320
//
// All these numbers:
// - have 3 digits
// - do not start with 0
// - end with an even digit
//
//
// Approach:
// We need to choose three different digits.
//
// We use three nested loops:
//
// i -> chooses the hundreds digit
// j -> chooses the tens digit
// k -> chooses the units digit
//
// First, check the hundreds digit.
//
// If digits[i] == 0, we skip it because a 3-digit number
// cannot start with 0.
//
// Then check j.
//
// If j == i, we skip it because the same array position
// cannot be used twice.
//
// Then check k.
//
// If k == i or k == j, we skip it because the same position
// cannot be reused.
//
// Finally, check whether digits[k] is even.
//
// An even number must end with an even digit.
//
// Therefore:
// digits[k] % 2 == 0
//
// If all conditions are satisfied, construct the number:
//
// digits[i] * 100 + digits[j] * 10 + digits[k]
//
// For example:
//
// digits[i] = 1
// digits[j] = 3
// digits[k] = 2
//
// Number:
// 1 * 100 + 3 * 10 + 2
// = 100 + 30 + 2
// = 132
//
// We store the number inside a set.
//
// Why use set?
//
// The input array can contain duplicate digits.
//
// Example:
// digits = [2,2,8]
//
// The same number may be generated more than once.
//
// set automatically removes duplicates.
//
// Also, set stores numbers in sorted order.
//
// Therefore, the final set already contains:
// - unique numbers
// - increasing order
//
//
// Example Walkthrough:
//
// digits = [2,1,3,0]
//
// i = 0
// digits[i] = 2
//
// 2 is not 0, so it can be the hundreds digit.
//
// j = 1
// digits[j] = 1
//
// k = 2
// digits[k] = 3
//
// 3 is odd, so skip.
//
// k = 3
// digits[k] = 0
//
// 0 is even.
//
// Number:
// 2 * 100 + 1 * 10 + 0
// = 210
//
// Insert 210 into set.
//
// Important Conditions:
//
// 1. First digit cannot be zero:
//
// if(digits[i] == 0)
//     continue;
//
// 2. Cannot reuse the same index:
//
// if(j == i)
//     continue;
//
// 3. k cannot use i or j:
//
// if(k == i || k == j)
//     continue;
//
// 4. Last digit must be even:
//
// if(digits[k] % 2 == 0)
//
// 5. Store unique numbers:
//
// set<int> unique_nums;
//
// Why are three loops needed?
//
// We are forming a 3-digit number:
//
//       Hundreds   Tens   Units
//           ↓       ↓      ↓
//          [ i ]   [ j ]  [ k ]
//
// i chooses the first digit.
// j chooses the second digit.
// k chooses the third digit.
//
// Therefore, three nested loops allow us to try every possible
// combination of three different positions.
//
// Time Complexity: O(n³ log m)
//
// There are three nested loops, so we check approximately:
// n * n * n = n³ combinations.
//
// Inserting into a set takes O(log m),
// where m is the number of unique numbers.
//
// Therefore:
// O(n³ log m)
//
// Since LeetCode 2094 has a very small input size,
// this brute-force approach is completely acceptable.
//
//
// Space Complexity: O(m)
//
// The set stores all unique 3-digit numbers.
//
// m = number of unique valid numbers.
//
//
//
// Final Code:

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> unique_nums;

        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] == 0)
                continue;

            for(int j = 0; j < digits.size(); j++)
            {
                if(j == i)
                    continue;

                for(int k = 0; k < digits.size(); k++)
                {
                    if(k == i || k == j)
                        continue;

                    if(digits[k] % 2 == 0)
                    {
                        int n = digits[i] * 100
                              + digits[j] * 10
                              + digits[k] * 1;

                        unique_nums.insert(n);
                    }
                }
            }
        }

        return vector<int>(unique_nums.begin(), unique_nums.end());
    }
};