# LeetCode 1480 – Running Sum of 1d Array

**Topic:** Array, Prefix Sum, In-place Modification

## Question
Given an array `nums`, return its running sum, where each element is the sum of all elements from index `0` to that index.

**Formula:**

`runningSum[i] = nums[0] + nums[1] + ... + nums[i]`

**Example:**
```text
Input:  nums = [1, 2, 3, 4]
Output: [1, 3, 6, 10]

Explanation:
- Index 0: `1`
- Index 1: `1 + 2 = 3`
- Index 2: `1 + 2 + 3 = 6`
- Index 3: `1 + 2 + 3 + 4 = 10`

## Approach Used
**In-place Prefix Sum**

Instead of creating a separate array, we modify the original array.

1. Start from index `1` because the first element is already its own running sum.
2. Add the previous running sum to the current element.
3. Repeat until the last index.
4. Return the modified array.

## Algorithm
```text
1. For i = 1 to nums.size() - 1:
       nums[i] = nums[i] + nums[i - 1]

2. Return nums.
```

## Code
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};
```

## Dry Run

Input: `nums = [1, 2, 3, 4]`

| Iteration | Calculation | Updated array |
|---|---|---|
| Initially | — | `[1, 2, 3, 4]` |
| `i = 1` | `nums[1] = 2 + 1 = 3` | `[1, 3, 3, 4]` |
| `i = 2` | `nums[2] = 3 + 3 = 6` | `[1, 3, 6, 4]` |
| `i = 3` | `nums[3] = 4 + 6 = 10` | `[1, 3, 6, 10]` |

**Output:** `[1, 3, 6, 10]`

## Important Concept: Why `nums[i - 1]`?

```cpp
nums[i] += nums[i - 1];
```

The previous element already contains the running sum up to that index.

For example, at `i = 2`:

```text
nums[1] = 1 + 2 = 3

nums[2] = 3 + nums[1]
        = 3 + 3
        = 6
```

So we don't need to add all previous elements again.

**Remember:** `nums[i - 1]` is not necessarily the original previous element. It has already been updated with its running sum.

## Complexity Analysis

- **Time Complexity:** \(O(n)\) — each element is processed once.
- **Auxiliary Space Complexity:** \(O(1)\) — no extra array is created; the original array is modified in place.

## Counterexamples to Test

| Input | Expected output | What it checks |
|---|---|---|
| `[5]` | `[5]` | Single element |
| `[1, 1, 1, 1]` | `[1, 2, 3, 4]` | Repeated values |
| `[1, 2, 3, 4]` | `[1, 3, 6, 10]` | Normal case |
| `[0, 0, 0]` | `[0, 0, 0]` | All zeros |

## Key Takeaways
- **Technique:** Prefix sum.
- Start at index `1` because index `0` needs no modification.
- Each element stores the sum of all elements up to that index.
- In-place modification saves extra space.
- Your solution is correct and optimal for this problem.