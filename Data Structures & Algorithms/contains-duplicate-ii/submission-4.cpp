class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int x = nums[i];
            if(mp.count(x))
            {
                int diff = abs(i-mp[x]);
                if(diff <= k) return true;
                else mp[x] = i;
            }
            else mp[x] = i;
        }
        return false;
    }
};