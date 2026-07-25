class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        vector<pair<int,int>> vp = {{1,0},{-1,0},{0,1},{0,-1}};
        int time=0;
        while(!q.empty() and fresh>0)
        {
            int sz=  q.size();
            while(sz--)
            {
                auto p = q.front();q.pop();
                int x=p.first,y=p.second;
                for(auto &d:vp)
                {
                    int nx = x+d.first,ny = y+d.second;
                    if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        if(fresh>0) return -1;
        return time;
    }
};
