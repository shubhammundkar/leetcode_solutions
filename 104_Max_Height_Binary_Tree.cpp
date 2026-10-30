LeetCode 104 - Maximum Depth of Binary Tree

Topic: Binary Tree, Recursion

Question

Find the maximum depth of a binary tree. Maximum depth is the number of nodes along the longest path from the root node to a leaf node.

Example

Input: "root = [3,9,20,null,null,15,7]"

Output: "3"

Approach

Use recursion to calculate the height of the left and right subtrees.

1. Base Case: If "root == nullptr", return "0".
2. Recursively calculate the maximum depth of the left subtree.
3. Recursively calculate the maximum depth of the right subtree.
4. Return the larger depth + 1 for the current node.

Important Concept: Nodes vs Edges

- If "nullptr" returns "-1", the result represents the number of edges.
- If "nullptr" returns "0", the result represents the number of nodes.

In this problem, depth is defined as the number of nodes from root to the deepest leaf. Therefore, we return "0" for a null node and add "1" for the current node.

Final Code

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        return max(maxDepth(root->left),
                   maxDepth(root->right)) + 1;
    }
};

Complexity

- Time Complexity: O(n) — every node is visited once.
- Space Complexity: O(h) — recursive call stack, where h is the tree height. Worst case O(n).