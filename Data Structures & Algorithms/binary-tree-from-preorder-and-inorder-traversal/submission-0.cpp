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
    int idx=0;
    unordered_map<int,int> mp;
    TreeNode *func(vector<int> &inorder,vector<int> &preorder,int l,int r)
    {
        if(l>r) return nullptr;
        TreeNode *root = new TreeNode(preorder[idx++]);
        int i = mp[root->val];
        root->left = func(inorder,preorder,l,i-1);
        root->right = func(inorder,preorder,i+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        return func(inorder,preorder,0,n-1);
    }
};










