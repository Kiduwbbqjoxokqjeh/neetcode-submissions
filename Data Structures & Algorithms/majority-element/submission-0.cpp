class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int freq=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1] == nums[i])
            {
                freq++;
            }
            else 
            {
                if(freq > n/2) return nums[i-1];
                freq=1;
            }

        }
        if(freq > n/2) return nums[n-1];
        return -1;
        
    }
};