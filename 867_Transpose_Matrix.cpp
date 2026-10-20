#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // tc -> O(m*n), sc -> O(m*n)
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};

// The int main() function allows the code to execute locally
int main() {
    // 1. Create a sample rectangular matrix (2 rows x 3 columns)
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 2. Instantiate your Solution class object
    Solution solver;
    
    // 3. Call the transpose function
    vector<vector<int>> result = solver.transpose(matrix);

    // 4. Print the transposed result matrix
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl; // Move to the next row
    }

    return 0; // Signals successful program completion
}
// g++ -O3 main.cpp -o main
// ./main