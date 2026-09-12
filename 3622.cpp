// Problem Summary: LeetCode 3622
// The problem asks you to check if a given positive integer n can be perfectly divided by a special number called lar_sum.This special number is calculated by finding two things from n:The Sum of its digitsThe Product of its digits
// You add these two values together to get lar_sum. If n leaves a remainder of 0 when divided by lar_sum, return true. Otherwise, return false.
// Example Walkthrough (n = 12)
// Digits: 1 and 2
// Sum: \(1 + 2 = 3\)
// Product: \(1 \times 2 = 2\)
// Special Number (lar_sum): \(3 + 2 = 5\)
// Check: Is 12 divisible by 5? No (\(12 \pmod 5 \neq 0\)). Return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int original_num = n;
        
        while (original_num > 0) {
            int digit = original_num % 10;
            sum += digit;
            product *= digit;
            original_num /= 10;
        }
        
        return (n % (sum + product) == 0);
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    int test1 = 12;
    cout << "Test 12: " << (solver.checkDivisibility(test1) ? "True" : "False") << " (Expected: False)\n";
    
    // Test Case 2 (e.g., if a number works, like 1 or specific numbers)
    int test2 = 10; // Sum = 1, Prod = 0 -> lar_sum = 1 -> 10 % 1 == 0
    cout << "Test 10: " << (solver.checkDivisibility(test2) ? "True" : "False") << " (Expected: True)\n";

    return 0;
}
