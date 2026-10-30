// LeetCode 102 - Binary Tree Level Order Traversal
// Topic: Binary Tree, BFS, Queue
//
// Question:
// Given the root of a binary tree, return its level order traversal.
// Visit nodes level by level, from left to right.
//
// Example:
// Input: root = [3,9,20,null,null,15,1047]
//
// Output: [[3],[9,20],[15,7]]
//
//
// Approach:
// Use a queue because it follows FIFO (First In, First Out).
//
// 1. Push the root into the queue.
// 2. Store the current queue size in len.
//    This represents the number of nodes at the current level.
// 3. Process exactly len nodes.
// 4. Add each node's value to cur_lvl.
// 5. Push its non-null left and right children into the queue.
// 6. After processing the level, add cur_lvl to ans.
//
// Repeat until the queue becomes empty.
//
//
// Example Walkthrough:
//
//        3
//       / \
//      9   20
//          / \
//         15  7
//
// Initially:
// Queue = [3]
//
// Level 1:
// Process 3
// Add children 9 and 20
// cur_lvl = [3]
//
// Level 2:
// Process 9, then 20
// Add children 15 and 7
// cur_lvl = [9,20]
//
// Level 3:
// Process 15, then 7
// cur_lvl = [15,7]
//
// Final answer:
// [[3],[9,20],[15,7]]
//
//
// Important Idea:
//
// int len = q.size();
//
// Store the size BEFORE processing the current level.
// This ensures children added during this level are processed
// in the NEXT level, not the current one.
//
//
// Time Complexity: O(n)
// Each node is processed once.
//
// Space Complexity: O(n)
// The queue and result store nodes and values.
//
//
// Final Code:

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int len = q.size();
            vector<int> cur_lvl;

            for(int i = 0; i < len; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                cur_lvl.push_back(curr->val);

                if(curr->left != nullptr)
                    q.push(curr->left);

                if(curr->right != nullptr)
                    q.push(curr->right);
            }

            ans.push_back(cur_lvl);
        }

        return ans;
    }
};