# LeetCode 2 - Add Two Numbers

**Topic:** Linked List

## Question

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in **reverse order**.

Add the two numbers and return the sum as a linked list, also in reverse order.

### Example

```text
l1 = 2 → 4 → 3
l2 = 5 → 6 → 4

342 + 465 = 807

Output:
7 → 0 → 8
```

## Approach Used

**Linked List Traversal + Carry**

We traverse both linked lists at the same time, just like normal addition.

1. Create a `dummy` node to make result-list creation easy.
2. Use `tail` to point to the last node of the result.
3. Keep a `carry` variable.
4. Continue while:

   * `l1` exists, OR
   * `l2` exists, OR
   * `carry` is not `0`.
5. Add the current values of `l1`, `l2`, and `carry`.
6. Calculate:

   * `carry = sum / 10`
   * `sum = sum % 10`
7. Create a new node containing `sum`.
8. Move `tail` forward.
9. Return `dummy.next`.

## Algorithm

```text
Create dummy node
tail = dummy
carry = 0

while l1 exists OR l2 exists OR carry exists:

    sum = carry

    if l1 exists:
        add l1 value to sum
        move l1

    if l2 exists:
        add l2 value to sum
        move l2

    carry = sum / 10
    digit = sum % 10

    create new node with digit
    attach it after tail
    move tail

return dummy.next
```

## Code

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            tail->next = new ListNode(sum);
            tail = tail->next;
        }

        return dummy.next;
    }
};
```

## Dry Run

```text
l1:  2 → 4 → 3
l2:  5 → 6 → 4

carry = 0

2 + 5 = 7
digit = 7, carry = 0

4 + 6 = 10
digit = 0, carry = 1

3 + 4 + 1 = 8
digit = 8, carry = 0

Result:
7 → 0 → 8
```

## Why `carry = sum / 10` first?

Suppose:

```text
8 + 7 = 15
```

We need:

```text
digit = 5
carry = 1
```

So:

```cpp
carry = sum / 10;   // 1
sum = sum % 10;     // 5
```

The carry must be calculated **before changing `sum`**.

## Why `dummy` node?

Instead of handling the first node separately, we start with:

```cpp
ListNode dummy(0);
ListNode* tail = &dummy;
```

Then every new result node can simply be attached using:

```cpp
tail->next = new ListNode(sum);
tail = tail->next;
```

Finally:

```cpp
return dummy.next;
```

because `dummy` itself is not part of the answer.

## Time Complexity

**O(max(n, m))**

We visit each node of both linked lists once.

## Space Complexity

**O(max(n, m))**

The result linked list requires at most `max(n,m) + 1` nodes.

## Key Points to Remember

* **Topic:** Linked List
* **Technique:** Simultaneous traversal + carry
* `sum = carry` at the beginning of every iteration.
* `carry = sum / 10`
* `digit = sum % 10`
* `dummy` makes result creation easier.
* Loop condition includes `carry != 0` so a final carry is not missed.
