
// LeetCode 19 - Remove Nth Node From End of List
// Topic: Linked List
//
// Question:
// Given the head of a linked list, remove the nth node from the end
// of the list and return the head.
//
// Example:
// Input: 1 -> 2 -> 3 -> 4 -> 5, n = 2
//
// Output:
// 1 -> 2 -> 3 -> 5
//
// Explanation:
// The 2nd node from the end is 4.
//
//
// Approach:
// First, count the total number of nodes.
//
// Let:
// cnt = total number of nodes
//
// The position of the node from the beginning is:
//
// cnt - n
//
// We need to reach the node just BEFORE the node we want to delete.
//
// Therefore, move:
// cnt - n - 1 steps from head.
//
// Then:
// temp->next = nodeToDelete->next
//
// Finally, delete the unwanted node.
//
//
// Special Case:
// If cnt == n, the node to delete is the head.
//
// Example:
//
// 1 -> 2 -> 3
// n = 3
//
// Delete head:
//
// head = head->next
//
//
// Example Walkthrough:
//
// List:
// 1 -> 2 -> 3 -> 4 -> 5
//
// n = 2
//
// cnt = 5
//
// Node to delete:
// cnt - n = 5 - 2 = 3rd position
//
// Node = 4
//
// We move to the node before it:
//
// temp = 3
//
// deleteNode = temp->next
//             = 4
//
// temp->next = deleteNode->next
//
// Result:
//
// 1 -> 2 -> 3 -> 5
//
//
// Time Complexity: O(n)
//
// We traverse the list to count nodes and then traverse again
// to reach the node before the one to delete.
//
// Space Complexity: O(1)
//
//
// Final Code:

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
        {
            return head;
        }

        ListNode* temp = head;
        int cnt = 0;

        // Count total nodes
        while(temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }

        // If head needs to be deleted
        if(cnt == n)
        {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;

            return head;
        }

        temp = head;

        // Reach node before the node to delete
        for(int i = 0; i < cnt - n - 1; i++)
        {
            temp = temp->next;
        }

        ListNode* deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;

        return head;
    }
};



// ------------------------------------------------------------
// Optimized Approach: Two Pointers
//
// Instead of counting the total number of nodes first,
// use two pointers: fast and slow.
//
// Move fast n steps ahead.
//
// Then move both fast and slow one step at a time.
// When fast reaches nullptr, slow will be at the node
// just before the node that needs to be deleted.
//
// Example:
//
// 1 -> 2 -> 3 -> 4 -> 5
// n = 2
//
// Move fast 2 steps:
//
// slow -> 1
// fast ------> 3
//
// Now move both:
//
// slow -> 2
// fast ------> 4
//
// slow -> 3
// fast ------> 5
//
// slow -> 4
// fast ------> nullptr
//
// slow is at 4, so delete slow->next.
//
// Result:
//
// 1 -> 2 -> 3 -> 5
//
//
//
// Important:
// A dummy node is used before head.
//
// dummy -> 1 -> 2 -> 3 -> 4 -> 5
//
// This makes deleting the head easier because even the head
// has a previous node (dummy).
//
//
// Time Complexity: O(n)
//
// Space Complexity: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n steps ahead
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // slow is just before the node to delete
        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;

        delete deleteNode;

        head = dummy->next;
        delete dummy;

        return head;
    }
};
