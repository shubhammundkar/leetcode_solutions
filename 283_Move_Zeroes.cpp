// Compilation Commands (Run these in your terminal):
// g++ -std=c++11 Solution.cpp -o Solution
// ./Solution

#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 1;
        
        while (right < nums.size()) {
            if (nums[left] == 0) {
                if (nums[right] != 0) {
                    // If nums[right] != 0, swap and move both pointers
                    swap(nums[left], nums[right]);
                    left++;
                    right++;
                }
                else {
                    // nums[right] == 0, only move the right pointer
                    right++;
                }
            }
            else {
                // If nums[left] != 0, move both pointers forward
                left++;
                right++;
            }
        }
    }
};

// Driver code to compile and run the solution locally
int main() {
    Solution solution;
    
    // Test case
    vector<int> nums = {0, 1, 0, 3, 12};
    
    cout << "Original Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    // Call the function to move zeroes to the end
    solution.moveZeroes(nums);

    cout << "Modified Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
