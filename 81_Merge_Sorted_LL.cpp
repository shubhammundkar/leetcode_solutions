```cpp
// LeetCode 21 - Merge Two Sorted Lists
// Topic: Linked List, Recursion
//
// Question:
// Given the heads of two sorted linked lists, merge them into one
// sorted linked list and return its head.
//
// Example:
// list1 = 1 -> 2 -> 4
// list2 = 1 -> 3 -> 4
//
// Output:
// 1 -> 1 -> 2 -> 3 -> 4 -> 4
//
//
// Approach:
// Compare the current nodes of both lists.
//
// If list1->val <= list2->val:
//     Keep list1's node.
//     Recursively merge the remaining list1 with list2.
//
// Otherwise:
//     Keep list2's node.
//     Recursively merge list1 with the remaining list2.
//
// When either list becomes nullptr, return the other list.
//
//
// Example Walkthrough:
//
// list1 = 1 -> 2 -> 4
// list2 = 1 -> 3 -> 4
//
// 1 <= 1
// Take list1's 1.
//
// Compare:
// 2 and 1
// Take list2's 1.
//
// Compare:
// 2 and 3
// Take 2.
//
// Compare:
// 4 and 3
// Take 3.
//
// Compare:
// 4 and 4
// Take list1's 4.
//
// Finally, attach the remaining 4.
//
// Result:
// 1 -> 1 -> 2 -> 3 -> 4 -> 4
//
//
// Important Idea:
//
// list1->next = mergeTwoLists(list1->next, list2);
//
// This means:
// Keep the current list1 node and recursively find
// what should come after it.
//
// Similarly:
//
// list2->next = mergeTwoLists(list1, list2->next);
//
//
//
// Base Case:
//
// if(list1 == nullptr || list2 == nullptr)
//
// If one list is finished, return the other list directly.
//
//
// Time Complexity: O(n + m)
//
// n = number of nodes in list1
// m = number of nodes in list2
//
//
// Space Complexity: O(n + m)
//
// Due to recursive function calls.
//
//
// Final Code:

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr || list2 == nullptr)
        {
            return list1 == nullptr ? list2 : list1;
        }

        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};