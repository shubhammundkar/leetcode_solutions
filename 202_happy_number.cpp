```cpp
// LeetCode 202 - Happy Number
// Topic: Math, Hashing
//
// Question:
// A happy number is a number where repeatedly replacing the number
// with the sum of the squares of its digits eventually reaches 1.
//
// If it reaches 1 -> happy number.
// If it enters a cycle -> not a happy number.
//
// Example:
// Input: n = 19
//
// 19 -> 1² + 9² = 82
// 82 -> 8² + 2² = 68
// 68 -> 6² + 8² = 100
// 100 -> 1² + 0² + 0² = 1
//
// Output: true
//
//
// Approach:
// Use an unordered_set called `seen` to store numbers we have already
// encountered.
//
// For every number:
// 1. Calculate the sum of squares of its digits.
// 2. Store the current number in `seen`.
// 3. Replace n with the calculated sum.
//
// If n becomes 1 -> happy number.
//
// If the same number appears again, a cycle has formed,
// so it is not a happy number.
//
//
// Important Line:
//
// while(n != 1 && seen.find(n) == seen.end())
//
// `seen.find(n) == seen.end()` means:
// n has NOT been seen before.
//
// If n has already been seen, the loop stops because we are
// repeating the same cycle.
//
//
// Example Walkthrough:
//
// n = 19
//
// 19 -> 1² + 9² = 82
// 82 -> 8² + 2² = 68
// 68 -> 6² + 8² = 100
// 100 -> 1² + 0² + 0² = 1
//
// n == 1
// return true
//
//
// For a non-happy number:
//
// Eventually, a number repeats:
//
// 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4
//
// Since 4 is already in `seen`, the loop stops.
//
// n != 1
// return false
//
//
// Time Complexity: O(log n) per digit-sum calculation
//
// Space Complexity: O(k)
// k = number of different values stored in the set
//
//
// Final Code:

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);

            int sum = 0;

            while(n != 0)
            {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }

            n = sum;
        }

        return n == 1;
    }
};
```
