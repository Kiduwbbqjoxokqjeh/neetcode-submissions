class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l=0,r=k-1,res = INT_MAX;
        while(r<n)
        {
            res = min(res,nums[r]-nums[l]);
            l++;r++;
        }
        return res;
    }
};