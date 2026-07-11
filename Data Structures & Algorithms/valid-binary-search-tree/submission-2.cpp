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
    bool func(TreeNode *&root,int l,int h)
    {
        if(!root) return true;
        if(root->val <= l or root->val >= h) return false;
        bool x = func(root->left,l,root->val);
        bool y = func(root->right,root->val,h);
        return x and y;
    }
    bool isValidBST(TreeNode* root) {
        return func(root,INT_MIN,INT_MAX);
    }
};
