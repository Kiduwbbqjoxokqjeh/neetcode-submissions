class Solution {
public:
    using vi = vector<int>;
    vector<vi> ans;
    void perm(vi &nums,int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            perm(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,0);
        return ans;
    }
};
