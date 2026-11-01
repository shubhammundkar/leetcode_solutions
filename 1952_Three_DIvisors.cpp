#include <iostream>

class Solution {
public:
    bool isThree(int n) {
        if(n < 4) return false;
        int cnt = 1;
        for(int i = 2; i <= n; i++){
            if(n % i == 0){
                cnt++;
            }
            if(cnt > 3){
                return false;
            }
        }
        return cnt == 3;
    }
};

int main() {
    Solution solver;
    
    // Testing the exact implementation
    int testCases[] = {4, 9, 12, 17};
    
    std::cout << std::boolalpha; 
    
    for (int n : testCases) {
        std::cout << "Input: " << n << " -> Exactly 3 divisors? " << solver.isThree(n) << std::endl;
    }
    
    return 0;
}
