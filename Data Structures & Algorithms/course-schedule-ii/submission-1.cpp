class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n); vector<int> indeg(n,0);
        for(auto &x:prerequisites)
        {
            int a=x[0],b=x[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();q.pop();
            ans.push_back(node);
            for(auto &child:adj[node])
            {
                indeg[child]--;
                if(indeg[child] == 0) q.push(child);
            }
        }
        if(n==ans.size()) return ans;
        return {};
    }
};
