// LeetCode 397: Integer Replacement
// Compilation Commands (Run these in your terminal):
// g++ -std=c++11 IntegerReplacement.cpp -o IntegerReplacement
// ./IntegerReplacement

#include <iostream>
#include <climits>   // For INT_MAX

using namespace std;

class Solution {
public:
    // Time Complexity: O(log n) - n is at least halved every two steps
    // Space Complexity: O(1)
    // Greedy rule for odd n, based on the last two bits:
    //   n % 4 == 1 -> n - 1  (result is a multiple of 4, can halve twice in a row)
    //   n % 4 == 3 -> n + 1  (same reason; clears a run of trailing 1-bits quickly)
    //   n == 3     -> n - 1  (special case: 3->2->1 is 2 steps, 3->4->2->1 is 3)
    int integerReplacement(int n) {
        int cnt = 0;
        long long temp = n;               // long long: n + 1 overflows int when n = INT_MAX
        while (temp != 1) {
            if (temp % 2 == 0) {          // even: only one choice
                temp = temp / 2;
            }
            else {
                if ((temp - 1) % 4 == 0 || temp == 3) {   // temp % 4 == 1, or special case 3
                    temp = temp - 1;
                }
                else {                    // temp % 4 == 3
                    temp = temp + 1;
                }
            }
            cnt++;                        // every branch is exactly one step
        }
        return cnt;
    }
};

// Driver code to compile and run the solution locally
int main() {
    Solution solution;

    // {input, expected output}
    int tests[][2] = {
        {1, 0}, {2, 1}, {3, 2}, {5, 3}, {7, 4}, {8, 3}, {9, 4}, {INT_MAX, 32}
    };

    for (auto &t : tests) {
        int got = solution.integerReplacement(t[0]);
        cout << "Input: " << t[0] << " -> Output: " << got
             << " (expected " << t[1] << ") "
             << (got == t[1] ? "PASS" : "FAIL") << endl;
    }

    return 0;
}