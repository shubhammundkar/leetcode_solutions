// Compilation Commands (Run these in your terminal):
// g++ -std=c++11 Solution.cpp -o Solution
// ./Solution

#include <iostream>

using namespace std;

class Solution {
public:
    // Time Complexity: O(log3 n)
    // Space Complexity: O(1) -> Iterative approach avoids the O(log3 n) recursion stack frames
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

// Driver code to compile and run the solution locally
int main() {
    Solution solution;
    
    // Array of test cases to verify the code logic
    int testCases[] = {27, 0, 9, 45, 1};
    
    for (int n : testCases) {
        cout << "Is " << n << " a power of three? -> ";
        if (solution.isPowerOfThree(n)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }

    return 0;
}
