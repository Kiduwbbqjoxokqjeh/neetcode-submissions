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
    int preidx=0;
    unordered_map<int,int> mp;
    TreeNode *func(vector<int> &preorder,vector<int> &postorder,int l,int r)
    {
        if(l>r) return nullptr;
        TreeNode *root = new TreeNode(preorder[preidx++]);
        int idx = mp[root->val];
        root->left = func(preorder,postorder,l,idx-1);
        root->right = func(preorder,postorder,idx+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        return func(preorder,inorder,0,n-1);
    }
};

















