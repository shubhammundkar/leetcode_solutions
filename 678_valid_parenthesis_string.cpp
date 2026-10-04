/*
====================================================================
LeetCode 678. Valid Parenthesis String
Difficulty : Medium
Topics     : String, Greedy, Dynamic Programming, Stack
Pattern    : Greedy range [lo, hi] of possible unmatched '('
Link       : https://leetcode.com/problems/valid-parenthesis-string/
Status     : Couldn't solve alone (tried counters). REDO on my own.
====================================================================

PROBLEM
-------
s contains '(', ')' and '*'. '*' can be treated as '(' , ')' or an
empty string. Return true if s can be made valid.

EXAMPLES
--------
"()"      -> true
"(*)"     -> true   ('*' as empty)
"(*))"    -> true   ('*' as '(')
"(*"      -> true   ('*' as ')')
")*("     -> false  (first ')' has nothing before it)

====================================================================
IDEA
====================================================================
Because '*' has 3 choices, the number of unmatched '(' is not one
number any more, it is a RANGE. Track:

  lo = fewest unmatched '(' possible  (use '*' as ')' when it helps)
  hi = most  unmatched '(' possible   (use '*' as '(')

  char | lo  | hi
  '('  | +1  | +1
  ')'  | -1  | -1
  '*'  | -1  | +1

After each character:
  1. hi < 0   -> return false.
                 Even with every '*' as '(', there are too many ')'.
                 (Catches ")*(" where order matters.)
  2. lo < 0   -> reset lo = 0.
                 A negative count is meaningless, we just don't use
                 that '*' as ')'.

At the end: return lo == 0
(there is some way to pick the stars so everything matches).

====================================================================
MY MISTAKE
====================================================================
My code:
    if (c=='*') star++;
    if (c=='(') open++;
    else { ... treat as ')' ... }

Bug 1: '*' also fell into the else branch (missing "else if").
Bug 2: abs(open - close) == star is wrong because
         - ORDER matters: ")*(" must be false but it said true.
         - stars can be EMPTY, so I don't need to use all of them.
           Condition should be "enough stars", not "exactly equal".
LESSON: when a symbol has multiple meanings, track a RANGE of
possible states instead of one number.

====================================================================
DRY RUN  s = "(*)"
====================================================================
  '('  -> lo=1,  hi=1
  '*'  -> lo=0,  hi=2
  ')'  -> lo=-1 -> reset to 0, hi=1
  end  -> lo == 0 -> true

DRY RUN  s = ")*("
  ')'  -> hi = -1 < 0 -> return false immediately

====================================================================
COMPLEXITY
====================================================================
Time  : O(n)  -> single pass
Space : O(1)  -> two integers

====================================================================
RELATED PROBLEMS
====================================================================
  921.  Minimum Add to Make Parentheses Valid  (counter idea)
  2116. Check if a Parentheses String Can Be Valid (similar range idea)
  1541. Minimum Insertions to Balance a Parentheses String
  32.   Longest Valid Parentheses
====================================================================
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0;   // min possible unmatched '('
        int hi = 0;   // max possible unmatched '('

        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else {  // c == '*'
                lo--;   // '*' as ')'
                hi++;   // '*' as '('
            }

            if (hi < 0) return false;   // too many ')' even in best case
            lo = max(lo, 0);            // can't have negative unmatched '('
        }
        return lo == 0;
    }
};

// ---------------------------------------------------------------
// Local testing (not needed on LeetCode)
// ---------------------------------------------------------------
int main() {
    Solution sol;

    string tests[] = { "()", "(*)", "(*))", "(*", ")*(", "((*)", "*(" };
    bool expected[] = { true, true, true, true, false, true, false };

    for (int i = 0; i < 7; i++) {
        bool got = sol.checkValidString(tests[i]);
        cout << "\"" << tests[i] << "\" -> " << boolalpha << got
             << (got == expected[i] ? "  OK" : "  WRONG") << "\n";
    }
    return 0;
}