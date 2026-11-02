#include <iostream>
#include <vector>

using namespace std;

class Solution { // binary one is giving o(mlog(n))
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        int row = m - 1; // we start form bottom left corner 
        int col = 0;
        
        // tc -> o(m+n) at each step either row or col is eliminate 
        while(row >= 0 && col < n) {
            if(grid[row][col] < 0) {
                cnt += n - col; // all right to it inclu are neg ; 
                row--; // we check in the upper row now ; 
            }
            else {
                // if pos then everything above it in this column is also positive..
                // move right to look for neg elemengts so col++;
                col++; // wrost case if we dont find any neg in last row 
                // and we hit col as n and we cant further incre it so we stop and 
                // return cnt as 0 cause we know it is both col and row top to b decreasing order 
                // so if whole last row is pos all are pos ; 
            }
        }
        
        return cnt;
    }
};

int main() {
    // Create an instance of your Solution class
    Solution solver;

    // Example grid matching LeetCode's Example 1
    vector<vector<int>> grid = {
        { 4,  3,  2, -1},
        { 3,  2,  1, -1},
        { 1,  1, -1, -2},
        {-1, -1, -2, -3}
    };

    // Run the function and capture the output
    int result = solver.countNegatives(grid);

    // Print the output to the console
    cout << "Total number of negative elements: " << result << endl;

    return 0;
}
