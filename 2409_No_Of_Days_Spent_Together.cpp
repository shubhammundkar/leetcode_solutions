#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int toDays(string& d) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = (d[0] - '0') * 10 + (d[1] - '0');
        int day = (d[3] - '0') * 10 + (d[4] - '0');
        
        int totalDays = 0;
        for (int i = 0; i < month - 1; i++) {
            totalDays += days[i];
        }
        return totalDays + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(toDays(arriveAlice), toDays(arriveBob));
        int end = min(toDays(leaveAlice), toDays(leaveBob));
        return max(0, end - start + 1);
    }
};

int main() {
    Solution solver;

    // Test Case 1: Alice and Bob have overlapping days
    string arriveAlice1 = "08-15", leaveAlice1 = "08-18";
    string arriveBob1   = "08-16", leaveBob1   = "08-19";
    int result1 = solver.countDaysTogether(arriveAlice1, leaveAlice1, arriveBob1, leaveBob1);
    cout << "Test Case 1 Days Together: " << result1 << " (Expected: 3)" << endl;

    // Test Case 2: No overlap at all
    string arriveAlice2 = "10-01", leaveAlice2 = "10-31";
    string arriveBob2   = "11-01", leaveBob2   = "12-31";
    int result2 = solver.countDaysTogether(arriveAlice2, leaveAlice2, arriveBob2, leaveBob2);
    cout << "Test Case 2 Days Together: " << result2 << " (Expected: 0)" << endl;

    return 0;
}
