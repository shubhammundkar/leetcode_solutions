```cpp
// LeetCode 142 - Linked List Cycle II
// Topic: Linked List, Two Pointers
//
// Question:
// Given the head of a linked list, return the node where the cycle begins.
// If there is no cycle, return nullptr.
//
//
// Approach:
// Use Floyd's Tortoise and Hare algorithm.
//
// slow moves 1 step.
// fast moves 2 steps.
//
// First, find whether a cycle exists.
//
// If slow and fast meet, a cycle is present.
//
// Then move fast back to head.
//
// Now move both slow and fast one step at a time.
//
// The node where they meet again is the beginning of the cycle.
//
//
// Why does moving fast to head work?
//
// Suppose:
//
// head → A → B → C → D
//             ↑       ↓
//             ← ← ← ←
//
// After slow and fast meet inside the cycle,
// resetting fast to head makes the distance between
// head and cycle start equal to the remaining distance
// from the meeting point to the cycle start.
//
// Therefore, moving both one step at a time makes them
// meet exactly at the cycle's starting node.
//
//
// Example:
//
// 3 → 2 → 0 → -4
//     ↑         ↓
//     ← ← ← ← ←
//
// slow and fast meet inside the cycle.
//
// Move fast back to head:
//
// fast → 3
// slow → meeting point
//
// Move both one step:
//
// fast → 2
// slow → 2
//
// They meet at 2.
//
// Therefore, 2 is the starting node of the cycle.
//
//
// Important Conditions:
//
// while(fast != nullptr && fast->next != nullptr)
//
// Prevents accessing a nullptr.
//
//
// Time Complexity: O(n)
//
// Space Complexity: O(1)
//
//
// Final Code:

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Edge case
        if(head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle is present
            if(fast == slow)
            {
                fast = head;

                // Find the starting node of cycle
                while(fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};
```
