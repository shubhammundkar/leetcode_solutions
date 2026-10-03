/*
==============================================================================
 LeetCode 22 - Generate Parentheses            (Medium)  | Backtracking
==============================================================================

PROBLEM
    Given n pairs of parentheses, generate all combinations of
    well-formed (valid) parentheses.

    Example:  n = 3
    Output:   ["((()))","(()())","(())()","()(())","()()()"]

------------------------------------------------------------------------------
 APPROACH: Backtracking (build the string one char at a time)
------------------------------------------------------------------------------
    Track two counters:  open_cnt  = '(' used so far
                         close_cnt = ')' used so far

    Two rules guarantee the string is always valid:
      1. Add '(' only if  open_cnt  < n        (can't use more than n opens)
      2. Add ')' only if  close_cnt < open_cnt (never close what isn't open)

    Base case: s.length() == 2*n  -> push to result.

    Pattern: CHOOSE -> EXPLORE -> UN-CHOOSE (push_back, recurse, pop_back)

    Why no invalid strings are ever built?
      Rule 2 ensures that at every prefix, #')' <= #'(' , which is exactly
      the condition for a valid prefix. So we never need to "validate" later.

------------------------------------------------------------------------------
 DRY RUN (n = 2)
------------------------------------------------------------------------------
                       ""
                       |
                      "("            (open=1, close=0)
                     /    \
                "(("        "()"
                  |           |
               "(()"        "()("
                  |           |
               "(())"       "()()"
              (add)         (add)

    Result = ["(())", "()()"]

------------------------------------------------------------------------------
 COMPLEXITY
------------------------------------------------------------------------------
    Time  : O(4^n / sqrt(n))  ~  O(Cn * n)
            Number of valid answers = n-th Catalan number Cn = 4^n / (n^1.5)
            Each answer is a string of length 2n, copied into result -> * n

    Space : O(n)  auxiliary  (recursion depth = 2n, plus the string s)
            O(Cn * n) if you count the output itself.

------------------------------------------------------------------------------
 KEY TAKEAWAYS / NOTES TO SELF
------------------------------------------------------------------------------
    - Pass string by reference (&s) -> avoids copying at every call,
      that's why we need the pop_back() to undo the change.
    - Alternative: pass string by value (no pop_back needed) but slower
      because of copies on each call.
    - Don't generate all 2^(2n) strings and filter -> wasteful.
      Pruning with the two rules is what makes this efficient.
    - Count of answers for n = 1,2,3,4,5 : 1, 2, 5, 14, 42  (Catalan)

------------------------------------------------------------------------------
 SIMILAR PROBLEMS (same backtracking template)
------------------------------------------------------------------------------
    - 17. Letter Combinations of a Phone Number
    - 46. Permutations
    - 78. Subsets
    - 39. Combination Sum
    - 20. Valid Parentheses            (validation, stack based)
    - 301. Remove Invalid Parentheses  (harder variant)

==============================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(string &s, int open_cnt, int close_cnt, int n,
                   vector<string> &result) {
        // Base case: n pairs -> length 2*n (e.g. n=3 -> 6 chars)
        if (s.length() == 2 * n) {
            result.push_back(s);
            return;
        }

        // Choice 1: add '(' if we still have opens left
        if (open_cnt < n) {
            s.push_back('(');                              // choose
            backtrack(s, open_cnt + 1, close_cnt, n, result); // explore
            s.pop_back();                                  // un-choose
        }

        // Choice 2: add ')' only if it matches an unclosed '('
        if (close_cnt < open_cnt) {
            s.push_back(')');
            backtrack(s, open_cnt, close_cnt + 1, n, result);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        backtrack(s, 0, 0, n, result);
        return result;
    }
};

// ---------------------- Local test (remove on LeetCode) ----------------------
int main() {
    Solution sol;
    for (int n = 1; n <= 3; n++) {
        vector<string> ans = sol.generateParenthesis(n);
        cout << "n = " << n << "  (" << ans.size() << " results)\n";
        for (auto &str : ans) cout << "  " << str << "\n";
    }
    return 0;
}