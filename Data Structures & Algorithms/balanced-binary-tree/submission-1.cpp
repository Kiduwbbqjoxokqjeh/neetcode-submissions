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
    bool bal=true;
    int func(TreeNode *&root)
    {
        if(!root) return 0;
        int x = func(root->left);
        int y = func(root->right);
        if(abs(x-y) > 1) bal=false;
        return max(x,y)+1;
    }
    bool isBalanced(TreeNode* root) {
        func(root);
        return bal;
    }
};
