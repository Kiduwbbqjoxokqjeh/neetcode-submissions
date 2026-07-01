class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        const int MOD = 1e9+7;
        int res=0;
        int l=0,r=nums.size()-1;
        vector<int> power(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            power[i] = (power[i-1]*2LL) % MOD;
        }
        while(l<=r)
        {
            int sum = nums[l]+nums[r];
            if(sum <= target)
            {
                res = (res + power[r-l]) % MOD;
                l++;
            }
            else r--;
        }
        return res;
        
    }
};