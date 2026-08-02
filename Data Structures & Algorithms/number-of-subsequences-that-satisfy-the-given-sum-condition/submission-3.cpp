class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();int ans=0;
        vector<int> power(n,1);
        const int MOD= 1e9+7;
        for(int i=1;i<n;i++) power[i] = (power[i-1]*2LL)%MOD;
        int l=0,r=n-1;
        while(l<=r)
        {
            int sum = nums[l]+nums[r];
            if(sum <= target)
            {
                ans = (ans + power[r-l])%MOD;
                l++;
            }
            else r--;
        }
        return ans;
    }
};