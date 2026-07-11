class Solution {
public:
    int dfs(int node,int parent,vector<vector<int>> &adj,vector<bool> &apple)
    {
        int time=0;
        for(auto &child:adj[node])
        {
            if(child==parent) continue;
            int childtime = dfs(child,node,adj,apple);
            if(childtime > 0 or apple[child]) time += childtime + 2;
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};