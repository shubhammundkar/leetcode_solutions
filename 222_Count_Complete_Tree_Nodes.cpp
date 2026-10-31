LeetCode 222 - Count Complete Tree Nodes

Topic: Binary Tree, Recursion

Question

Given the root of a complete binary tree, return the total number of nodes in the tree.

Approach

Use recursion to count nodes in the left and right subtrees.

1. Base Case: If "root == nullptr", return "0".
2. Recursively count all nodes in the left subtree.
3. Recursively count all nodes in the right subtree.
4. Add "1" for the current root node.

Example

Input: "root = [1,2,3,4,5,6]"

Output: "6"

Final Code

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        return countNodes(root->left) +
               countNodes(root->right) + 1;
    }
};

Complexity

- Time Complexity: O(n) — visits every node once.
- Space Complexity: O(h) — recursive call stack, where h is the tree height. Worst case O(n).

Remember

"left count + right count + 1"

The "+1" counts the current root node.