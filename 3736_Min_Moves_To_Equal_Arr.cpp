#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int maxi = nums[0];
        //sort will take o(nlog(n)) while for loop will take o(n);
        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt += maxi - nums[i];
        }

        return cnt;
    }
};

int main() {
    // Instantiate the solution class
    Solution solver;

    // Test Case 1: Elements require increments to reach the maximum (5)
    vector<int> test1 = {1, 2, 5};
    int result1 = solver.minMoves(test1);
    cout << "Test Case 1 [1, 2, 5] -> Expected: 7, Got: " << result1 << endl;

    // Test Case 2: Elements are already equal
    vector<int> test2 = {3, 3, 3};
    int result2 = solver.minMoves(test2);
    cout << "Test Case 2 [3, 3, 3] -> Expected: 0, Got: " << result2 << endl;

    // Test Case 3: A larger gap array
    vector<int> test3 = {1, 10};
    int result3 = solver.minMoves(test3);
    cout << "Test Case 3 [1, 10]    -> Expected: 9, Got: " << result3 << endl;

    return 0;
}
