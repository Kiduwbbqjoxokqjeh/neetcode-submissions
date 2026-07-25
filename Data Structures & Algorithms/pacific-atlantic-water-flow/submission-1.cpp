class Solution {
public:
    int n ,m;
    using vb = vector<bool>;
    using vi = vector<int>;
    void dfs(int i,int j,vector<vi> &heights,vector<vb> &vis)
    {
        vis[i][j] = true;
        vector<vi> v = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &d:v)
        {
            int nx = i+d[0],ny = j+d[1];
            if(nx>=0 and nx<n and ny>=0 and ny<m and !vis[nx][ny] and heights[nx][ny] >= heights[i][j])
            {
                dfs(nx,ny,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(),m = heights[0].size();
        vector<vb> pac(n,vb(m,false)),atl;
        atl = pac;
        for(int i=0;i<m;i++)
        {
            if(!pac[0][i]) dfs(0,i,heights,pac);
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
        vector<vi> ans;
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









































