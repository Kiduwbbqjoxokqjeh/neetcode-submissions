class Solution {
public:
    int minOperations(vector<int>& nums) {

        int ans=0;
        unordered_map<int,int> mp;
        for(auto &x: nums) mp[x]++;

        for(auto &[k,v]:mp)
        {
            if(v == 1) return -1;
            ans += (v+2)/3;
        }
        return ans;
    }
};