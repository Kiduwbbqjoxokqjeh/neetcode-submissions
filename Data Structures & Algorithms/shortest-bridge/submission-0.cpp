class Solution {
public:
    using vb=vector<bool>;
    using vi=vector<int>;
    int n;
    void dfs(vector<vi> &grid,int i,int j,vector<vb> &vis,queue<pair<int,int>> &q)
    {
        vector<pair<int,int>> vp = {{1,0},{-1,0},{0,1},{0,-1}};
        vis[i][j] = true;
        q.push({i,j});
        for(auto &d:vp)
        {
            int nx = i+d.first,ny = j+d.second;
            if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny] == 1 and !vis[nx][ny])
            {
                dfs(grid,nx,ny,vis,q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        bool found=false;
        for(int i=0;i<n and !found;i++)
        {
            for(int j=0;j<n and !found;j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,vis,q);
                    found=true;
                }
            }
        }
        int ans=0;
        vector<pair<int,int>> vp = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int r=q.front().first,c = q.front().second; q.pop();
                for(auto &d:vp)
                {
                    int nx = r+d.first,ny = c+d.second;
                    if(nx>=0 and nx<n and ny>=0 and ny<n and !vis[nx][ny])
                    {
                        if(grid[nx][ny] == 1) return ans;
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


















