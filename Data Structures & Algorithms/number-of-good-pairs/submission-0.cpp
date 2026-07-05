class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]++;
        }

        int ans=0;

        for(auto &[k,v] : mp)
        {
            if(v > 1)
            {
                ans += (v*(v-1)) / 2;
            }
        }
        return ans;
        
    }
};