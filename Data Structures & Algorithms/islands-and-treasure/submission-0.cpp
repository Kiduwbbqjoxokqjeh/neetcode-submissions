class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf = 2147483647;
        queue<pair<int,int>> q;
        int n=grid.size(),m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            auto [x,y] = q.front();q.pop();
            for(auto d:dir)
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
