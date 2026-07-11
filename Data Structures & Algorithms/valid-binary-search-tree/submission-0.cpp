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
    bool func(TreeNode *&root,int low,int high)
    {
        if(!root) return true;
        if(root->val <= low or root->val >= high) return false;

        bool x = func(root->left,low,root->val);
        bool y = func(root->right,root->val,high);

        return x and y;
    }
    bool isValidBST(TreeNode* root) {
        return func(root,INT_MIN,INT_MAX);
    }
};
