class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2==1) return false;
        int target = total/2;
        int n=nums.size();
        vector<int> dp(target+1,false);
        dp[0] = true;
        for(auto &x:nums)
        {
            for(int j=target;j>=x;j--)
            {
                dp[j] = dp[j] || dp[j-x];
            }
        }
        return dp[target];
    }
};
