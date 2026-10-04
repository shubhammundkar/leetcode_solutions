#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Lower-bound binary search: find the first index with nums[i] >= target
        // Time: O(log n), Space: O(1)

        int left = 0, right = nums.size() - 1;

        // Default answer: if target is bigger than all elements, insert at the end
        int result = nums.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;  // safe from overflow

            if (nums[mid] >= target) {
                // mid is a valid candidate; look left for an even earlier one
                result = mid;
                right = mid - 1;
            } else {
                // nums[mid] is too small; answer lies to the right
                left = mid + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};

    cout << sol.searchInsert(nums, 5) << endl;  // expected 2
    cout << sol.searchInsert(nums, 2) << endl;  // expected 1
    cout << sol.searchInsert(nums, 7) << endl;  // expected 4
    cout << sol.searchInsert(nums, 0) << endl;  // expected 0

    return 0;
}