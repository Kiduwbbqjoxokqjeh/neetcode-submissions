class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n+1,0),outdeg(n+1,0);
        for(auto &p:trust)
        {
            int x = p[0],y = p[1];
            outdeg[x]++;
            indeg[y]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(indeg[i] == n-1 and outdeg[i] == 0) return i;
        }
        return -1;
    }
};