```cpp
// LeetCode 20 - Valid Parentheses
// Topic: Stack, String
//
// Question:
// Given a string containing '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
//
// A string is valid if:
// 1. Every opening bracket has a matching closing bracket.
// 2. Brackets close in the correct order.
//
// Example:
// Input: s = "({[]})"
//
// Output: true
//
// Explanation:
// Every opening bracket is closed by the correct bracket
// in the reverse order in which it was opened.
//
//
// Approach:
// Use a stack.
//
// If we see an opening bracket:
//     push it into the stack.
//
// If we see a closing bracket:
//     check the top of the stack.
//
// The top represents the most recent opening bracket.
//
// If it matches the closing bracket:
//     pop it.
//
// If it does not match:
//     return false.
//
// At the end, the stack must be empty.
//
//
// Example Walkthrough:
//
// s = "({[]})"
//
// '(' -> push
// '{' -> push
// '[' -> push
//
// ')' -> top is '[' -> mismatch -> would be false
//
// So this example would actually be invalid.
//
// Example of valid string:
//
// s = "({[]})"
// 
// Correct matching order should be:
// '(' -> '{' -> '[' -> ']' -> '}' -> ')'
//
//
// Important Idea:
//
// Stack follows LIFO:
//
// Last In -> First Out
//
// This is exactly what brackets need because the
// most recently opened bracket must be closed first.
//
//
// Important Checks:
//
// if(st.empty())
//     return false;
//
// No opening bracket is available to match the closing bracket.
//
//
// if(c == ')' && top != '(')
//     return false;
//
// Same idea for ']' and '}'
//
//
// At the end:
//
// return st.empty();
//
// If anything is left in the stack, some opening bracket
// was never closed.
//
//
// Time Complexity: O(n)
//
// Space Complexity: O(n)
//
//
// Final Code:

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if(st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if(c == ')' && top != '(')
                    return false;

                if(c == ']' && top != '[')
                    return false;

                if(c == '}' && top != '{')
                    return false;
            }
        }

        return st.empty();
    }
};
```
