class Solution {
public:
    using vi=vector<int>;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vi dp(n,1);
        vi parent(n,-1);
        int maxlen=1,last=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 and dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i] > maxlen)
            {
                maxlen=dp[i];
                last=i;
            }
        }   
        vi ans;
        while(last != -1)
        {
            ans.push_back(nums[last]);
            last=parent[last];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};





















