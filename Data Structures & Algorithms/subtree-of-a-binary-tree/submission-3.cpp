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
    bool issame(TreeNode *&a,TreeNode *&b)
    {
        if(!a and !b) return true;
        if(!a or !b) return false;
        if(a->val != b->val) return false;
        bool x = issame(a->left,b->left);
        bool y = issame(a->right,b->right);
        return x and y;
    }
    bool func(TreeNode *&a,TreeNode *&b)
    {
        if(!a) return false;
        if(issame(a,b)) return true;
        bool x = func(a->left,b);
        bool y = func(a->right,b);
        return x or y;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return func(root,subRoot);
    }
};
