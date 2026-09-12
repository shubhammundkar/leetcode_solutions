/**
 * LeetCode 24 - Swap Nodes in Pairs
 * Topic: Linked List
 *
 * Question:
 * Given the head of a singly linked list, swap every two adjacent
 * nodes and return the new head.
 *
 * The nodes themselves must be swapped, not just their values.
 *
 * Example:
 * Input: 1 -> 2 -> 3 -> 4
 * Output: 2 -> 1 -> 4 -> 3
 *
 * Explanation:
 *
 * First pair:
 * 1 -> 2
 * becomes
 * 2 -> 1
 *
 * Second pair:
 * 3 -> 4
 * becomes
 * 4 -> 3
 *
 * Final list:
 * 2 -> 1 -> 4 -> 3
 *
 * Approach:
 * Use a dummy node before the head.
 *
 * Maintain a pointer `point` that stays just before the
 * pair of nodes that needs to be swapped.
 *
 * For every pair:
 *
 *     swap1 = first node
 *     swap2 = second node
 *
 * Before:
 *
 *     point -> swap1 -> swap2 -> next
 *
 * After:
 *
 *     point -> swap2 -> swap1 -> next
 *
 * Steps:
 * 1. Store the first two nodes.
 * 2. Make swap1 point to the node after swap2.
 * 3. Make swap2 point to swap1.
 * 4. Connect point to swap2.
 * 5. Move point to swap1 and process the next pair.
 *
 * Example walkthrough:
 *
 * 1 -> 2 -> 3 -> 4
 *
 * Initially:
 * point = dummy
 *
 * First pair:
 * swap1 = 1
 * swap2 = 2
 *
 * After swapping:
 * 2 -> 1 -> 3 -> 4
 *
 * Move point to 1.
 *
 * Second pair:
 * swap1 = 3
 * swap2 = 4
 *
 * After swapping:
 * 2 -> 1 -> 4 -> 3
 *
 * Move point to 3.
 *
 * No more complete pairs, so stop.
 *
 * Edge Cases:
 * - Empty list -> return nullptr
 * - One node -> return the same node
 * - Odd number of nodes -> last node remains unchanged
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* point = dummy;

        while(point->next != nullptr && point->next->next != nullptr) {

            ListNode* swap1 = point->next;
            ListNode* swap2 = point->next->next;

            swap1->next = swap2->next;
            swap2->next = swap1;

            point->next = swap2;

            point = swap1;
        }

        return dummy->next;
    }
};