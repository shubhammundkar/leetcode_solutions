#include <iostream>

class Solution {
public:
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
    bool isPowerOfTwo(int n) {
        while(n > 1 && n % 2 == 0){
            n = n / 2;
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    int test1 = 16;
    int test2 = 5;
    int test3 = 0;
    int test4 = -8;
    
    // std::boolalpha forces the console to output "true" or "false" instead of 1 or 0
    std::cout << std::boolalpha;
    std::cout << "Is " << test1 << " a power of two? " << solution.isPowerOfTwo(test1) << "\n";
    std::cout << "Is " << test2 << " a power of two? " << solution.isPowerOfTwo(test2) << "\n";
    std::cout << "Is " << test3 << " a power of two? " << solution.isPowerOfTwo(test3) << "\n";
    std::cout << "Is " << test4 << " a power of two? " << solution.isPowerOfTwo(test4) << "\n";
    
    return 0;
}
