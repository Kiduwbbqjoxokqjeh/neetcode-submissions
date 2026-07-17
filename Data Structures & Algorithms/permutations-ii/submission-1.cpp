class Solution {
public:
    using vi = vector<int>;
    set<vi> st;
    vector<vi> ans;
    void func(vi &nums,int idx)
    {
        if(idx==nums.size())
        {
            st.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            func(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        func(nums,0);
        ans = vector<vi>(st.begin(),st.end());
        return ans;
    }
};