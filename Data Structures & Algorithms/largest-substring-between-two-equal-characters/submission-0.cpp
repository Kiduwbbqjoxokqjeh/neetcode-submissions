class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        int ans=-1;
        unordered_map<char,vector<int>> mp;

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].push_back(i);
        }

        for(auto &[k,v]: mp)
        {
            int temp=-1;
            int n = v.size();
            if(n > 1)
            {
                temp += (v[n-1] - v[0]);
            }
            ans = max(ans,temp);
        }
        return ans;
        
    }
};