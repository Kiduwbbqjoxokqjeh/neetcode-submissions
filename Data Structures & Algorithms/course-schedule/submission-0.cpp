class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto &x:prerequisites)
        {
            int a = x[0],b=x[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i] == 0) q.push(i);
        }
        int count=0;
        while(!q.empty())
        {
            int node = q.front();q.pop();
            count++;
            for(auto &child:adj[node])
            {
                indeg[child]--;
                if(indeg[child]==0) q.push(child);
            }
        }
        return count==n;
    }
};
