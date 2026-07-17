class Solution {
public:
    using vi = vector<int>;
    vector<vi>ans;
    void func(vi &nums,vi &curr,int k,int i)
    {
        if(curr.size()==k)
        {
            ans.push_back(curr);return;
        }
        if(i == nums.size()) return;
        func(nums,curr,k,i+1);
        curr.push_back(nums[i]);
        func(nums,curr,k,i+1);
        curr.pop_back();
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vi nums(n,1);
        for(int i=1;i<n;i++) nums[i] = nums[i-1]+1;
        vi curr;
        func(nums,curr,k,0);
        return ans;
    }
};