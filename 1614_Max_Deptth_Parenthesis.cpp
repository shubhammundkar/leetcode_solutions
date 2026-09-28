```cpp
// LeetCode 1614 - Maximum Nesting Depth of the Parentheses
// Topic: String, Stack
//
// Question:
// Given a valid parentheses string s, return its maximum nesting depth.
//
// Example:
// Input: s = "(1+(2*3)+((8)/4))+1"
//
// Output: 3
//
// Explanation:
// The deepest nested part is:
// ((8)/4)
//
// It has 3 opening parentheses active at the same time.
//
//
// Approach:
// We only need to keep track of how many '(' are currently open.
//
// When we see '(':
//     depth++
//
// When we see ')':
//     depth--
//
// At every step, update maxi.
//
// maxi stores the maximum depth reached.
//
//
// Example Walkthrough:
//
// s = "(1+(2*3)+((8)/4))+1"
//
// '(' -> depth = 1 -> maxi = 1
// '(' -> depth = 2 -> maxi = 2
// ')' -> depth = 1
// '(' -> depth = 2
// '(' -> depth = 3 -> maxi = 3
// ')' -> depth = 2
// ')' -> depth = 1
// ')' -> depth = 0
//
// Final answer = 3
//
//
// Important Idea:
//
// We don't actually need a stack here.
//
// We only need to know how many parentheses are currently open,
// so one variable `depth` is enough.
//
//
// Time Complexity: O(n)
//
// Space Complexity: O(1)
//
//
// Final Code:

class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int depth = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                depth++;
            }
            else if(c == ')')
            {
                depth--;
            }

            maxi = max(depth, maxi);
        }

        return maxi;
    }
};
```
