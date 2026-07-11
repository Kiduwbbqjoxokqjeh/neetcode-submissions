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
    vector<vector<int>> ans;
    void func(TreeNode *&root)
    {
        vector<int> x; bool flag=false;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty())
        {
            int n=q.size();x.clear();
            for(int i=0;i<n;i++)
            {
                auto node=q.front();q.pop();
                x.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag==false)
            {
                ans.push_back(x); flag=true;
            }
            else 
            {
                reverse(x.begin(),x.end());
                ans.push_back(x); flag=false;
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return ans;
        func(root);
        return ans;
    }
};