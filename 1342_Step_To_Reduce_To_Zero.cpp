#include <iostream>

class Solution {
public:
    int numberOfSteps(int n) {
        int step = 0;
        while (n > 0) {
            if (n % 2 == 0) {
                n = n / 2;
                step++;
            } else {
                n = n - 1;
                step++;
            }
        }
        return step;
    }
};

int main() {
    // Instantiate the Solution class
    Solution solver;

    // Test input
    int input_number = 14; 
    
    // Call the function and store the result
    int result = solver.numberOfSteps(input_number);

    // Print the output to the console
    std::cout << "Steps required for " << input_number << " to reach 0: " << result << std::endl;

    return 0;
}
