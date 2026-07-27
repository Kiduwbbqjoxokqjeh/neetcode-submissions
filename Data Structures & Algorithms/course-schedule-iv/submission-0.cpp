class Solution {
public:
    using vb=vector<bool>;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vb> reach(n,vb(n,false));
        for(auto &x:prerequisites)
        {
            int a = x[0],b=x[1];
            reach[a][b] = true;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(reach[i][k] and reach[k][j]) reach[i][j] = true;
                }
            }
        }
        vb ans;
        for(auto &x:queries)
        {
            int a=x[0],b=x[1];
            ans.push_back(reach[a][b]);
        }
        return ans;
    }
};