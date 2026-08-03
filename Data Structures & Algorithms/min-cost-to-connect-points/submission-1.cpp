class Solution {
public:
    using vi=vector<int>;
    using pii=pair<int,int>;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool> vis(n,false);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0});
        int conn = 0,ans=0;
        while(!pq.empty())
        {
            auto [costsofar,curr] = pq.top();pq.pop();
            if(vis[curr])continue;
            conn++;
            vis[curr]=true;
            ans += costsofar;
            for(int next=0;next<n;next++)
            {
                if(!vis[next])
                {
                    int cost = abs(points[curr][0] - points[next][0])+abs(
                        points[curr][1] - points[next][1]
                    );
                    pq.push({cost,next});
                }
            }
        }
        return ans;
    }
};














