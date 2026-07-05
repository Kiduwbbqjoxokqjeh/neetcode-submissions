class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        vector<int> prefix(nums.size(),0);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            int ls;
            if(i==0)
            {
                ls = 0;
            }
            else ls = prefix[i-1];
            int rs = prefix[nums.size() -1] - prefix[i];
            if(ls == rs) return i;
        }
        return -1;
        
    }
};