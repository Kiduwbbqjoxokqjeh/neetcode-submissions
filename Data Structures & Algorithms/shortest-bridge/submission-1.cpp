class Solution {
public:
    using vi = vector<int>;
    using pi = pair<int,int>;
    using vb = vector<bool>;
    int n;
    vector<pi> vp = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vi> &grid,int i,int j,vector<vb> &vis,queue<pi> &q)
    {
        vis[i][j]=true;
        q.push({i,j});
        for(auto &d:vp)
        {
            int nx= i+d.first,ny=j+d.second;
            if(nx>=0 and nx<n and ny>=0 and ny<n and !vis[nx][ny] and grid[nx][ny]==1)
            {
                dfs(grid,nx,ny,vis,q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vb> vis(n,vb(n,false));
        bool found=false;
        queue<pi> q; // first islands
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!found)
                {
                    if(grid[i][j] == 1)
                    {
                        dfs(grid,i,j,vis,q);
                        found=true;
                    }
                }
                if(found)break;
            }
            if(found)break;
        }
        int ans=0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int r=q.front().first,c=q.front().second;q.pop();
                for(auto &d:vp)
                {
                    int nx=r+d.first,ny=c+d.second;
                    if(nx>=0 and nx<n and ny>=0 and ny<n and !vis[nx][ny])
                    {
                        if(grid[nx][ny]==1) return ans;
                        else
                        {
                            vis[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};