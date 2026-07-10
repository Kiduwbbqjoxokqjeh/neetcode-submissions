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
    TreeNode *findmin(TreeNode *x)
    {
        while(x->left) x=x->left;
        return x;
    }
    TreeNode *func(TreeNode *&root,int key)
    {
        if(!root) return nullptr;
        if(key < root->val) root->left=func(root->left,key);
        else if(key>root->val) root->right=func(root->right,key);
        else
        {
            if(!root->left)
            {
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            if(!root->right)
            {
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            TreeNode *succ = findmin(root->right);
            root->val=succ->val;
            root->right=func(root->right,succ->val); 
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return func(root,key);
    }
};