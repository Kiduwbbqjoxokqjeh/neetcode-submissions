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
    vector<string> func(TreeNode *&root)
    {
        if(!root) return {};
        if(!root->left and !root->right) return {to_string(root->val)};
        vector<string> left,right,res;
        left = func(root->left);
        right = func(root->right);
        for(auto &l:left) res.push_back(l+to_string(root->val));
        for(auto &r:right) res.push_back(r+to_string(root->val));
        return res;
    }
    int sumNumbers(TreeNode* root) {
        vector<string> ans=func(root);
        for(auto &elem:ans) reverse(elem.begin(),elem.end());
        int x=0;
        for(auto &elem:ans) x += stoi(elem);
        return x;
    }
};























