class Solution {
public:
    using vi = vector<int>;
    vector<vi> ans;
    void func(vi &nums,vi &curr,int tar,int sum,int i)
    {
        if(sum==tar)
        {
            ans.push_back(curr); return;
        }
        if(sum>tar or i==nums.size()) return;

        func(nums,curr,tar,sum,i+1);
        curr.push_back(nums[i]);
        func(nums,curr,tar,sum+nums[i],i);
        curr.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vi curr;
        func(nums,curr,target,0,0);
        return ans;
    }
};
