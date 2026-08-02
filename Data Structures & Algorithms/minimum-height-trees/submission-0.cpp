class Solution {
public:
    using vi = vector<int>;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vi> adj(n);
        vi degree(n,0);
        for(auto &e:edges)
        {
            int a=e[0],b=e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(degree[i] == 1) q.push(i);
        }
        int rem = n;
        while(rem>2)
        {
            int sz = q.size();
            rem = rem-sz;
            while(sz--)
            {
                int node=q.front();q.pop();
                for(auto &next:adj[node])
                {
                    degree[next]--;
                    if(degree[next]==1) q.push(next);
                }
            }
        }
        vi ans;
        while(!q.empty()) 
        {
            ans.push_back(q.front());q.pop();
        }
        return ans;
    }
};






















