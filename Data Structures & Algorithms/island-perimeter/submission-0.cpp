class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p=0;
        int n = grid.size(),m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    p += 4;
                    if(i>0 and grid[i-1][j] == 1) p -= 2;
                    if(j>0 and grid[i][j-1] == 1) p -= 2;
                }
            }
        }
        return p;
    }
};