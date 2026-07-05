class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int,int> mp;
        for(auto x:arr)
        {
            mp[x]++;
        }
        int maxe = -1;
        for(auto &[k,v] : mp)
        {
            if(k == v) maxe = max(maxe,v);
        }
        return maxe;
        
    }
};