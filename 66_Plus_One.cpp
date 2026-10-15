// LeetCode 66: Plus One
// Compile: g++ -std=c++17 plus_one.cpp -o plus_one && ./plus_one

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // ---------------------------------------------------------------
    // APPROACH 1: RECURSIVE
    // ---------------------------------------------------------------
    // Idea: start from the last digit.
    //   - digit < 9  -> just increment it, done (no carry).
    //   - digit == 9 -> set it to 0 and carry 1 to the previous digit (recurse).
    //   - ran past index 0 (size < 0) -> every digit was 9 (e.g. 999),
    //     so insert a leading 1 (-> 1000).
    //
    // Time : O(n) worst case (all 9s)
    // Space: O(k) recursion stack, k = number of trailing 9s (+1 frame).
    //        e.g. 19999 -> 5 frames (4 nines + 1). Worst case O(n).
    //        Insert at front on all-9s also shifts n elements: O(n).
    void fxn(vector<int>& digits, int size) {
        // Base case: carry fell off the front, e.g. 99 -> 00 -> need leading 1
        if (size < 0) {
            digits.insert(digits.begin(), 1); // shifts everything right by 1
            return;
        }

        // No carry needed: increment and stop
        if (digits[size] < 9) {
            digits[size]++;
            return;
        }

        // digit is 9: becomes 0, carry moves to the previous digit
        digits[size] = 0;
        fxn(digits, size - 1);
    }

    vector<int> plusOneRecursive(vector<int> digits) { // by value: keeps the original intact
        fxn(digits, (int)digits.size() - 1);
        return digits;
    }

    // ---------------------------------------------------------------
    // APPROACH 2: ITERATIVE
    // ---------------------------------------------------------------
    // Same logic, but a loop instead of recursion.
    //
    // Time : O(n)
    // Space: O(1) auxiliary (no stack frames). In the all-9s case we still
    //        need room for n+1 digits, but that's the output itself.
    vector<int> plusOneIterative(vector<int> digits) {
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {   // no carry: increment and finish
                digits[i]++;
                return digits;
            }
            digits[i] = 0;         // 9 -> 0, keep carrying left
        }
        // Loop finished => all digits were 9 (now all 0). Add the leading 1.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Helper to print a vector like [1, 2, 3]
void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1, 2, 3},        // -> [1,2,4]       (simple, no carry)
        {1, 9, 9, 9, 9},  // -> [2,0,0,0,0]   (4 trailing 9s, 5 stack frames)
        {9, 9, 9},        // -> [1,0,0,0]     (all 9s, new digit added)
        {9},              // -> [1,0]         (single 9)
        {0},              // -> [1]           (zero)
        {4, 3, 2, 9}      // -> [4,3,3,0]     (one carry)
    };

    for (auto& t : tests) {
        cout << "Input     : "; printVec(t); cout << "\n";
        cout << "Recursive : "; printVec(sol.plusOneRecursive(t)); cout << "\n";
        cout << "Iterative : "; printVec(sol.plusOneIterative(t)); cout << "\n\n";
    }

    return 0;
}