/*
====================================================================
LeetCode 921. Minimum Add to Make Parentheses Valid
Difficulty : Medium
Topics     : String, Stack, Greedy
Pattern    : Counter (no stack needed, only one bracket type)
Link       : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
Status     : Needed help. REDO on my own.
====================================================================

PROBLEM
-------
Given a string s of '(' and ')', in one move you can insert a
parenthesis at any position. Return the minimum number of moves
required to make s valid.

EXAMPLES
--------
"())"  -> 1   (add one '(' at the start)
"((("  -> 3   (add three ')' at the end)
"()"   -> 0
")("   -> 2   (add '(' before and ')' after)

====================================================================
IDEA
====================================================================
Go left to right. Each ')' either:
  - matches an earlier unmatched '('  -> they cancel, or
  - has nothing to match with         -> stuck, needs a '(' inserted.
Any '(' still unmatched at the end each need a ')' added.

Answer = unmatched '(' left at the end + stuck ')' counted on the way.

VARIABLES
---------
  open  = unmatched '(' so far
  close = unmatched ')' that had no '(' available before them

====================================================================
MY MISTAKE
====================================================================
I used ONE net counter ( '(' -> -1, ')' -> +1 ).
It fails on ")(" or "())(" because the stuck ')' and the leftover '('
cancel each other out and I got 0. Correct answer is 2.

LESSON: an early unmatched ')' can NOT be fixed by a later '('.
Count it the moment the balance would go below 0.

====================================================================
DRY RUN  s = "())("
====================================================================
  '('  -> open = 1, close = 0
  ')'  -> open > 0, so open-- -> open = 0
  ')'  -> open == 0, stuck, so close++ -> close = 1
  '('  -> open = 1
  answer = open + close = 1 + 1 = 2

====================================================================
COMPLEXITY
====================================================================
Time  : O(n)  -> single pass over the string
Space : O(1)  -> only two integers

====================================================================
RELATED PROBLEMS (same "balance can't go negative" idea)
====================================================================
  1541. Minimum Insertions to Balance a Parentheses String
  678.  Valid Parenthesis String
  32.   Longest Valid Parentheses
  1021. Remove Outermost Parentheses (depth counter)
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;    // unmatched '(' so far
        int close = 0;   // unmatched ')' that needed a '(' inserted

        for (char c : s) {
            if (c == '(') {
                open++;
            } else {  // c == ')'
                if (open > 0) {
                    open--;     // matches an earlier '('
                } else {
                    close++;    // nothing to match, must insert a '('
                }
            }
        }
        return open + close;    // leftover '(' need ')' + inserted '('
    }
};

// ---------------------------------------------------------------
// Local testing (not needed on LeetCode)
// ---------------------------------------------------------------
int main() {
    Solution sol;

    string tests[] = { "())", "(((", "()", ")(", "())(" };
    int expected[] = { 1, 3, 0, 2, 2 };

    for (int i = 0; i < 5; i++) {
        int got = sol.minAddToMakeValid(tests[i]);
        cout << "\"" << tests[i] << "\" -> " << got
             << (got == expected[i] ? "  OK" : "  WRONG") << "\n";
    }
    return 0;
}