class Solution {
public:
    using vi = vector<int>;
    bool func(vi &nums,vi &bucket,int tar,int idx)
    {
        if(idx == nums.size()) return true;
        for(int i=0;i<bucket.size();i++)
        {
            if(bucket[i] + nums[idx] <= tar)
            {
                bucket[i] += nums[idx];
                if(func(nums,bucket,tar,idx+1)) return true;
                bucket[i] -= nums[idx];
            }
            if(bucket[i] == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total % k != 0) return false;   
        int tar = total/k; 
        vi bucket(k,0);
        return func(nums,bucket,tar,0);
    }
};