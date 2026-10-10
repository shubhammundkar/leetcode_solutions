# LeetCode 389 – Find the Difference

**Topic:** String, Hashing, Frequency Array

## Question
You are given two strings `s` and `t`. String `t` is created by shuffling the characters of `s` and adding one extra character.

Find and return the extra character.

**Example:**
```text
Input:  s = "abcd", t = "abcde"
Output: 'e'
```

## Approach Used
**Frequency Counting + Negative Frequency Detection**

We use an integer array of size 26 to store the frequency of each lowercase letter.

1. Initialize `hashmap[26]` to zero.
2. Traverse `s` and increment the frequency of each character.
3. Traverse `t` and decrement the frequency of each character.
4. After processing each character of `t`, check the frequency array.
5. If any frequency becomes negative, return the corresponding character.
6. If no negative frequency is found, return `'\0'` as a fallback.

**Why does this work?**

Every character in `s` should have a matching occurrence in `t`. The extra character in `t` makes its frequency negative when we subtract the characters of `t` from the frequencies of `s`.

## Algorithm
```text
1. Initialize hashmap[26] = 0.

2. For each character c in s:
       hashmap[c - 'a']++

3. For each character c in t:
       hashmap[c - 'a']--

       For i = 0 to 25:
           If hashmap[i] < 0:
               Return character i + 'a'

4. Return '\0'.
```

## Code
```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hashmap[26] = {0};

        for (char c : s) {
            hashmap[c - 'a']++;
        }

        for (char c : t) {
            hashmap[c - 'a']--;

            for (int i = 0; i < 26; i++) {
                if (hashmap[i] < 0) {
                    return char(i + 'a');
                }
            }
        }

        return '\0';
    }
};
```

## Dry Run

Input: `s = "abcd"`, `t = "abced"`

After processing `s`:

| Character | a | b | c | d | e |
|---|---:|---:|---:|---:|---:|
| Frequency | 1 | 1 | 1 | 1 | 0 |

Now process `t`:

| Character processed | a | b | c | d | e | Result |
|---|---:|---:|---:|---:|---:|---|
| `a` | 0 | 1 | 1 | 1 | 0 | No negative |
| `b` | 0 | 0 | 1 | 1 | 0 | No negative |
| `c` | 0 | 0 | 0 | 1 | 0 | No negative |
| `e` | 0 | 0 | 0 | 1 | -1 | Return `'e'` |

The character `'e'` makes its frequency negative because it does not occur in `s`.

## Important Concepts

**1. Why `c - 'a'`?**

It converts a lowercase letter into an array index from `0` to `25`.

```cpp
hashmap[c - 'a']--;
```

For example, if `c = 'c'`, then `'c' - 'a' = 2`, so `hashmap[2]` is decremented.

**2. Why `i + 'a'`?**

It converts an array index back into its corresponding lowercase character.

```cpp
return char(i + 'a');
```

For example, if `i = 4`, then `4 + 'a'` gives `'e'`.

`i + 97` works for lowercase English letters because `'a'` has ASCII value 97, but `i + 'a'` is more readable and avoids relying on the numeric ASCII value explicitly.

**3. Is the inner loop necessary?**

No. Your code is correct, but checking all 26 frequencies after every character is inefficient. We can simply return the current character `c` when its frequency becomes negative:

```cpp
for (char c : t) {
    hashmap[c - 'a']--;

    if (hashmap[c - 'a'] < 0) {
        return c;
    }
}
```

This works because the frequency of the character being processed is the one that has just decreased. If it becomes negative, that character is the extra one.

## Optimized Code
```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hashmap[26] = {0};

        for (char c : s) {
            hashmap[c - 'a']++;
        }

        for (char c : t) {
            hashmap[c - 'a']--;

            if (hashmap[c - 'a'] < 0) {
                return c;
            }
        }

        return '\0';
    }
};
```

## Complexity Analysis

Let \(n\) be the length of `s`.

**Your original solution:**
- **Time Complexity:** \(O(n)\), because the alphabet has a fixed size of 26, so checking all 26 entries per character is constant work.
- **Space Complexity:** \(O(1)\), because the array always contains 26 integers.

**Optimized solution:**
- **Time Complexity:** \(O(n)\).
- **Space Complexity:** \(O(1)\).

## Key Takeaways
- **Technique:** Frequency counting with a fixed-size array.
- Increment frequencies for `s`; decrement frequencies for `t`.
- A negative frequency identifies the extra character.
- `i + 'a'` converts an index back to a character.
- Avoid checking all 26 entries after every character when checking the current character alone is sufficient.
- This solution assumes lowercase English letters and the problem's guarantee that `t` contains exactly one extra character.