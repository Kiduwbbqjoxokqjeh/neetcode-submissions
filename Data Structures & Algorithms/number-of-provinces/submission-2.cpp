class Solution {
public:
    int n;
    void dfs(int node,vector<vector<int>> &graph,vector<bool> &vis)
    {
        vis[node] = true;
        for(int next=0;next<n;next++)
        {
            if(graph[node][next] and !vis[next]) dfs(next,graph,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};