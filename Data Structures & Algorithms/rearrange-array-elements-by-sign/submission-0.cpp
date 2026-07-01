class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = nums.size();
        vector<int> a,b;
        for(auto &x:nums) 
        {
            if(x>0) a.push_back(x);
            else b.push_back(x);
        }
        // 3 1 2
        // -2 -5 -4
        vector<int> ans;
        for(int i=0;i<a.size();i++)
        {
            ans.push_back(a[i]);
            ans.push_back(b[i]);
        }
        return ans;

    }
};