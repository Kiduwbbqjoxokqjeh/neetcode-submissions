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
    TreeNode *func(TreeNode *&root,TreeNode *&p,TreeNode *&q)
    {
        if(!root) return nullptr;
        if(root->val == p->val or root->val==q->val) return root;
        TreeNode *x = func(root->left,p,q);
        TreeNode *y = func(root->right,p,q);
        if(x and y) return root;
        if(!x and !y) return nullptr;
        if(!x) return y;
        return x;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
    }
};
