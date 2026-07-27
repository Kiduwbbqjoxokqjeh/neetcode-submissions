class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis)
    {
        vis[node]=true;
        for(auto &child:adj[node])
        {
            if(!vis[child]) dfs(child,adj,vis);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(auto &x:edges)
        {
            int a=x[0],b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0,adj,vis);
        for(auto x:vis)
        {
            if(x==false) return false;
        }
        return true;
    }
};
