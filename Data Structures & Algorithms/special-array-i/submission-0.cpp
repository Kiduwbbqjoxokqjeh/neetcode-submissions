class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        

        for(int i=1;i<nums.size();i++)
        {
            int diff = abs(nums[i] - nums[i-1]);
            if(diff % 2 == 0) return false;
        }
        return true;
        
    }
};