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
    vector<string> dfs(TreeNode *&root)
    {
        if(!root) return {};
        if(!root->left and !root->right) return {to_string(root->val)};
        vector<string> l = dfs(root->left);
        vector<string> r = dfs(root->right);
        vector<string> res;
        for(auto &elem:l) res.push_back(elem+to_string(root->val));
        for(auto &elem:r) res.push_back(elem+to_string(root->val));
        return res;
    }
    int sumNumbers(TreeNode* root) {
        vector<string> ans = dfs(root);
        for(auto &elem:ans)
        {
            reverse(elem.begin(),elem.end());
        }
        int x=0;
        for(auto &elem:ans) x += stoi(elem);
        return x;
    }
};



























