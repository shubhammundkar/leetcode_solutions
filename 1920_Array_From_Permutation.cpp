# LeetCode 1920 – Build Array from Permutation

**Topic:** Array, Indexing, In-place Optimization

## Question
Given a zero-indexed permutation `nums`, build an array `ans` of the same length such that:

`ans[i] = nums[nums[i]]`

Return the resulting array.

**Example:**
```text
Input:  nums = [0, 2, 1, 5, 3, 4]
Output: [0, 1, 2, 4, 5, 3]
```

## Approach Used
**Direct Indexing + `push_back()`**

1. Create an empty vector `ans`.
2. Traverse `nums` from index `0` to `nums.size() - 1`.
3. For each index `i`, access `nums[nums[i]]`.
4. Append that value to `ans` using `push_back()`.
5. Return `ans`.

## Algorithm
```text
1. Create an empty vector ans.
2. For i = 0 to nums.size() - 1:
       ans.push_back(nums[nums[i]])
3. Return ans.
```

## Code
```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[nums[i]]);
        }

        return ans;
    }
};
```

## Dry Run

Input: `nums = [0, 2, 1, 5, 3, 4]`

| `i` | `nums[i]` | `nums[nums[i]]` | `ans` after insertion |
|---:|---:|---:|---|
| 0 | 0 | `nums[0] = 0` | `[0]` |
| 1 | 2 | `nums[2] = 1` | `[0, 1]` |
| 2 | 1 | `nums[1] = 2` | `[0, 1, 2]` |
| 3 | 5 | `nums[5] = 4` | `[0, 1, 2, 4]` |
| 4 | 3 | `nums[3] = 5` | `[0, 1, 2, 4, 5]` |
| 5 | 4 | `nums[4] = 3` | `[0, 1, 2, 4, 5, 3]` |

**Output:** `[0, 1, 2, 4, 5, 3]`

## Important Concepts

**1. Why `nums[nums[i]]`?**

There are two indexing operations:

```cpp
nums[i]        // Get the value at index i
nums[nums[i]]  // Use that value as another index
```

For example, if `i = 1`:

```text
nums[1] = 2
nums[nums[1]] = nums[2] = 1
```

**2. Why does `ans.push_back()` work?**

```cpp
vector<int> ans;
ans.push_back(10);
```

An empty vector has no elements initially. `push_back()` appends a new element and automatically increases the vector's size.

However, this would be invalid:

```cpp
vector<int> ans;
ans[0] = 10;  // Invalid: no element exists at index 0
```

To use indexed assignment, allocate the elements first:

```cpp
vector<int> ans(nums.size());

for (int i = 0; i < nums.size(); i++) {
    ans[i] = nums[nums[i]];
}
```

**3. Does `vector<int> ans(nums.size())` initialize elements to zero?**

Yes. When a vector is created with a size, its `int` elements are value-initialized to `0`, and its `bool` elements to `false`.

## Complexity Analysis

- **Time Complexity:** \(O(n)\) — one constant-time indexing operation and one append per element on average.
- **Auxiliary Space Complexity:** \(O(n)\) — the result vector stores `n` elements.

## Can Space Complexity Be Optimized?

Your comment says this can be optimized. Yes, **the extra space can be reduced from \(O(n)\) to \(O(1)\)** by encoding both the original and new values in each element, modifying `nums` in place, and then decoding it.

One common method uses the fact that every value in this permutation is between `0` and `n - 1`.

```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] += n * (nums[nums[i]] % n);
        }

        for (int i = 0; i < n; i++) {
            nums[i] /= n;
        }

        return nums;
    }
};
```

The first loop stores the new value in the higher part of each element while preserving the original value in the remainder. The second loop extracts the encoded new values.

- **Time Complexity:** \(O(n)\)
- **Auxiliary Space Complexity:** \(O(1)\)

This optimized approach modifies the input array, so your original solution is preferable when you need to preserve `nums`.

## Key Takeaways
- **Technique:** Direct indexing.
- `nums[nums[i]]` uses the value at index `i` as another index.
- `push_back()` appends to a vector without requiring preallocated elements.
- Your original solution is correct, simple, and runs in \(O(n)\) time.
- Its \(O(n)\) extra space is not optimal if in-place modification is allowed.