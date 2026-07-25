class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>> &heights,vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        vector<pair<int,int>> vp = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &d:vp)
        {
            int nx = i+d.first,ny = j+d.second;
            if(nx>=0 and nx<n and ny>=0 and ny<m and !vis[nx][ny] and 
            heights[nx][ny] >= heights[i][j])
            {
                dfs(nx,ny,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();m = heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false)),atl;
        atl = pac;
        for(int i=0;i<m;i++)
        {
            if(!pac[0][i])
            {
                dfs(0,i,heights,pac);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!pac[i][0]) dfs(i,0,heights,pac);
        }
        for(int j=0;j<m;j++)
        {
            if(!atl[n-1][j]) dfs(n-1,j,heights,atl);
        }
        for(int j=0;j<n;j++)
        {
            if(!atl[j][m-1]) dfs(j,m-1,heights,atl);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] and atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};









































