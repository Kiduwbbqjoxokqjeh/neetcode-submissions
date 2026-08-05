class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> dpmax(n),dpmin(n);
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            dpmax[i] = max({nums[i],nums[i]*dpmax[i-1],nums[i]*dpmin[i-1]});
            dpmin[i] = min({nums[i],nums[i]*dpmax[i-1],nums[i]*dpmin[i-1]});
            ans=max(ans,dpmax[i]);
        }
        return ans;
    }
};
