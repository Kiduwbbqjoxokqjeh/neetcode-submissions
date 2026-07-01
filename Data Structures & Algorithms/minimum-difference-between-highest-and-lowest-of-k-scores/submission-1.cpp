class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=k-1,res = INT_MAX;
        while(r<n)
        {
            res = min(res,nums[r]-nums[l]);
            l++;
            r++;
        }
        return res;
    }
};