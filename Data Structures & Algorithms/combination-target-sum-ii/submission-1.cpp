class Solution {
public:
    using vi = vector<int>;
    vector<vi> ans;
    void func(vi &cand,vi &curr,int tar,int sum,int i)
    {
        if(sum==tar)
        {
            ans.push_back(curr);return;
        }
        if(sum>tar) return;
        for(int j=i;j<cand.size();j++)
        {
            if(j>i and cand[j] == cand[j-1]) continue;
            curr.push_back(cand[j]);
            func(cand,curr,tar,sum+cand[j],j+1);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vi curr;
        sort(candidates.begin(),candidates.end());
        func(candidates,curr,target,0,0);
        return ans;
    }
};
