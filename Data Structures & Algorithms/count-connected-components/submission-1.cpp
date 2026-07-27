class Solution {
public:
    using vi=vector<int>;
    int ans=0;
    using vb=vector<bool>;
    void dfs(vector<vi> &adj,int node,vb &vis)
    {
        vis[node]=true;
        for(auto &child:adj[node])
        {
            if(!vis[child]) dfs(adj,child,vis);
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
                dfs(adj,i,vis);
                ans++;
            }
        }
        return ans;
    }
};
