class Solution {
public:
    using vi=vector<int>;
    using pii=pair<int,int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii>> adj(n);
        for(auto &v:flights)
        {
            int from=v[0],to=v[1],cost=v[2];
            adj[from].push_back({to,cost});
        }
        queue<vi> q;
        q.push({0,src,0});
        vi dist(n,INT_MAX); dist[src] = 0;
        while(!q.empty())
        {
            auto v = q.front();q.pop();
            int stops=v[0],node=v[1],costsofar=v[2];
            if(stops > k)continue;
            for(auto &[next,wt]:adj[node])
            {
                int newcost = costsofar+wt;
                if(newcost < dist[next])
                {
                    dist[next]=newcost;
                    q.push({stops+1,next,newcost});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
