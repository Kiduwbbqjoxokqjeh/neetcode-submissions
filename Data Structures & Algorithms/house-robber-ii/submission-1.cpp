class Solution {
public:
    int solve(int l,int r,vector<int> &nums)
    {
        if(l==r) return nums[l];
        vector<int> dp(r-l+1,0);
        dp[0] = nums[l];
        dp[1] = max(nums[l],nums[l+1]);
        for(int i=2;i<dp.size();i++)
        {
            dp[i] = max(dp[i-1],nums[l+i]+dp[i-2]);
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(solve(0,n-2,nums),solve(1,n-1,nums));
    }
};
