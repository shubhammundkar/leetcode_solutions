// Compilation Commands (Run these in your terminal):
// g++ -std=c++11 Solution.cpp -o Solution
// ./Solution

#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

using namespace std;

class Solution {
public:
    // Time Complexity: O(n^2) approximate worst-case due to repeated reversals
    // Space Complexity: O(n) to store the result string
    // Note: Can be further optimized using a deque and direction flags to achieve O(n) time.
    string finalString(string s) {
        string res = "";
        for (char c : s) {
            if (c != 'i') { // If char is not 'i', simply append it
                res.push_back(c);
            }
            else { // If char is 'i', reverse the string formed so far
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};

// Driver code to compile and run the solution locally
int main() {
    Solution solution;
    
    // Test cases to verify the logic
    string test1 = "string";
    string test2 = "poiinter";
    
    cout << "Input: \"" << test1 << "\" -> Output: \"" << solution.finalString(test1) << "\"" << endl;
    cout << "Input: \"" << test2 << "\" -> Output: \"" << solution.finalString(test2) << "\"" << endl;

    return 0;
}
