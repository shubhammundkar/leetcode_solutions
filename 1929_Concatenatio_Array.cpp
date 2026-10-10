# LeetCode 1929 – Concatenation of Array

**Topic:** Array, Indexing, Vector

## Question
Given an integer array `nums` of length `n`, create an array `ans` of length `2n` such that:

- `ans[i] = nums[i]`
- `ans[i + n] = nums[i]`

In simple words, concatenate the array with itself.

**Example:**
```text
Input:  nums = [1, 2, 1]
Output: [1, 2, 1, 1, 2, 1]
```

## Approach Used
**Preallocated Vector + Index Mapping**

1. Create `ans` with size `2 * nums.size()`.
2. Traverse the original array using index `i`.
3. Copy `nums[i]` into the first half at `ans[i]`.
4. Copy the same element into the second half at `ans[i + nums.size()]`.
5. Return `ans`.

## Algorithm
```text
1. n = nums.size()
2. Create ans with size 2 * n.
3. For i = 0 to n - 1:
       ans[i] = nums[i]
       ans[i + n] = nums[i]
4. Return ans.
```

## Code
```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2 * nums.size());

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }

        return ans;
    }
};
```

## Dry Run

Input: `nums = [1, 2, 1]`

Here, `n = 3`, so `ans` initially contains six zeros.

| `i` | `ans[i] = nums[i]` | `ans[i+n] = nums[i]` | Result |
|---:|---|---|---|
| 0 | `ans[0] = 1` | `ans[3] = 1` | `[1, 0, 0, 1, 0, 0]` |
| 1 | `ans[1] = 2` | `ans[4] = 2` | `[1, 2, 0, 1, 2, 0]` |
| 2 | `ans[2] = 1` | `ans[5] = 1` | `[1, 2, 1, 1, 2, 1]` |

**Output:** `[1, 2, 1, 1, 2, 1]`

## Important Concept: Why `i + nums.size()`?

Suppose `nums = [1, 2, 3]` and `n = 3`.

- First half indices: `0, 1, 2`
- Second half indices: `3, 4, 5`

Adding `n` to `i` shifts the position into the second half.

```cpp
ans[i] = nums[i];          // First copy
ans[i + nums.size()] = nums[i];  // Second copy
```

Because `ans` was created with `2 * nums.size()` elements, indexed assignments are valid.

## Complexity Analysis

- **Time Complexity:** \(O(n)\) — each input element is copied twice.
- **Auxiliary Space Complexity:** \(O(n)\) — the result vector stores `2n` elements.

## Counterexamples to Test

| Input | Expected output |
|---|---|
| `[1]` | `[1, 1]` |
| `[1, 2]` | `[1, 2, 1, 2]` |
| `[0, 0, 0]` | `[0, 0, 0, 0, 0, 0]` |

## Key Takeaways
- **Technique:** Array indexing.
- `vector<int> ans(2 * n)` allocates the required number of elements.
- Use `i + n` to access the corresponding position in the second half.
- Your solution is correct and optimal in time complexity: \(O(n)\).