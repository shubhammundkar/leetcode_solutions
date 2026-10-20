#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Time Complexity: O(n) - where n is the number of rows/columns
    // Space Complexity: O(1) - constant extra space used
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        
        for (int i = 0; i < mat.size(); i++) {
            sum += mat[i][i];       // Primary diagonal
            sum += mat[i][n - i - 1]; // Secondary diagonal        
        }
        
        // If the matrix size is odd, the middle element was added twice
        if (n % 2 != 0) {
            sum -= mat[n / 2][n / 2];
        }
        
        return sum;
    }
};

int main() {
    // Test Case: 3x3 Odd-sized Matrix
    // The middle element is 5, which shouldn't be counted twice.
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution solver;
    int totalSum = solver.diagonalSum(mat);

    // Expected calculation: (1 + 5 + 9) + (3 + 5 + 7) - 5 = 25
    cout << "Total Diagonal Sum: " << totalSum << endl;

    return 0;
}
