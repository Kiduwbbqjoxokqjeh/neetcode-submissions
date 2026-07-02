class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l=0,ans=0;
        int cs=0;
        for(int r=0;r<n;r++)
        {
            cs += nums[r];
            int target = nums[r]*(r-l+1);
            while(target-cs > k)
            {
                cs -= nums[l];
                l++;
                target = nums[r]*(r-l+1);
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};