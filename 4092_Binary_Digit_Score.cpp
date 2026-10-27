#include <iostream>

class Solution {
public:
    // Helper function to count the set bits
    int Score(int x){
        int cnt = 0;
        while(x > 0){
            if(x % 2 != 0){
                cnt++;
            }
            x /= 2;
        }
        return cnt;
    }

    // Main logic function to calculate the final score
    int calculateScore(int a, int b) {
        int s1 = Score(a);
        int s2 = Score(b);

        if(s1 >= s2){
            return s1 * s2;
        }
        return s2 / s1;
    }
};

int main() {
    // 1. Instantiate the Solution class
    Solution solver;

    // 2. Define test inputs
    // Example: 13 (binary: 1101 -> 3 bits), 7 (binary: 111 -> 3 bits)
    // s1 = 3, s2 = 3. Since s1 >= s2, result should be 3 * 3 = 9
    int a = 13;
    int b = 7;

    // 3. Call the class method and capture the output
    int result = solver.calculateScore(a, b);

    // 4. Print the output to the console
    std::cout << "The binary digit score for " << a << " and " << b << " is: " << result << std::endl;

    return 0;
}
