class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt=1;
        const int MARK = 100001;
        int val=nums[0];
        int i=1;
        while(i<n)
        {
            if(nums[i] == val)
            {
                cnt++;
                if(cnt > 2)
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
        for(int i=0;i<n;i++)
        {
            if(nums[i] != MARK)
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};