class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid[0].size();
        vector<int> check(n*n,0);
        vector<int> ans;
        for(auto x: grid)
        {
            for(auto y: x)
            {
                check[y-1]++;
            }
        }
        auto it1 = find(check.begin(),check.end(),2);
        int idx1 = it1-check.begin();
        auto it2 = find(check.begin(),check.end(),0);
        int idx2 = it2-check.begin();
        return {idx1+1,idx2+1};
        
    }
};