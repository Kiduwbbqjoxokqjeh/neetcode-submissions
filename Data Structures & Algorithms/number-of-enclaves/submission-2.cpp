class Solution {
public:
    int n,m;
    using vi = vector<int>;
    void dfs(int i,int j,vector<vi> &grid)
    {
        grid[i][j] = 0;
        vector<pair<int,int>> vp = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &d:vp)
        {
            int nx = i+d.first,ny=j+d.second;
            if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny] == 1) dfs(nx,ny,grid);
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1) dfs(i,0,grid);
            if(grid[i][m-1] == 1) dfs(i,m-1,grid);
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j] == 1) dfs(0,j,grid);
            if(grid[n-1][j] == 1) dfs(n-1,j,grid);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};