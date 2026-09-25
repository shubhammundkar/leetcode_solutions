
// LeetCode 141 - Linked List Cycle
// Topic: Linked List, Two Pointers
//
// Question:
// Given the head of a linked list, determine if the linked list
// contains a cycle.
//
// A cycle exists when a node's next pointer points back to a
// previous node instead of pointing to nullptr.
//
// Return true if a cycle exists, otherwise return false.
//
//
// Approach:
// Use two pointers:
//
// slow -> moves one step at a time
// fast -> moves two steps at a time
//
// If there is no cycle:
//     fast will eventually reach nullptr.
//
// If there is a cycle:
//     fast will eventually catch up to slow.
//
// Therefore, if:
//
// slow == fast
//
// a cycle exists.
//
//
// Example:
//
// 1 -> 2 -> 3 -> 4
//          ↑    ↓
//          ← ← ←
//
// slow and fast will eventually meet inside the cycle.
//
//
// Important Condition:
//
// while(fast != nullptr && fast->next != nullptr)
//
// This prevents fast->next from being accessed when fast is nullptr.
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};
