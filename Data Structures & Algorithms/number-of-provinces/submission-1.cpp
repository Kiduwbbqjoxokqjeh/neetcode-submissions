class Solution {
public:
    int n;
    using vi=vector<int>;
    void dfs(int node,vector<vi> &graph,vector<bool> &vis)
    {
        vis[node] = true;
        for(int next=0;next<n;next++)
        {
            if(graph[node][next] == 1 and !vis[next]) dfs(next,graph,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> vis(n,false);
        int prov=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) 
            {
                prov++;
                dfs(i,isConnected,vis);
            }
        }
        return prov
        ;
    }
};