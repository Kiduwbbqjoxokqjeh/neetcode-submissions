

class Solution {
public:
    void solve(Node *&root,vector<int> &ans)
    {
        if(root)
        {
            for(auto child:root->children)
            {
                solve(child,ans);
            }
            ans.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};