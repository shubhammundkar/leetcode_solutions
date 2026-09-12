/*
    LeetCode 2485 - Find the Pivot Integer

    Problem:
    Given a positive integer n, find the pivot integer x such that:

        1 + 2 + 3 + ... + x = x + (x+1) + ... + n

    If no such integer exists, return -1.

    --------------------------------------------------

    Approach:

    Total sum of numbers from 1 to n is:

        sum = n * (n + 1) / 2

    If x is the pivot integer, then:

        1 + 2 + ... + x = x + (x+1) + ... + n

    Notice that the right side contains the total sum minus
    the sum before x.

    This simplifies to:

        x² = total sum

    Therefore, we only need to check whether the total sum
    is a perfect square.

    If sum is a perfect square:
        x = sqrt(sum)

    Otherwise:
        return -1.

    --------------------------------------------------

    Example:

    n = 8

    Total sum:
        1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36

    sqrt(36) = 6

    Check:

        1 + 2 + 3 + 4 + 5 + 6 = 21

        6 + 7 + 8 = 21

    Therefore, pivot integer = 6.

    --------------------------------------------------

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;

        int x = sqrt(sum);

        if (x * x == sum) {
            return x;
        }

        return -1;
    }
};