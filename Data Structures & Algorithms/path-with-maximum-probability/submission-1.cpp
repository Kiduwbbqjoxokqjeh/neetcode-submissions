class Solution {
public:
    using pid=pair<int,double>;
    using pdi=pair<double,int>;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pdi> pq;
        vector<vector<pid>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0],b=edges[i][1];
            double prob=succProb[i];
            adj[a].push_back({b,prob});
            adj[b].push_back({a,prob});
        }
        vector<double> best(n,0); best[start_node]=1;
        vector<bool> vis(n,false);
        pq.push({1.0,start_node});
        while(!pq.empty())
        {
            auto [prob,curr] = pq.top();pq.pop();
            if(vis[curr]) continue;
            vis[curr]=true;
            if(curr==end_node) return prob;
            for(auto &[next,p]:adj[curr])
            {
                if(!vis[next])
                {
                    double newprob = p*prob;
                    if(newprob > best[next])
                    {
                        best[next]=newprob;
                        pq.push({newprob,next});
                    }
                }
            }
        }
        return 0;
    }
};













