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
    int sum=0;
    int func(TreeNode *&root,int l,int h)
    {
        if(!root) return 0;
        if(root->val >= l and root->val <=h) sum+=root->val;
        int x = func(root->left,l,h);
        int y = func(root->right,l,h);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return func(root,low,high);
    }
};