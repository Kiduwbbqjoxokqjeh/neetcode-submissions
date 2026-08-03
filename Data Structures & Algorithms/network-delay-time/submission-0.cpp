class Solution {
public:
    using vi=vector<int>;
    using pii=pair<int,int>;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n+1);
        for(auto &e:times)
        {
            int u=e[0],v=e[1],timetaken=e[2];
            adj[u].push_back({v,timetaken});
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k});
        vi time(n+1,INT_MAX);
        time[k] = 0;
        while(!pq.empty())
        {
            auto [currtime,currnode] = pq.top();pq.pop();
            if(currtime > time[currnode]) continue;
            for(auto &[node,nodetime]:adj[currnode])
            {
                int totaltime = nodetime+currtime;
                if(totaltime < time[node])
                {
                    time[node]=totaltime;
                    pq.push({totaltime,node});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(time[i] == INT_MAX) return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};  













