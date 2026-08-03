class Solution {
public:
    using vi=vector<int>;
    using pii=pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n+1);
        for(auto &v:times)
        {
            int a=v[0],b=v[1],timetakes=v[2];
            adj[a].push_back({b,timetakes});
        }
        vector<int> time(n+1,INT_MAX); time[k]=0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            int timesofar=pq.top().first,node=pq.top().second;pq.pop();
            if(timesofar > time[node])continue;
            for(auto &[next,t]:adj[node])
            {
                int totaltime = timesofar+t;
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
            ans=max(time[i],ans);
        }
        return ans;
    }
};

















