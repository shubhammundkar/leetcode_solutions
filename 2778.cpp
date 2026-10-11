# LeetCode 2778 – Sum of Squares of Special Elements

**Topic:** Arrays, Loops, Modulo Operator, Indexing

## 1. Question

Given a 0-indexed integer array `nums` of length `n`, an element `nums[i]` is called **special** if `n` is divisible by `i + 1`.

Return the sum of the squares of all special elements.

**Example:**

Input: `nums = [1, 2, 3, 4]`

Output: `21`

Explanation:
- `n = 4`
- Index `0`: `4 % (0 + 1) == 0` → special → \(1^2 = 1\)
- Index `1`: `4 % (1 + 1) == 0` → special → \(2^2 = 4\)
- Index `2`: `4 % (2 + 1) != 0` → not special
- Index `3`: `4 % (3 + 1) == 0` → special → \(4^2 = 16\)

Total: \(1 + 4 + 16 = 21\)

## 2. Approach Used

Your approach is correct. You use **1-based indexing in the loop** while accessing the vector using `i - 1`.

```cpp
for(int i = 1; i <= nums.size(); i++)
```

Why start from `1`?

The question checks whether the array length `n` is divisible by the element's **1-based position**, which is `i + 1` when using a 0-based index.

You use `i` directly as the 1-based position, so the condition becomes:

```cpp
if(nums.size() % i == 0)
```

But vectors use 0-based indexing, so you access the element at:

```cpp
nums[i - 1]
```

**Remember:** `i` represents the 1-based position; `i - 1` represents the actual vector index.

## 3. Algorithm

1. Initialize `sum = 0`.
2. Loop `i` from `1` to `nums.size()`.
3. Check whether `nums.size() % i == 0`.
4. If true, add `nums[i-1] * nums[i-1]` to `sum`.
5. Return `sum`.

## 4. Code

```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;

        for(int i = 1; i <= nums.size(); i++) {
            if(nums.size() % i == 0) {
                sum += nums[i-1] * nums[i-1];
            }
        }

        return sum;
    }
};
```

## 5. Dry Run

Input: `nums = [2, 7, 1, 19, 18, 3]`

Here, `n = 6`.

| `i` (position) | `6 % i` | Element `nums[i-1]` | Action |
|---:|---:|---:|---|
| 1 | 0 | 2 | Add \(2^2 = 4\) |
| 2 | 0 | 7 | Add \(7^2 = 49\) |
| 3 | 0 | 1 | Add \(1^2 = 1\) |
| 4 | 2 | 19 | Skip |
| 5 | 1 | 18 | Skip |
| 6 | 0 | 3 | Add \(3^2 = 9\) |

Final sum = `4 + 49 + 1 + 9 = 63`

## 6. Time and Space Complexity

- **Time Complexity:** \(O(n)\), because the loop visits every position once.
- **Auxiliary Space Complexity:** \(O(1)\), because only a few variables are used.

## 7. Counterexamples and Edge Cases

| Input | Expected output | Reason |
|---|---:|---|
| `[5]` | 25 | The only position is special |
| `[1, 2]` | 5 | Positions 1 and 2 are both special |
| `[1, 2, 3]` | 1 | Only position 1 divides 3 |
| `[2, 7, 1, 19, 18, 3]` | 63 | Positions 1, 2, 3 and 6 are special |

## 8. Key Takeaways

- `nums.size()` gives the number of elements, not the last index.
- For a vector of size `n`, valid indices are `0` through `n - 1`.
- Your loop uses positions `1` through `n`, so `nums[i - 1]` is necessary.
- `%` checks divisibility: `n % i == 0` means `n` is divisible by `i`.
- Always check whether your loop variable represents an **index** or a **position** before accessing an array.
