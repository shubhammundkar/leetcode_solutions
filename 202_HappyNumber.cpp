#include <iostream>
using namespace std;

/*
 * Problem: Happy Number (LeetCode 202)
 *
 * Approach: Floyd's Cycle Detection (Tortoise and Hare)
 *   1. getNext(n) gives the sum of the squares of the digits of n.
 *   2. Repeating getNext on a number either reaches 1 (happy)
 *      or falls into a cycle that never contains 1 (not happy).
 *   3. Treat the sequence like a linked list: each number "points" to getNext(number).
 *   4. Use two pointers:
 *        tortoise -> moves 1 step  (one getNext call)
 *        hare     -> moves 2 steps (two getNext calls)
 *   5. Stop when:
 *        hare == 1         -> reached 1, happy
 *        tortoise == hare  -> met inside a cycle without 1, not happy
 *   6. Return hare == 1 to tell which exit happened.
 *
 * Time Complexity:  O(log n)
 *   - getNext takes O(log n) because it loops over the digits of n (about log10(n) digits).
 *   - After the first step, the value drops to a small number (at most 243 for a 32-bit int),
 *     so the sequence length before reaching 1 or a cycle is bounded by a small constant.
 *
 * Space Complexity: O(1)
 *   - Only a few integer variables (tortoise, hare, sum, digit).
 *   - No set/hash map needed to remember visited numbers.
 *
 * Alternative: HashSet approach is O(log n) time but O(log n) space (stores visited numbers).
 */

class Solution {
private:
    // Returns the sum of the squares of the digits of n
    // e.g. 82 -> 8*8 + 2*2 = 68
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;     // take the last digit
            sum += digit * digit;   // add its square
            n = n / 10;             // drop the last digit
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int tortoise = n;            // slow pointer: moves 1 step at a time
        int hare = getNext(n);       // fast pointer: starts 1 step ahead, moves 2 steps at a time

        // Stop when either:
        //  1) hare == 1          -> reached 1, number is happy
        //  2) tortoise == hare   -> met inside a cycle that doesn't include 1, not happy
        while (hare != 1 && tortoise != hare) {
            tortoise = getNext(tortoise);          // 1 step
            hare = getNext(getNext(hare));         // 2 steps
        }

        // true only if we exited because we found 1
        return hare == 1;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;  // print true/false instead of 1/0

    cout << sol.isHappy(19) << endl;  // expected true
    cout << sol.isHappy(2)  << endl;  // expected false
    cout << sol.isHappy(1)  << endl;  // expected true
    cout << sol.isHappy(7)  << endl;  // expected true

    return 0;
}