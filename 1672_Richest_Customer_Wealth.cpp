# LeetCode 1672 – Richest Customer Wealth

**Topic:** 2D Array, Nested Loops, Maximum

## Question
You are given a 2D array `accounts`, where `accounts[i][j]` represents the money the \(i\)-th customer has in the \(j\)-th bank.

The wealth of a customer is the total money they have across all their bank accounts.

Return the **maximum wealth** among all customers.

**Example:**
```text
Input: accounts = [[1, 2, 3], [3, 2, 1]]

Output: 6
```

Explanation:
- Customer 0: `1 + 2 + 3 = 6`
- Customer 1: `3 + 2 + 1 = 6`

Maximum wealth = `6`.

## Approach Used
**Nested Loops + Running Sum + Maximum Tracking**

1. Initialize `max_wealth = 0`.
2. Traverse each customer using the outer loop.
3. Initialize `curr_wealth = 0` for each customer.
4. Use the inner loop to add the money from all the customer's bank accounts.
5. Update the maximum wealth using `max(max_wealth, curr_wealth)`.
6. Return `max_wealth`.

## Algorithm
```text
1. max_wealth = 0

2. For each customer i:
       curr_wealth = 0

       For each bank account j of customer i:
           curr_wealth += accounts[i][j]

       max_wealth = max(max_wealth, curr_wealth)

3. Return max_wealth
```

## Code
```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;

        for (int i = 0; i < accounts.size(); i++) {
            int curr_wealth = 0;

            for (int j = 0; j < accounts[i].size(); j++) {
                curr_wealth += accounts[i][j];
            }

            max_wealth = max(max_wealth, curr_wealth);
        }

        return max_wealth;
    }
};
```

## Dry Run

Input:
```text
accounts = [
    [1, 2, 3],
    [3, 2, 1],
    [4, 5, 2]
]
```

| Customer (`i`) | Bank balances | `curr_wealth` | `max_wealth` |
|---:|---|---:|---:|
| 0 | `[1, 2, 3]` | 6 | 6 |
| 1 | `[3, 2, 1]` | 6 | 6 |
| 2 | `[4, 5, 2]` | 11 | 11 |

**Output:** `11`

## Important Concepts

**1. Why use `accounts[i].size()`?**

```cpp
for (int j = 0; j < accounts[i].size(); j++)
```

- `accounts.size()` gives the number of customers (rows).
- `accounts[i].size()` gives the number of bank accounts belonging to customer `i` (columns in that row).

This allows the code to handle customers with different numbers of bank accounts.

**2. Why reset `curr_wealth = 0` inside the outer loop?**

Each customer must have their wealth calculated independently. If you initialize `curr_wealth` outside the outer loop, money from previous customers could incorrectly carry over.

**3. Why use `max()`?**

```cpp
max_wealth = max(max_wealth, curr_wealth);
```

It keeps whichever value is larger: the maximum found so far or the current customer's wealth.

## Complexity Analysis

Let:
- \(m\) = number of customers.
- \(n\) = maximum number of bank accounts per customer.

- **Time Complexity:** \(O(mn)\) in the rectangular case, or \(O(\text{total number of bank balances})\) for rows of different lengths.
- **Auxiliary Space Complexity:** \(O(1)\) — only two integer variables are used.

## Counterexamples to Test

| Input | Expected output | What it checks |
|---|---:|---|
| `[[5]]` | 5 | One customer, one account |
| `[[1,2],[3,4]]` | 7 | Different customer wealth |
| `[[1,1,1],[2]]` | 3 | Different row lengths |
| `[[0,0],[0,0]]` | 0 | All balances are zero |

## Key Takeaways
- **Technique:** 2D array traversal using nested loops.
- Outer loop → customers.
- Inner loop → bank accounts of the current customer.
- `curr_wealth` calculates one customer's total.
- `max_wealth` stores the richest customer's wealth.
- Your solution correctly handles rows of different lengths and runs in linear time relative to the total number of balances.