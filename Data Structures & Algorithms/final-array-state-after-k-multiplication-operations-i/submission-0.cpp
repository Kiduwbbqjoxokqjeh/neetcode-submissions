class Solution {
public:
    using pii = pair<int,int>;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pii,vector<pii>,greater<pii>> q;
        for(int i=0;i<nums.size();i++)
        {
            q.push({nums[i],i});
        }
        while(!q.empty() and k--)
        {
            auto x = q.top();q.pop();
            x.first = x.first * multiplier;
            q.push(x);
        }
        vector<int> ans(nums.size(),0);
        while(!q.empty())
        {
            auto x = q.top();q.pop();
            ans[x.second] = x.first;
        }
        return ans;
    }
};