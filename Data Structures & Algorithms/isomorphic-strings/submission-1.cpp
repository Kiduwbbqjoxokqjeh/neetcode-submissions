class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,char> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] != t[i]) return false;
                else continue;
            }
            else
            {
                for(auto &[k,v]:mp)
                {
                    if(v == t[i]) return false;
                }
                mp[s[i]] = t[i];
            }

        }
        return true;
        
    }
};