/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public://tc and sc both O(n);
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;//fifo
        q.push(root);

        while(!q.empty()){
            int len=q.size();
            vector<int> cur_lvl;//used to store one lvl in one vector 
            for(int i=0;i<len;i++)
            { 
                TreeNode* curr=q.front();
                q.pop();
                cur_lvl.push_back(curr->val);//adds the root and then its child to back in the queue.for ex: 1 3 is added and when dequeued form queue its childs are added to the end of queue and then when left child is dequeued first then right one when left is dequeued then its child are added at the end of queue and same with right till we get all nullptrs .

                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
            }
        ans.push_back(cur_lvl);
        }
    return ans;      
    }
};