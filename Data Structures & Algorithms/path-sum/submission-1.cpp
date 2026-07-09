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
public: 
    bool func(TreeNode *&root,int k)
    {
        if(!root) return false;
        if(!root->left and !root->right) return k==root->val;
        bool x = func(root->left,k-root->val);
        bool y = func(root->right,k-root->val);
        return x or y;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return func(root,targetSum);
    }
};