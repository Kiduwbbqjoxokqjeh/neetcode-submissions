class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> power(n,1);
        sort(nums.begin(),nums.end());
        const int MOD = 1e9+7;
        for(int i=1;i<n;i++) power[i] = (power[i-1]*2LL)%MOD;
        
        int l=0,r=n-1;
        int res=0;
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