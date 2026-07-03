class Solution {
public:
    int func(vector<int> &nums,int goal)
    {
        if(goal < 0) return 0;
        int n = nums.size(),l=0,ans=0,sum=0;
        for(int r=0;r<n;r++)
        {
            sum += nums[r];
            while(sum > goal)
            {
                sum -= nums[l++];
            }
            ans += (r-l+1);
        }
        return ans;//
        //number of subarrays with sum <= goal
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // subarrays with sum <=2 - subarrays with sum <=1 = sub with sum=2
        return func(nums,goal) - func(nums,goal-1);
    }
};