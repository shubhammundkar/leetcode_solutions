#include <iostream>
#include <string>
#include <algorithm>

// Bring in the standard namespace so we don't have to write std:: everywhere
using namespace std;

class Solution {
public:
    string toHex(int num) {
        // Base case
        if (num == 0) return "0";
        
        // Cast to unsigned int to correctly handle two's complement for negatives
        unsigned int n = num; 
        
        string hexChars = "0123456789abcdef";
        string result = "";
        
        // Loop runs until all bits are processed
        while (n > 0) {
            // 1. Extract the last 4 bits using bitwise AND with 15 (0xF)
            int remainder = n & 15; 
            
            // 2. Map the 4-bit value to its hexadecimal character
            result += hexChars[remainder]; 
            
            // 3. Right shift by 4 bits to process the next hex digit
            n >>= 4; 
        }
        
        // Since we processed from right to left, we need to reverse the string
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Positive Number
    int test1 = 26;
    cout << "Decimal: " << test1 << " -> Hex: " << solver.toHex(test1) << endl;

    // Test Case 2: Negative Number (Handles two's complement automatically)
    int test2 = -1;
    cout << "Decimal: " << test2 << " -> Hex: " << solver.toHex(test2) << endl;

    // Test Case 3: Zero Edge Case
    int test3 = 0;
    cout << "Decimal: " << test3 << " -> Hex: " << solver.toHex(test3) << endl;

    return 0;
}
