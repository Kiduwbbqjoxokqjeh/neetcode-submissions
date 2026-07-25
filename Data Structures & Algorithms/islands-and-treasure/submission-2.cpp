class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int inf = 2147483647;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        vector<pair<int,int>> vp = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            auto p = q.front();q.pop();
            int x=p.first,y=p.second;
            for(auto &d:vp)
            {
                int nx = x+d.first;
                int ny = y+d.second;
                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny] == inf)
                {
                    grid[nx][ny] = grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
};
