class Solution {
public:
    int ans=0;
    void func(vector<int> &nums,int idx,int xr)
    {
        if(idx==nums.size())
        {
            ans += xr;
            return;
        }
        func(nums,idx+1,xr);
        func(nums,idx+1,xr^nums[idx]);
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        func(nums,0,0);
        return ans;
    }
};