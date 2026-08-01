class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int MARK = 100000;
        int n=nums.size(),cnt=0,i=0,val=nums[0];
        while(i<n)
        {
            if(nums[i] == val)
            {
                cnt++;
                if(cnt>2)
                {
                    nums[i] = MARK;
                }
            }
            else
            {
                val = nums[i];
                cnt=1;
            }
            i++;
        }
        int k=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j] != MARK) swap(nums[k++],nums[j]);
        }
        return k;
    }
};















