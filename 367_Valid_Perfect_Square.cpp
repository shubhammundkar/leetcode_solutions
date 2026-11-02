#include <iostream>

class Solution {
public:
    // Linear approach (i * i <= num): O(√N)
    // Mathematical odd subtraction approach: O(√N)
    // Binary Search approach (Below): O(log N)
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        if (num == 1) return true;

        long long right = num / 2;
        long long left = 1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            }
            else if (square < num) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution solver;
    
    // Test cases
    int test1 = 16;
    int test2 = 14;
    int test3 = 1;
    int test4 = 2147395600; // Large perfect square (46340 * 46340)

    std::cout << std::boolalpha; // Prints true/false instead of 1/0
    
    std::cout << "Is " << test1 << " a perfect square? " << solver.isPerfectSquare(test1) << "\n";
    std::cout << "Is " << test2 << " a perfect square? " << solver.isPerfectSquare(test2) << "\n";
    std::cout << "Is " << test3 << " a perfect square? " << solver.isPerfectSquare(test3) << "\n";
    std::cout << "Is " << test4 << " a perfect square? " << solver.isPerfectSquare(test4) << "\n";

    return 0;
}
