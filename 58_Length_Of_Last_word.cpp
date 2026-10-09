# LeetCode 58 – Length of Last Word

**Topic:** String, Two Pointers, Traversal

## Question
Given a string `s` consisting of words and spaces, return the length of the last word.

A word is a maximal substring consisting of non-space characters only.

**Example:**
```text
Input:  s = " Hello World   "
Output: 5

Explanation: The last word is "World", whose length is 5.
```

## Approach Used
**Reverse Traversal using Two While Loops**

Instead of traversing the entire string from the beginning, start from the last index and move backward.

1. Initialize `right = s.size() - 1` and `cnt = 0`.
2. **First while loop:** Skip all trailing spaces.
3. **Second while loop:** Count characters until a space or the beginning of the string is reached.
4. Return `cnt`.

## Algorithm
```text
1. right = last index of string
2. cnt = 0

3. While right >= 0 AND s[right] == ' ':
       right--

4. While right >= 0 AND s[right] != ' ':
       right--
       cnt++

5. Return cnt
```

## Code
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1;
        int cnt = 0;

        // Skip trailing spaces
        while (right >= 0 && s[right] == ' ') {
            right--;
        }

        // Count characters of the last word
        while (right >= 0 && s[right] != ' ') {
            right--;
            cnt++;
        }

        return cnt;
    }
};
```

## Dry Run

Input: `s = " Hello World   "`

**Step 1: Skip trailing spaces**

The pointer moves backward over the three spaces at the end until it reaches `'d'`.

**Step 2: Count the last word**

| Character | `right` moves backward | `cnt` |
|---|---|---:|
| `d` | Yes | 1 |
| `l` | Yes | 2 |
| `r` | Yes | 3 |
| `o` | Yes | 4 |
| `W` | Yes | 5 |

The pointer then reaches the space before `"World"`, so the loop stops.

**Output:** `5`

## Important Concepts

**1. Why use two while loops?**

- First loop removes trailing spaces logically by moving the pointer; it does not modify the string.
- Second loop counts only the characters of the last word.

**2. Why `right >= 0`?**

It prevents accessing an invalid index when the pointer moves before the beginning of the string.

**3. Why does the second loop stop at a space?**

A space marks the boundary between the last word and the preceding word.

**4. Does `right--` before `cnt++` cause a problem?**

No. Both operations happen once per character, so the count remains correct.

## Complexity Analysis

- **Time Complexity:** \(O(n)\) — in the worst case, the pointer traverses the entire string.
- **Space Complexity:** \(O(1)\) — only two integer variables are used.

## Key Takeaways
- **Technique:** Reverse traversal.
- Skip trailing spaces first, then count the last word.
- No extra string or array is required.
- `right >= 0` prevents invalid access.
- The string itself remains unchanged.