class Solution {
public:
    using vi=vector<int>;
    using vb=vector<bool>;
    int ans=0;
    void dfs(int node,vector<vi> adj,vb &vis)
    {
        vis[node]=true;
        for(auto &child:adj[node])
        {
            if(!vis[child]) dfs(child,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vi> adj(n);
        for(auto &x:edges)
        {
            int a=x[0],b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }    
        vb vis(n,false);
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
