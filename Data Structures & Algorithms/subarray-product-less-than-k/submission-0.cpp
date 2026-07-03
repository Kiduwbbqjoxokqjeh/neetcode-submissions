class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0 or k == 1) return 0;
        int n = nums.size();
        int ans=0,count=1;
        int l=0;
        for(int r=0;r<n;r++)
        {
            count *= nums[r];
            while(count >= k)
            {
                count /= nums[l];
                l++;
            }
            ans += (r-l+1);
        }
        return ans;
    }
};