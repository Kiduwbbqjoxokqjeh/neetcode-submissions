class Solution {
public:
    string customSortString(string order, string s) {

        unordered_map<char,int> mp;
        for(auto x:s) mp[x]++;
        string ans = "";

        for(auto c:order)
        {
            while(mp[c] > 0)
            {
                ans.push_back(c); mp[c]--;
            }
        }
        for(auto &[k,v]:mp)
        {
            while(v>0)
            {
                ans.push_back(k);v--;
            }
        }
        return ans;
        
    }
};