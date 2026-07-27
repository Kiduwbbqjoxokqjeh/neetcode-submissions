class Solution {
public:
    int ans=0;
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis)
    {
        vis[node]=true;
        for(auto &child:adj[node])
        {
            if(!vis[child]) dfs(child,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(auto &x:edges)
        {
            int a=x[0],b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
