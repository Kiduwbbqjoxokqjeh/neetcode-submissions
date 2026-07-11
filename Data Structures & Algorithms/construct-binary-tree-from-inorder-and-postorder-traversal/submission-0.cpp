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
    int postidx;
    unordered_map<int,int> mp;
    TreeNode *func(vector<int> &inorder,vector<int> &postorder,int l,int r)
    {
        if(l > r) return nullptr;
        TreeNode *root = new TreeNode(postorder[postidx--]);
        int idx = mp[root->val];
        root->right = func(inorder,postorder,idx+1,r);
        root->left = func(inorder,postorder,l,idx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postidx=postorder.size()-1;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        return func(inorder,postorder,0,n-1);
    }
};












