# LeetCode 242 – Valid Anagram

**Topic:** String, Hashing, Frequency Array

## Question

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, otherwise return `false`.

An anagram contains the same characters with the same frequencies, but the order can differ.

**Example:**

```text
Input:  s = "anagram", t = "nagaram"
Output: true

Input:  s = "rat", t = "car"
Output: false
```

## Approach Used

**Frequency Counting using Two Hash Arrays**

1. If the lengths of both strings differ, return `false`.
2. Create two arrays of size 26, initialized to `0`, to store the frequencies of lowercase English letters.
3. Traverse both strings simultaneously and increment the frequency of each character.
4. Compare the frequencies of all 26 letters.
5. If any frequency differs, return `false`; otherwise, return `true`.

## Algorithm

```text
1. If lengths differ, return false.
2. Initialize hashmap1[26] and hashmap2[26] to 0.
3. For every index i:
      hashmap1[s[i] - 'a']++
      hashmap2[t[i] - 'a']++
4. For i = 0 to 25:
      If hashmap1[i] != hashmap2[i]:
          return false
5. Return true.
```

## Code

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int hashmap1[26] = {0};
        int hashmap2[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            hashmap1[s[i] - 'a']++;
            hashmap2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (hashmap1[i] != hashmap2[i])
                return false;
        }

        return true;
    }
};
```

## Dry Run

Input: `s = "rat"`, `t = "car"`

| Character | Frequency in `s` | Frequency in `t` |
| --------- | ---------------: | ---------------: |
| a         |                1 |                1 |
| c         |                0 |                1 |
| r         |                1 |                1 |
| t         |                1 |                0 |

The frequencies of `c` and `t` differ, so the answer is `false`.

## Important Concept: `s[i] - 'a'`

Characters have numeric character codes. Subtracting `'a'` converts a lowercase letter into an index from `0` to `25`.

| Character |            Index |
| --------- | ---------------: |
| `'a'`     |  `'a' - 'a' = 0` |
| `'b'`     |  `'b' - 'a' = 1` |
| `'c'`     |  `'c' - 'a' = 2` |
| `'z'`     | `'z' - 'a' = 25` |

For example, `hashmap1[s[i] - 'a']++` increases the frequency of the character at that index.

**Remember:** `int hashmap[26] = {0};` initializes all 26 elements to zero.

This solution assumes both strings contain only lowercase English letters. For uppercase letters, use `s[i] - 'A'` when indexing uppercase characters. To handle mixed uppercase and lowercase letters as equivalent, convert them to lowercase first, for example using `tolower()`.

## Complexity Analysis

* **Time Complexity:** \(O(n)\) — counting takes \(O(n)\), and comparing 26 frequencies takes constant time.
* **Space Complexity:** \(O(1)\) — two arrays of fixed size 26 are used.

## Key Takeaways

* **Technique:** Frequency counting using arrays.
* **Why two arrays?** To count the characters in each string independently.
* **Why compare all 26 indices?** Anagrams must have identical frequencies for every letter.
* **Why check lengths first?** Strings with different lengths cannot be anagrams.
* **Optimization:** A single frequency array can also solve this problem by incrementing for `s` and decrementing for `t`.
