class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int ms = nums[0];
        int cs = ms;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1]) cs += nums[i];
            else cs = nums[i];
            ms = max(ms,cs);
        }
        return ms;
        
    }
};