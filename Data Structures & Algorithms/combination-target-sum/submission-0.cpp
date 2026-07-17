class Solution {
public:
    using vi = vector<int>;
    vector<vi> ans;
    void func(vi &nums,vi &curr,int sum,int tar,int i)
    {
        if(sum==tar)
        {
            ans.push_back(curr); return;
        }
        if(i==nums.size() or sum>tar) return;
        func(nums,curr,sum,tar,i+1);
        curr.push_back(nums[i]);
        func(nums,curr,sum+nums[i],tar,i);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vi curr;
        func(nums,curr,0,target,0);
        return ans;
    }
};
