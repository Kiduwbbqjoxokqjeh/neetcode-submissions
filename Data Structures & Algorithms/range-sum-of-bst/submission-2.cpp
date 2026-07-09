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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            auto x = q.front();q.pop();
            if(!x) continue;
            if(x->val >= low and x->val <= high) sum += x->val;
            if(x->val > low) q.push(x->left);
            if(x->val < high) q.push(x->right);
        }
        return sum;
    }
};