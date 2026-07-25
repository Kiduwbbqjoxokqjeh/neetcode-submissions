class Solution {
public:
    void dfs(vector<vector<int>> &image,int i,int j,int oc,int nc)
    {
        int m = image.size(),n = image[0].size();
        if(i<0 or i>=m or j<0 or j>=n) return;
        if(image[i][j] != oc) return;
        image[i][j] = nc;
        dfs(image,i,j+1,oc,nc);
        dfs(image,i,j-1,oc,nc);
        dfs(image,i-1,j,oc,nc);
        dfs(image,i+1,j,oc,nc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc];
        if(oc == color) return image;
        dfs(image,sr,sc,oc,color);
        return image;
    }
};