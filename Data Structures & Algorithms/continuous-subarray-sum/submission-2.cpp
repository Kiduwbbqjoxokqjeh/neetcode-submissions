class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }
        // 23 25 29 35 42
        if(prefix.size() == 2)
        {
            int x = prefix.back();
            if(x%k == 0) return true;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+2;j<n;j++)
            {
                int diff = prefix[j]-prefix[i];
                if(diff % k == 0) return true;
            }
        }
        return false;
    }
};