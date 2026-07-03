class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,ans=0,sum=0;
        for(int r=0;r<n;r++)
        {
            sum += nums[r];
            while((r-l+1)-sum > k)
            {
                if(nums[l] == 1)sum--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};