class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0;i<n;i++)
        {
            int rem = prefix[i]%k;
            if(mp.count(rem))
            {
                if(i - mp[rem] >= 2) return true;
            }
            else mp[rem] = i;
        }
        return false;
    }
};