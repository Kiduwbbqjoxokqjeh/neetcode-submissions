class Solution {
public:
    using vi = vector<int>;
    vector<vi> ans;
    void func(vi &nums,vi &curr,int idx)
    {
        ans.push_back(curr);
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx and nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            func(nums,curr,i+1);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vi curr;
        func(nums,curr,0);
        return ans;
    }
};
