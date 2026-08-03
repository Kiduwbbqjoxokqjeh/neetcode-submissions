class Solution {
public:
    using vi=vector<int>;
    using pii = pair<int,int>;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool> vis(n,false);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0});
        int connected=0;
        int ans=0;
        while(!pq.empty())
        {
            auto [costsofar,currnode] = pq.top();pq.pop();
            if(vis[currnode]) continue;
            vis[currnode] = true;
            ans += costsofar;
            connected++;
            for(int next=0;next<n;next++)
            {
                if(!vis[next])
                {
                    int cost = abs(points[currnode][0] - points[next][0])+
                               abs(points[currnode][1] - points[next][1]);
                    pq.push({cost,next});
                }
            }
        }
        return ans;
    }
};
