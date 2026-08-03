class Solution {
public:
    using vi=vector<int>;
    using pii=pair<int,int>;
    using node=pair<int,pair<int,int>>;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vi> dist(n,vi(m,INT_MAX));
        dist[0][0] = 0;
        priority_queue<node,vector<node>,greater<node>> q;
        q.push({0,{0,0}});
        while(!q.empty())
        {
            auto it = q.top();q.pop();
            int effort=it.first,r=it.second.first,c=it.second.second;
            if(r==n-1 and c==m-1) return effort;
            if(effort > dist[r][c]) continue;
            vector<pii> vp = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto &d:vp)
            {
                int nx=r+d.first,ny=c+d.second;
                if(nx>=0 and nx<n and ny>=0 and ny<m)
                {
                    int wt = abs(heights[r][c] - heights[nx][ny]);
                    int neweffort = max(effort,wt);
                    if(neweffort < dist[nx][ny])
                    {
                        dist[nx][ny] = neweffort;
                        q.push({neweffort,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};