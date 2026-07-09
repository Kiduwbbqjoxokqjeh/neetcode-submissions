/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    TreeNode *func(TreeNode *&root,TreeNode *&p,TreeNode *&q)
    {
        if(!root) return nullptr;
        if(root==p or root==q) return root;
        TreeNode *x,*y;
        x = func(root->left,p,q);
        y = func(root->right,p,q);
        if(x and y) return root;
        if(!x and !y) return nullptr;
        if(!x) return y;
        return x;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
    }
};