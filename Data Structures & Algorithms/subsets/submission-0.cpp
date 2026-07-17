class Solution {
public:
    using vi = vector<int>;
    vector<vi> ans;
    void func(vi &nums,int i,vi &curr)
    {
        if(i==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        func(nums,i+1,curr);
        curr.push_back(nums[i]);
        func(nums,i+1,curr);
        curr.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vi curr;
        func(nums,0,curr);
        return ans;
    }
};
