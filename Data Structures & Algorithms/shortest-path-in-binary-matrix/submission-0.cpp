class Solution {
public:
    using pii = pair<int,int>;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 or grid[n-1][n-1]==1) return -1;
        queue<pair<pii,int>> q;
        vector<pair<int,int>> vp = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        q.push({{0,0},1}); grid[0][0] = 1;
        while(!q.empty())
        {
            auto p = q.front();q.pop();
            int x = p.first.first,y = p.first.second;
            int dist = p.second;
            if(x==n-1 and y==n-1) return dist;
            for(auto &d:vp)
            {
                int nx = x+d.first,ny = y+d.second;
                if(nx>=0 and nx< n and ny>=0 and ny<n and grid[nx][ny] == 0)
                {
                    grid[nx][ny] = 1;
                    q.push({{nx,ny},dist+1});
                }
            }
        }
        return -1;
    }
};