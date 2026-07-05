class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        for(auto x:nums) mp[x]++;
        set<pair<int,int>> st;
        for(auto &[key,val]:mp)
        {
            st.insert(make_pair(val,key));
        }
        vector<int> ans;
        auto it = st.rbegin();
        for(int i=0;i<k and it!=st.rend();i++, it++)
        {
            ans.push_back(it->second);
        }
        return ans;
        
    }
};
