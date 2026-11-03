#include <iostream>
#include <vector>

// Global variable to simulate the first bad version in our mock API
int GLOBAL_FIRST_BAD_VERSION = 0;

// Mock implementation of the API provided by LeetCode
bool isBadVersion(int version) {
    return version >= GLOBAL_FIRST_BAD_VERSION;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = 0;
        int left = 1;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                ans = mid;
                right = mid - 1; // finding first occurrence here
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

// Helper function to run and format test cases
void runTestCase(int testNum, int totalVersions, int actualFirstBad) {
    // Set the hidden bad version for the mock API
    GLOBAL_FIRST_BAD_VERSION = actualFirstBad;
    
    Solution solver;
    int result = solver.firstBadVersion(totalVersions);
    
    std::cout << "Test Case " << testNum << ":\n";
    std::cout << "  Total Versions (n): " << totalVersions << "\n";
    std::cout << "  Expected First Bad: " << actualFirstBad << "\n";
    std::cout << "  Result from Code  : " << result << "\n";
    
    if (result == actualFirstBad) {
        std::cout << "  Status            : PASSED ✅\n\n";
    } else {
        std::cout << "  Status            : FAILED ❌\n\n";
    }
}

int main() {
    std::cout << "--- Running First Bad Version Tests ---\n\n";
    
    // Test Case 1: Standard LeetCode example (n = 5, bad = 4)
    runTestCase(1, 5, 4);
    
    // Test Case 2: The very first version is bad (n = 3, bad = 1)
    runTestCase(2, 3, 1);
    
    // Test Case 3: The very last version is bad (n = 10, bad = 10)
    runTestCase(3, 10, 10);
    
    // Test Case 4: Larger range (n = 100, bad = 42)
    runTestCase(4, 100, 42);

    return 0;
}
