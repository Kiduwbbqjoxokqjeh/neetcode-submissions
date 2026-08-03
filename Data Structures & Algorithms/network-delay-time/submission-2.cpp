class Solution {
public:
    using vi=vector<int>;
    using pii=pair<int,int>;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n+1);
        for(auto &v:times)
        {
            int from=v[0],to=v[1],timetaken=v[2];
            adj[from].push_back({to,timetaken});
        }    
        vi time(n+1,INT_MAX);
        time[k]=0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto it=pq.top();pq.pop();
            int timesofar=it.first,node=it.second;
            if(timesofar > time[node]) continue;
            for(auto &[next,t]:adj[node])
            {
                int totaltime = timesofar + t;
                if(totaltime < time[next]) 
                {
                    time[next]=totaltime;
                    pq.push({totaltime,next});
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

















