#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Check if left character is NOT a letter
            if (!((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z'))) {
                left++;
            }
            // Check if right character is NOT a letter
            else if (!((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))) {
                right--;
            }
            // Both are letters, so swap them
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Simple string with symbols
    string test1 = "ab-cd";
    cout << "Input:  " << test1 << "\n";
    cout << "Output: " << solver.reverseOnlyLetters(test1) << "\n\n"; // Expected: "dc-ba"

    // Test Case 2: Mixed case and multiple symbols
    string test2 = "a-bC-dEf-ghIj";
    cout << "Input:  " << test2 << "\n";
    cout << "Output: " << solver.reverseOnlyLetters(test2) << "\n\n"; // Expected: "j-Ih-gfE-dCba"

    // Test Case 3: Symbols at the edges
    string test3 = "Test1ng-Leet=code-Q!";
    cout << "Input:  " << test3 << "\n";
    cout << "Output: " << solver.reverseOnlyLetters(test3) << "\n";    // Expected: "Qedo1ct-eeL=gntS-T!"

    return 0;
}
