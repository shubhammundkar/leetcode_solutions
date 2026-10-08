// LeetCode 292 - Nim Game
// Topic: Game Theory / Mathematical Pattern
//
// We can take 1, 2, or 3 stones.
// Losing positions: 4, 8, 12, 16...
//
// Why?
// If n is a multiple of 4, whatever we take,
// opponent can take the remaining stones and win.
//
// So:
// n % 4 == 0 → Lose
// n % 4 != 0 → Win
//
// Time: O(1)
// Space: O(1)

class Solution {
public:// optimally means opp is also smart enough to win ... 
    bool canWinNim(int n) {
        //if n is a multiple of 4 then whatever we take opp always wins for 4 we take 1 he take 3 we take 2 he take 2 we take 3 he take 1 
        //for n as non multiple of 4 we can take 1 2 or 3 and leave multile of 4 for opp so we can win 
        return n%4!=0;
    }
};
// losing position are 4 8 12 16 ... 
