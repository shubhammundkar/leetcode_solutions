#include <iostream>
#include <vector>
#include <cmath> // For abs()

using namespace std;

class Solution {
public:
    /*
     * Time Complexity (TC): O(N * M)
     * - N is the size of arr1, and M is the size of arr2.
     * - For each element in arr1 (outer loop runs N times), we potentially 
     *   iterate through every element in arr2 (inner loop runs M times).
     *
     * Space Complexity (SC): O(1)
     * - We are using a constant amount of extra space (only a couple of integer 
     *   variables like cnt, i, j, and the boolean isValid). No extra heap allocations.
     */
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        
        for (int i = 0; i < arr1.size(); i++) {
            bool isValid = true; // assume that diff is always greater than d;
            
            // when found at any iteration if diff is <= d then we make false;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false;
                    break; // will take out of this loop 
                }
            }
            if (isValid) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    int result = solver.findTheDistanceValue(arr1, arr2, d);

    // Expected Output: 2
    // Explanation: 
    // For 4: |4-10|=6, |4-9|=5, |4-1|=3, |4-8|=4 (All > 2) -> Valid (+1)
    // For 5: |5-10|=5, |5-9|=4, |5-1|=4, |5-8|=3 (All > 2) -> Valid (+1)
    // For 8: |8-8|=0 (Which is <= 2) -> Invalid
    cout << "Result: " << result << endl; 

    return 0;
}
