# LeetCode 2273 – Find Resultant Array After Removing Anagrams

**Topic:** String, Hashing, Frequency Array, Vector

## Question

Given an array of strings `words`, remove a word if it is an anagram of the **previous word that remains** in the array. Return the resulting array.

**Example:**

```text
Input:  words = ["abba","baba","bbaa","cd","cd"]

Output: ["abba","cd"]
```

Explanation:

* `"baba"` is an anagram of `"abba"`, so remove it.
* `"bbaa"` is also an anagram of `"abba"`, so remove it.
* `"cd"` is not an anagram of `"abba"`, so keep it.
* The next `"cd"` is an anagram of the previous remaining word `"cd"`, so remove it.

## Approach Used

**Frequency Counting + Comparing Adjacent Remaining Words**

1. Create a result vector `res` and push the first word into it.
2. For every subsequent word, create two frequency arrays of size 26.
3. Count the character frequencies of the current word in `hashmap1`.
4. Count the frequencies of the last word in `res` using `res.back()` and store them in `hashmap2`.
5. Compare both arrays:

   * If all frequencies match, the words are anagrams, so skip the current word.
   * If any frequency differs, push the current word into `res`.
6. Return `res`.

## Algorithm

```text
1. Create an empty result vector res.
2. Push words[0] into res.

3. For each word from index 1:
      Initialize hashmap1[26] and hashmap2[26] to 0.

      Count frequencies of the current word.
      Count frequencies of res.back().

      Set Anagram = true.

      Compare all 26 frequencies:
          If any frequency differs:
              Anagram = false
              Break

      If Anagram is false:
          Push the current word into res.

4. Return res.
```

## Code

```cpp
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            int hashmap1[26] = {0};
            int hashmap2[26] = {0};

            for (char c : words[i]) {
                hashmap1[c - 'a']++;
            }

            for (char c : res.back()) {
                hashmap2[c - 'a']++;
            }

            bool Anagram = true;

            for (int j = 0; j < 26; j++) {
                if (hashmap1[j] != hashmap2[j]) {
                    Anagram = false;
                    break;
                }
            }

            if (!Anagram) {
                res.push_back(words[i]);
            }
        }

        return res;
    }
};
```

## Important Concepts

**1. `res.back()`**

Returns the last element of the result vector.

Example:

```cpp
res = {"abba", "cd"};

res.back();  // "cd"
```

We use it because the current word must be compared with the **previous word that remains**, not necessarily the previous word in the original array.

**2. Why do we push only when `!Anagram`?**

```cpp
if (!Anagram) {
    res.push_back(words[i]);
}
```

* `Anagram == true`: Skip the current word.
* `Anagram == false`: Keep the current word.

**3. Why use `j` in the comparison loop?**

```cpp
for (int j = 0; j < 26; j++)
```

Using `j` avoids reusing the outer loop variable `i`. Your original code works with a separate inner `i` because it is declared in a new scope, but `j` makes the code easier to read.

## Complexity Analysis

Let:

* \(n\) = number of words
* \(k\) = maximum length of a word

**Time Complexity:** \(O(nk)\)

For every word, we count characters in the current and previous remaining words and compare 26 frequencies. Since the alphabet size is fixed, the total is \(O(nk)\).

**Auxiliary Space Complexity:** \(O(1)\)

The two frequency arrays each have a fixed size of 26.

**Output Space:** \(O(nk)\) in the worst case for storing the resulting strings.

## Key Takeaways

* **Technique:** Frequency counting with a fixed-size array.
* `res.back()` accesses the last word that was retained.
* Anagrams have identical character frequencies regardless of order.
* Skip the current word if its frequencies match the last retained word.
* Otherwise, push it into `res`.
* The result vector preserves the original order of the retained words.
