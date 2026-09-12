// LeetCode 21 - Merge Two Sorted Lists
// Topic: Linked List
//
// Question:
// Given the heads of two sorted singly linked lists, merge them
// into one sorted linked list and return the head of the merged list.
//
// The original nodes should be reused instead of creating new nodes
// for every element.
//
// Example:
// Input:
// list1 = 1 -> 2 -> 4
// list2 = 1 -> 3 -> 4
//
// Output:
// 1 -> 1 -> 2 -> 3 -> 4 -> 4
//
// Explanation:
// Compare the current nodes of both lists and attach the smaller
// node to the merged list.
//
// Approach:
// Use a dummy node to make handling the first node easier.
//
// Maintain three pointers:
//
// temp1 -> current node of list1
// temp2 -> current node of list2
// temp  -> last node of the merged list
//
// Compare temp1->val and temp2->val.
//
// If temp1 is smaller or equal:
//     Attach temp1 to the merged list.
//     Move temp1 forward.
//
// Otherwise:
//     Attach temp2 to the merged list.
//     Move temp2 forward.
//
// Continue until one of the lists becomes empty.
//
// Finally, attach the remaining nodes of the non-empty list.
//
// Example walkthrough:
//
// list1 = 1 -> 2 -> 4
// list2 = 1 -> 3 -> 4
//
// Compare 1 and 1:
// 1 <= 1 -> take list1
//
// Merged:
// 1
//
// Compare 2 and 1:
// 2 > 1 -> take list2
//
// Merged:
// 1 -> 1
//
// Compare 2 and 3:
// 2 < 3 -> take list1
//
// Merged:
// 1 -> 1 -> 2
//
// Compare 4 and 3:
// 4 > 3 -> take list2
//
// Merged:
// 1 -> 1 -> 2 -> 3
//
// Compare 4 and 4:
// 4 <= 4 -> take list1
//
// Merged:
// 1 -> 1 -> 2 -> 3 -> 4
//
// list1 is now empty, so attach the remaining list2:
//
// 1 -> 1 -> 2 -> 3 -> 4 -> 4
//
// Time Complexity: O(n + m)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp = dummy;

        while(temp1 != nullptr && temp2 != nullptr) {
            if(temp1->val <= temp2->val) {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }

        if(temp1)
            temp->next = temp1;
        else
            temp->next = temp2;

        return dummy->next;
    }
};