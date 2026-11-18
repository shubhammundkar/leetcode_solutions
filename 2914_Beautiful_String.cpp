#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * Time Complexity (TC): O(n)
     * - The loop iterates through the string in steps of 2 (n / 2 iterations).
     * - Each comparison takes O(1) constant time.
     *
     * Space Complexity (SC): O(1)
     * - Only one extra integer variable 'cnt' is used, requiring constant auxiliary space.
     */
    int minChanges(string s) {
        int cnt = 0; // Stores the minimum number of character flips needed
        
        // Check adjacent pairs of characters: (0,1), (2,3), (4,5), etc.
        // Using (i + 1 < s.size()) prevents unsigned integer underflow if 's' is empty
        for (int i = 0; i + 1 < s.size(); i += 2) {
            // If the pair does not match, one character must be flipped
            if (s[i] != s[i + 1]) {
                cnt++;
            }
        }
        
        return cnt;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;
    
    // Sample test cases
    string test1 = "1001";
    string test2 = "10";
    string test3 = "0000";
    
    // Run and print results
    cout << "Input: " << test1 << " -> Min Changes: " << sol.minChanges(test1) << endl; // Expected: 2
    cout << "Input: " << test2 << " -> Min Changes: " << sol.minChanges(test2) << endl; // Expected: 1
    cout << "Input: " << test3 << " -> Min Changes: " << sol.minChanges(test3) << endl; // Expected: 0
    
    return 0;
}
