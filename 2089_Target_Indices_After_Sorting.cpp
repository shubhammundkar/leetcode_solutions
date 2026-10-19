/*
Compilation and Execution Commands:
===================================
To compile the program:
$ g++ -O3 solution.cpp -o solution

To run the program:
$ ./solution
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // We can do binary search for first and last occurrence but it wont help cause we already doing sort which takes o(nlogn) tc and then using binary search instead of a traversal loop will do o(Logn) instead of o(n) which wont help cause of that sorts o(nlogn).
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Sample test case setup
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    
    cout << "Input Array: ";
    for (int num : nums) cout << num << " ";
    cout << "\nTarget: " << target << "\n";
    
    // Call the function
    vector<int> result = solution.targetIndices(nums, target);
    
    // Display results
    cout << "Target Indices after sorting: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << "\n";
    
    return 0;
}
