// LeetCode - Count Commas in Numbers
//
// Approach:
// A comma first appears when numbers reach 1,000.
// Every number from 1,000 to n contains exactly one comma
// (for the given constraint).
//
// Count of such numbers:
//     n - 1000 + 1
//   = n - 999
//
// Example:
// n = 1005
//
// Numbers containing a comma:
// 1000, 1001, 1002, 1003, 1004, 1005
//
// Count = 6
//
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;

        return n - 999;
    }
};