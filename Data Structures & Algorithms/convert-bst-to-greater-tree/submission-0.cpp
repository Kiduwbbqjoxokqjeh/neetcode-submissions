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
    vector<pair<int,TreeNode*>> vp;
    void trav(TreeNode *&root)
    {
        if(!root) return;
        trav(root->left);
        vp.push_back({root->val,root});
        trav(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        trav(root);
        reverse(vp.begin(),vp.end());
        int ans = vp[0].first;
        for(int i=1;i<vp.size();i++)
        {
            auto &[k,v] = vp[i];
            ans += k;
            v->val=  ans;

        }
        return root;

    }
};






























